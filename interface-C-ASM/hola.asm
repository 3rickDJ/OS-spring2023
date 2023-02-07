global main
extern printf
section .data
msg: db "Hello, World!", 0xa, 0
section .text
main:
    push dword msg
    call printf
    add esp, 4
    ret
