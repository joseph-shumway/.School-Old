// File: Fill.asm
// Author: Joseph Shumway
// Date: 10/14/2021
// Section: 504
// E-mail: joseph.shumway@tamu.edu 
// Description:
// e.g. The content of this file implements filling the screen in the hack assembly language

// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, the
// program clears the screen, i.e. writes "white" in every pixel.

// Put your code here.

// set screen size
@8191
D=A
@screensize
M=D

// set fill number
@65535
D=A
@full
M=D


(FILLMAIN)

    // if key pressed, fill
    @KBD
    D=M
    @DOFILL
    D;JNE

    // if no key pressed, empty
    @DOEMPTY
    D;JEQ

    @FILLMAIN
    0;JMP


(DOFILL)

    // set starting point for position on screen
    @position
    M=0

    (SETPIXELSFULL)
        
        // stop if on last row
        @screensize
        D=M-D
        @FILLMAIN
        D;JLE
        
        // grab position and set to D
        @position
        D=M

        // get screen and add offset of position
        @SCREEN
        A=A+D

        // set row to full
        M=-1

        // add 1 to position to get next row
        @position
        M=M+1

        @SETPIXELSFULL
        0;JMP

    @FILLMAIN
    0;JMP


(DOEMPTY)

    // set starting point for position on screen
    
    @position
    M=0
    (SETPIXELSEMPTY)
        
        // stop if on last row
        @screensize
        D=M-D
        @FILLMAIN
        D;JLE
        
        // grab position and set to D
        @position
        D=M

        // get screen and add offset of position
        @SCREEN
        A=A+D

        // set row to empty
        M=0

        // add 1 to position to get next row
        @position
        M=M+1

        @SETPIXELSEMPTY
        0;JMP



    @FILLMAIN
    0;JMP
