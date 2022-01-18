// File: Div.asm
// Author: Joseph Shumway
// Date: 10/13/2021
// Section: 504
// E-mail: joseph.shumway@tamu.edu 
// Description:
// e.g. The content of this file implements division in the hack assembly language

@R0
D=M

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

    // check dividend less than divisor. Jump to END if so.
    @END
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