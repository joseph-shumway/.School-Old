#!/usr/bin/env bash

set -e -o pipefail

CONFIG_DIR="$(planr config configdir)"
SRC_DIR="$(planr config srcdir)"
BUILD_DIR="$(planr config builddir)"

. "${CONFIG_DIR}/scripts/honor.bash"

HONOR_TXT="honor.txt"
HONOR_TXT_PATH="${BUILD_DIR}/${HONOR_TXT}"

HONOR_JSON="honor.json"
HONOR_JSON_PATH="${BUILD_DIR}/${HONOR_JSON}"

DELIVERABLE_PATH="deliverable.tgz"

if [ ! -d "${BUILD_DIR}" ]; then
  mkdir "${BUILD_DIR}";
fi

generate_honor "${HONOR_TXT_PATH}" "${HONOR_JSON_PATH}"

honor_exists_error() {
cat <<_EOF

The following files must not be present to generate the deliverable:
- ${HONOR_TXT}
- ${HONOR_JSON}

If these files contain valuable data, please save them to another directory.
Otherwise, delete them:
rm -rf ${HONOR_TXT} ${HONOR_JSON}
_EOF

exit 1
}

remove_tmp_honors() {
  rm -rf "${HONOR_TXT}" "${HONOR_JSON}"
}

if [ -e "${HONOR_TXT}" ] || [ -e "${HONOR_JSON}" ]; then
  honor_exists_error
fi

trap 'remove_tmp_honors' EXIT

cp "${HONOR_JSON_PATH}" "${HONOR_JSON}"
cp "${HONOR_TXT_PATH}" "${HONOR_TXT}"
tar -czf "${DELIVERABLE_PATH}" src "${HONOR_TXT}" "${HONOR_JSON}"

remove_tmp_honors

skip

echo "The following files were added to the deliverable:"
tar --list -f "${DELIVERABLE_PATH}" 
