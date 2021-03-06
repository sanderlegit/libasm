; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strcpy.S                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: averheij <averheij@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/17 11:49:38 by averheij      #+#    #+#                  ;
;    Updated: 2020/06/17 11:49:38 by averheij      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_strcpy

; char		*ft_strcpy(char *dest, const char *src);

_ft_strcpy:
	push rdi			; prologue
	push rsi
_l:
	mov	al, byte[rsi]	; copy char
	mov byte[rdi], al
	cmp byte[rsi], 0	; check for null term
	je _le
	inc	rsi				; incr ptrs
	inc rdi
	jmp _l
_le:
	pop rsi				; epilogue
	pop rdi
	mov rax, rdi		; return dest
	ret
