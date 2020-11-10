; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_read.S                                          :+:    :+:             ;
;                                                      +:+                     ;
;    By: averheij <averheij@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/17 11:48:39 by averheij      #+#    #+#                  ;
;    Updated: 2020/06/17 11:48:40 by averheij      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_read

extern __errno_location
;extern __error
; ssize_t	ft_read(int fd, const void *buf, size_t count);

_ft_read:
	push rdi		; prologue
	mov rax, 0		; syscall read
	syscall
	cmp rax, 0		; check for error
	jge _r			; use jc if this doesnt work on mac
	neg rax			; invert error
	push rax		; sto value to save in errno
    ;push rbp
    ;call __error	; errno pointer in rax
    call __errno_location
	;pop rbp
	pop	rdi
	mov [rax], edi	; pop error into errno
	mov rax, -1		; return -1
_r:
	pop rdi			; epilogue
	ret
