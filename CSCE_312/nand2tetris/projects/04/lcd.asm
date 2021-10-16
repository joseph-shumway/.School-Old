// File: lcd.asm
// Author: Joseph Shumway
// Date: 10/14/2021
// Section: 504
// E-mail: joseph.shumway@tamu.edu 
// Description:
// e.g. The content of this file implements lcd in the hack assembly language

// USING MOD.ASM HERE IN ADDITION TO LCD CODE

// set remainder to -1 for later
@remainder
M=-1
    
@R0
D=M
// set A to R0
@A
M=D

@R1
D=M
// set B to R1
@B
M=D


(MAIN)
    // check if A=0
    @A
    D=M
    @LCDEQB
    D;JEQ

    // check if B=0
    @B
    D=M
    @LCDEQA
    D;JEQ

    // // if remainder exists from previous step, set B to remainder
    // @remainder
    // D=M
    // @SETRB
    // D;JGT

    // (BACKTOMAIN)




(DIVIDE)
    @A
    D=M
    // set dividend to R0
    @dividend
    M=D

    @B
    D=M
    // set divisor to R1
    @divisor
    M=D

    // set R2 to 0
    @R2
    M=0

    // check if dividend is 0 and end if so
    @A
    D=M

    @ENDZERO
    D;JEQ


    (LOOP1)
        // get dividend value and give to D register
        @A
        D=M

        // D = dividend - divisor
        @B
        D=D-M

        @quotient
        M=D

        // check dividend less than divisor. Jump to REMAINDER if so.
        @REMAINDER
        D;JLT

        // increase count
        @R2
        M=M+1

        // now reset values and do division
        // get divisor value and give to D register
        @B
        D=M

        // D = dividend - divisor
        @A
        M=M-D

        @LOOP1
        0;JMP


    (REMAINDER)

        // get last dividend value and give to D register
        @A
        D=M

        // remainder = new dividend
        @remainder
        M=D

        // set updated values to original values for dividend and divisor
        @dividend
        D=M
        @A
        M=D
        @divisor
        D=M
        @B
        M=D

        // set A to value of B
        @B
        D=M
        @A
        M=D

        @remainder
        D=M
        @B
        M=D

        // jump to next MAIN
        @MAIN
        0;JMP


    

    (ENDDIVIDE)

        // end
        @ENDDIVIDE
        0;JMP


    (ENDDIVIDEZERO)

        // set R2 to 0 first
        @R2
        M=0

        @ENDDIVIDEZERO
        0;JMP

(SETRB)

    @remainder
    D=M

    @B
    M=D
    @BACKTOMAIN
    0;JMP

(LCDEQB)
    @B
    D=M
    @R2
    M=D
    @LCDEQB
    0;JMP

(LCDEQA)
    @A
    D=M
    @R2
    M=D
    @LCDEQA
    0;JMP