// File: Problem_3.62.c
// Author: Joseph Shumway
// Date: 11/14/2021
// Section: 504
// E-mail: joseph.shumway@tamu.edu 
// Description:
// This file implements problem 3.62 in C from Assembly

// ---------------  Original assembly code with comments  -----------------------
/*

// p1 in %rdi, p2 in %rsi, action in %edx, value in %eax
.L8: MODE_E
    movl $27, %eax    // move 27 to result
    ret               // return

.L3: MODE_A
    movq (%rsi), %rax // move value in [p2] to result
    movq (%rdi), %rdx // move value in [p1] to p2
    movq %rdx, (%rsi) // move p2 to [p2]
ret                   // return

.L5: MODE_B
    movq (%rdi), %rax // move value in [p1] to result
    addq (%rsi), %rax // add value in [p2] to result
    movq %rax, (%rdi) // move result to [p1]
ret                   // return

.L6: MODE_C
    movq $59, (%rdi)  // move 59 to [p1]
    movq (%rsi), %rax // move value in [p2] to result
    ret               // return

.L7: MODE_D
    movq (%rsi), %rax // move value in [p2] to result
    movq %rax, (%rdi) // move result to [p1]
    movl $27, %eax    // move 27 to result
    ret               // return

.L9: default          
    movl $12, %eax    // move 12 to result
    ret               // return
    
*/
// --------------------------------- C Code -------------------------------------


/* Enumerated type creates set of constants numbered 0 and upward */


typedef enum {MODE_A, MODE_B, MODE_C, MODE_D, MODE_E} mode_t;

long switch3(long *p1, long *p2, mode_t action) {
    
    long result = 0;

    switch(action) {
        case MODE_A:
            result = *p2;
            *p2 = *p1;
            break;

        case MODE_B:
            result = *p1;
            result = result + *p2;
            *p1 = result;
            break;

        case MODE_C:
            *p1 = 59;
            result = *p2;
            break;

        case MODE_D:
            result = *p2;
            p1 = result;
            result = 27;
            break;

        case MODE_E:
            result = 27;
            break;

        default:
            result = 12;
            break;
    }

    return result;

}