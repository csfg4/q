global long_mode_start
extern kernel_main

section .text
bits 64
long_mode_start:
    ; load null into registers
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov edi, 0xb8000
    mov rax, 0x1f201f201f201f20
    mov ecx, 500
    rep stosq

    call kernel_main

    hlt
