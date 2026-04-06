; 64-bit Assembly program that prints Hello, World
; Written for NASM

    global main

    section .text
main:
    ; syscall write(1, message, 13)
    mov rax, 1          ; syscall number for write
    mov rdi, 1          ; file descriptor 1 is stdout
    mov rsi, message    ; pointer to the string
    mov rdx, 13         ; length of the string (including \n)
    syscall

    ; syscall exit(0)
    mov rax, 60         ; syscall number for exit
    xor rdi, rdi        ; return code 0
    syscall

    section .data
message:
    db "Hello, World", 10 ; 10 is the ASCII for \n
