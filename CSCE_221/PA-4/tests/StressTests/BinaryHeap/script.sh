g++ heap_sim10000.cpp -o hsim10k
if ./hsim10k;then
  diff RunSim10000.txt Solution10000.txt > diff.txt
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