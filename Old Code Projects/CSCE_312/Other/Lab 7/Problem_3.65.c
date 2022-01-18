// File: Problem_3.65.c
// Author: Joseph Shumway
// Date: 11/14/2021
// Section: 504
// E-mail: joseph.shumway@tamu.edu 
// Description:
// This file implements problem 3.65 in C from Assembly

int M = 0;

void transpose(long A[M][M]) {
    long i, j;
    for(i = 0; i < M; i++) {
        for(j = 0; j < i; j++) {
            long t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
    }
}




/*

.L6:
    movq     (%rdx), %rcx       // move value at rdx to rcx
    movq     (%rax), %rsi       // move value at rax to rsi
    movq     %rsi, (%rdx)       // move value at rsi to rdx
    movq     %rcx, (%rax)       // move rcx to rax
    addq     $8, %rdx           // add 8 to rdx
    addq     $120, %rax         // add 120 to rax
    cmpq     %rdi, %rax         // compare rdi to rax
    jne     .L6                 // jump to L6 if not equal to zero

*/



//A. Which register holds a pointer to array element A[i][j]?   %rdx holds this pointer

// B. Which register holds a pointer to array element A[j][i]?  %rax holds this pointer

// C. What is the value of M?   15
