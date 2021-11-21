g++ sim1000.cpp -o sim1k
if ./sim1k > TotalRunSim1000.txt;then
  diff TotalRunSim1000.txt Solution1000.txt > diff.txt
  if [ -s diff.txt ];then
    echo diff.txt > OUTPUT
    echo false > OUTPUT
  else
    echo true > OUTPUT
  fi
else
  echo "Failed to Run" > OUTPUT
  echo false > OUTPUT
fi