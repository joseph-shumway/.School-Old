// File: Problem_3.58.c
// Author: Joseph Shumway
// Date: 11/14/2021
// Section: 504
// E-mail: joseph.shumway@tamu.edu 
// Description:
// This file implements problem 3.58 in C from Assembly


// Original assembly code with comments
/*

decode2:
    subq %rdx, %rsi     // subtract z from y and store in y
    imulq %rsi, %rdi    // multiply x by y and store in x
    movq %rsi, %rax     // move y to value
    salq $63, %rax      // shift rax left by 63
    sarq $63, %rax      // shift rax right by 63
    xorq %rdi, %rax     // xor value and x
    ret                 // return

*/

long decode(long x, long y, long z) {
    y = y - z;
    x = y * x;
    long value = y;
    value << 63;
    value >> 63;
    value = value ^ x;

    return value;
}