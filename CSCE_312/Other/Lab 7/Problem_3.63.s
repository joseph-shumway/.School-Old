<switch_prob>:
        sub $0x3c,%rsi                    // subtract 60 from rsi
        cmp $0x5,%rsi                     // set condition codes for rsi
        ja 4005c3 <switch_prob+0x33>      // jump if above address at jump location
        jmpq *0x4006f8(,%rsi,8)           // jump to jump table
        lea 0x0(,%rdi,8),%rax             // load effective address of __ to rax
        retq                              // return

        mov %rdi,%rax                     // move rdi to rax
        sar $0x3,%rax                     // move 3 to rax
        retq                              // return

        mov %rdi,%rax                     // move rdi to rax
        shl $0x4,%rax                     // shift rax by 4 bits
        sub %rdi,%rax                     // subtract rdi from rax
        mov %rax,%rdi                     // move rax to rdi
        imul %rdi,%rdi                    // multiply rdi by rdi
        lea 0x4b(%rdi),%rax               // load effective address of __ to rax
        retq                              // return