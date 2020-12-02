; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_write.S                                         :+:    :+:             ;
;                                                      +:+                     ;
;    By: averheij <averheij@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/17 11:50:02 by averheij      #+#    #+#                  ;
;    Updated: 2020/06/17 11:50:02 by averheij      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_write

extern __errno_location
;extern __error
; ssize_t	ft_write(int fd, const void *buf, size_t count);

_ft_write:
	push rdi		; prologue
	mov rax, 0x2000004; syscall write
	syscall
	cmp rax, 0		; check for error
	jge _r
	neg rax			; invert error
	push rax		; sto value to save in errno
    ;push rbp
	call __error	; errno pointer in rax
	;pop rbp
	pop	rdi
	mov [rax], edi	; pop error into errno
	mov rax, -1		; return -1
_r:
	pop rdi			; epilogue
	ret
