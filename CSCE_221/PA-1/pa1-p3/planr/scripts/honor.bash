#!/usr/bin/env bash

set -e -o pipefail

print_sources_prompt() {
cat <<_EOF

Please list all external sources you used during the assignment 
(Does not include TAs, PTs, or course materials.) If you fail to
cite sources you can get a lower number of points or even zero, 
read more in the Aggie Honor System Office http://aggiehonor.tamu.edu/

Enter each source on one line (leave line blank to stop):
_EOF
}

get_sources() {
  local sources
  local num

  sources=""
  num=0

  local source
  while [ -n "${source}" ] || [ $num -eq 0 ]; do
    num=$((num + 1))
    read -p "${num}. " source
    if [ -n "${source}" ]; then
      sources="${sources}${num}. ${source}\n"
    fi
  done

  echo -e "${sources}"
}

is_yes() {
  if [ "y" = "$1" ] || [ "Y" = "$1" ] || [ "yes" = "$1" ]; then
    return 0;
  elif [ "n" = "$1" ] || [ "N" = "$1" ] || [ "no" = "$1" ]; then
    return 1;
  fi

  return 2;
}

is_yes_no() {
  is_yes "$1"
  if [ $? -lt 2 ]; then
    return 0;
  fi

  return 1;
}

print_honor() {
cat <<_EOF
I certify that I have listed all the sources that I used to develop the 
solutions/code to the submitted work.

"On my honor as an Aggie, I have neither given nor received any unauthorized 
help on this academic work."

_EOF
}

read_non_blank() {
  local ans
  read -p "${1}" ans

  if [[ -n "${ans}" ]]; then
    echo "${ans}"
  else
    read_non_blank "${1}";
  fi
}

get_uin() {
  echo "$( read_non_blank 'UIN: ' )" 
}

get_email() {
  echo "$( read_non_blank 'TAMU Email: ' )"
}

get_signature() {
  echo "$( read_non_blank 'Your Name (signature): ')"
}

line() {
  echo "========================================"
}

honor_txt() {

  print_honor

cat <<_EOF

Sources:
--------
${SOURCES}

UIN: ${UIN}
Email: ${EMAIL}
Signature: ${SIGNATURE}
_EOF
}

honor_json() {
cat <<_EOF
{
  "uin": "${UIN}",
  "email": "${EMAIL}",
  "signature": "${SIGNATURE}"
}
_EOF
}

affirm_honor() {
  line
  cat "$1"
  line
  echo -n -e "\n"

  local is_correct
  while ! is_yes_no "${is_correct}"; do
    read -p 'Is the above information correct (y/n): ' is_correct
  done


  if is_yes "${is_correct}"; then
    return 0;
  fi

  return 1;
}

skip() {
  echo -n -e "\n\n\n\n\n\n\n\n"
}

request_honor() {
  print_sources_prompt

  SOURCES="$(get_sources)"

  echo ""

  print_honor

  UIN="$(get_uin)"
  EMAIL="$(get_email)"
  SIGNATURE="$(get_signature)"
}

generate_honor() {
  local honor_txt
  local honor_json
  honor_txt="$1"
  honor_json="$2"

  if [ -f "${honor_txt}" ] \
     && [ -f "${honor_json}" ]; then
    if affirm_honor "${honor_txt}"; then
      return 0;
    else
      skip
    fi
  fi

  while : ; do
    request_honor
    
    honor_txt > "${honor_txt}"
    honor_json > "${honor_json}"

    skip

    if affirm_honor "${honor_txt}"; then
      break;
    fi
  done
}
