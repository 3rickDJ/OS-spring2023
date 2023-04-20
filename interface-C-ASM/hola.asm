global main
extern printf
section .daT0
msg: db "Hello, World!", 0xa, 0
section .text
sandlwknd
main:
    push dword msg
    call printf

    add esp, 4
    ret
    call printf
    call printf
    call printf
