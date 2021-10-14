// File: Div.asm
// Author: Joseph Shumway
// Date: 10/13/2021
// Section: 504
// E-mail: joseph.shumway@tamu.edu 
// Description:
// e.g. The content of this file implements division in the hack assembly language

@R0
D=M

@END
D;JEQ





(LOOP1)
    // get dividend value and give to D register
    @R0
    D=M

    // D = dividend - divisor
    @R1
    D=D-M

    // check divisor less than dividend. Jump to END if so.
    @END
    D;JGE

    // now reset values and do division
    // grab dividend
    @R0
    D=M

    // get divisor and subtract from dividend. Set new dividend
    @R1
    D=D-M
    @R0
    M=D

    // increase count
    @R2
    M=M+1

    @LOOP1
    0;JMP

(END)

    // get count
    @count
    D=M

    // set R2 to value in count
    @R2
    M=D

    @END
    0;JMP