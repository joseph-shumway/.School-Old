// File: Problem_3.63.c
// Author: Joseph Shumway
// Date: 11/14/2021
// Section: 504
// E-mail: joseph.shumway@tamu.edu 
// Description:
// This file implements problem 3.63 in C from Assembly

// ----------------  Original assembly code with comments  -------------------
/*

<switch_prob>:
    sub $0x3c,%rsi                    // %rsi = 60 - n
    cmp $0x5,%rsi                     // check if 60 - n is > 5. Jump to default if so. If not, got to corresponding case
    ja 4005c3 <switch_prob+0x33>      // jump to default
    jmpq *0x4006f8(,%rsi,8)           // jump table location

    lea 0x0(,%rdi,8),%rax             // result = 8 * x
    retq                              // return

    mov %rdi,%rax                     // move x to result
    sar $0x3,%rax                     // shift result right by 3 bits
    retq                              // return

    mov %rdi,%rax                     // move x to result
    shl $0x4,%rax                     // shift result left by 4 bits
    sub %rdi,%rax                     // subtract x from result
    mov %rax,%rdi                     // move result to x
    imul %rdi,%rdi                    // multiply x by x
    lea 0x4b(%rdi),%rax               // result = 75 + x (default case)
    retq                              // return

*/
// ------------------------------- Jump table --------------------------------

// (gdb) x/6gx 0x4006f8
// 0x4006f8: 0x00000000004005a1 0x00000000004005c3
// 0x400708: 0x00000000004005a1 0x00000000004005aa
// 0x400718: 0x00000000004005b2 0x00000000004005bf

// we've got 6 different jump locations here ^^^

// --------------------------------- C Code ----------------------------------

long switch_prob(long x, long n) {
    
    long result = x;

    switch(n) {
        case 60:
            result = 8 * x;
            break;

        case 62:
            result = 8 * x;
            break;

        case 63:
            result = x;
            result = result >> 3;
            break;

        case 64:
            result = x;
            result = result << 4;
            result = result - x;
            x = result;

        case 65:
            x = x * x;

        default:
            result = 75 + x;
            break;
    }

    return result;

}