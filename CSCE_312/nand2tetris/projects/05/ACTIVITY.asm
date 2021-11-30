// -----------------------------
@16 // variable A = 1
M=1

@17 // variable B = 0
M=0

@16 // D = 1  (K)
D=M

@3  // D = 1 - 3
D=D-A

@18 //goto (LABEL 1) at RAM 18 if D (-2) is greater than 0 (false)
D;JGT

@16 // set D = 1
D=M

@17 // set B = 1 + 0
M=D+M

@16 // set A++ (2)
M=M+1

@4  // goto line 4 aka K
0;JMP

@18 // outside infinite loop
0;JMP



// a = 1              // a=1
// b = 0              // b=0

// (K)
// d = a              // d=1
// d = d - 3          // d=-2
// if (d > 0) goto J  // false, continue

// d = a              // d=1
// b = d + b          // b=1
// a = a + 1          // a=2
// (gotoK)          // repeat


// (J)
// while true: repeat
// (gotoJ)
