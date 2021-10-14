load Elevator.hdl,
output-file Elevator.out,
compare-to Elevator.cmp,
output-list time%S2.3.1 d%D4.1.4 u%D4.1.4 n%B4.1.4 b%B4.1.4;

set u %D0,
set d %D0,
tick,
output,
tock,
output;

set u %D1,
set d %D0,
tick,
output,
tock,
output;

set u %D0,
set d %D1,
tick,
output,
tock,
output;

set u %D1,
set d %D1,
tick,
output,
tock,
output;

set u %D0,
set d %D1,
tick,
output,
tock,
output;

set u %D1,
set d %D0,
tick,
output,
tock,
output;

set u %D1,
set d %D0,
tick,
output,
tock,
output;

set u %D1,
set d %D1,
tick,
output,
tock,
output;

set u %D0,
set d %D0,
tick,
output,
tock,
output;