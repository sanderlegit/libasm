section .text
	global ft_read

extern __errno_location
;extern __error
; ssize_t	ft_read(int fd, const void *buf, size_t count);

ft_read:
	push rdi		; prologue
	mov rax, 0		; syscall read
	syscall
	cmp rax, 0		; check for error
	jge r
	neg rax			; invert error
	push rax		; sto value to save in errno
    ;push rbp
    ;call __error	; errno pointer in rax
    call __errno_location
	;pop rbp
	pop	rdi
	mov [rax], edi	; pop error into errno
	mov rax, -1		; return -1
r:
	pop rdi			; epilogue
	ret
