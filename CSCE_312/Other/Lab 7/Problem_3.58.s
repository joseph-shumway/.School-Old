# x = %rdi
# y = %rsi
# z = %rdx

# value = %rax 

decode2:
    subq %rdx, %rsi     // subtract z from y and store in y
    imulq %rsi, %rdi    // multiply x by y and store in x
    movq %rsi, %rax     // move y to value
    salq $63, %rax      // shift rax left by 63
    sarq $63, %rax      // shift rax right by 63
    xorq %rdi, %rax     // xor value and x
    ret                 // return