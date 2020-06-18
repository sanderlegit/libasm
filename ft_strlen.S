; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strlen.S                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: averheij <averheij@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/17 11:49:48 by averheij      #+#    #+#                  ;
;    Updated: 2020/06/17 11:49:48 by averheij      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_strlen

; size_t	ft_strlen(const char *str);

_ft_strlen:
	push rdi				; prologue
	mov rax, 0				; initialize counter
_l:
	cmp byte[rdi + rax], 0	; check for null terminator
	je _le
	inc rax					; incr counter
	jmp _l
_le:
	pop rdi					; epilogue
	ret
