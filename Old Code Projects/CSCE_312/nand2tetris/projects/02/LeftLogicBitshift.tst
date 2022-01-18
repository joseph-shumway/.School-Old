load LeftLogicBitshift.hdl,
output-file LeftLogicBitshift.out,
compare-to LeftLogicBitshift.cmp,
output-list x%B1.16.1 y%B1.16.1 out%B1.16.1;

set x %B0000000000000001,
set y %B0000000000000001,
eval,
output;

set x %B0000000000000010,
set y %B0000000000000001,
eval,
output;

set x %B0000000000000001,
set y %B00000000000000010,
eval,
output;