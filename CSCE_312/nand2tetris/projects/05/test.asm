@20
D=A-1     // D = 19
AD=A+1    // A and D = 21

@19       // A = 19
D=A       // D = 19

@21       
AD=D+A    // A and D = 40

@5034   
M=D-1     // RAM[5034] = 39

@5034
A=M       // A = 39

@171
D=A       // D = 171

@53
M=D       // RAM[53] = 171

@10
D=A       // D = 10

@7
M=D       // RAM[7] = 10

@7
M=M+1     // RAM[7] = 11

@21
0;JMP     // infinite loop