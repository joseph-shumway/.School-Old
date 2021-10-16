// File: mod.asm
// Author: Joseph Shumway
// Date: 10/14/2021
// Section: 504
// E-mail: joseph.shumway@tamu.edu 
// Description:
// e.g. The content of this file implements mod in the hack assembly language

//This asm computes the modular of two numbers
//Assuming R0 stores the number a and R1 stores the number n
//so in normal programming language, the goal is to compute RAM[R0]%RAM[R1]
//The result will be put to R2
//Assuming RAM[R1] is positive integer and RAM[R0] is non-negative integer

//See the mod.cmp,mod.tst file to understand the input and output structure

//Put your code here


// USING DIV.ASM HERE IN ADDITION TO MOD CODE

@R0
D=M
// set dividend to R0
@dividend
M=D

@R1
D=M
// set divisor to R1
@divisor
M=D

// set R2 to 0
@R2
M=0

// check if dividend is 0 and end if so
@R0
D=M




@ENDZERO
D;JEQ


(LOOP1)
    // get dividend value and give to D register
    @R0
    D=M

    // D = dividend - divisor
    @R1
    D=D-M

    // check dividend less than divisor. Jump to REMAINDER if so.
    @REMAINDER
    D;JLT

    // increase count
    @R2
    M=M+1

    // now reset values and do division
    // get divisor value and give to D register
    @R1
    D=M

    // D = dividend - divisor
    @R0
    M=M-D

    @LOOP1
    0;JMP


(REMAINDER)

    // get last dividend value and give to D register
    @R0
    D=M

    // remainder = new dividend
    @R2
    M=D

    // set updated values to original values for dividend and divisor
    @dividend
    D=M
    @R0
    M=D

    @divisor
    D=M
    @R1
    M=D

    // jump to end
    @END
    0;JMP


(END)

    // end
    @END
    0;JMP


(ENDZERO)

    // set R2 to 0 first
    @R2
    M=0

    @ENDZERO
    0;JMP
