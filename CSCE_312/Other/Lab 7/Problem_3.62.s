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
