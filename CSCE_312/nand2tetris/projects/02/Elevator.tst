load Elevator.hdl,
output-file Elevator.out,
compare-to Elevator.cmp,
output-list c%B1.2.1 r%B1.2.1 next%B1.2.1;

set c %B01,
set r %B01,
eval,
output;

set c %B10,
set r %B01,
eval,
output;

set c %B00,
set r %B10,
eval,
output;