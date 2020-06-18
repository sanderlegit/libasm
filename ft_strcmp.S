; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strcmp.S                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: averheij <averheij@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/17 11:49:21 by averheij      #+#    #+#                  ;
;    Updated: 2020/06/17 11:49:21 by averheij      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_strcmp

; int		ft_strcmp(const char *s1, const char *s2);

_ft_strcmp:
	push rdi			; prologue
	push rsi
_l:
	mov al, byte[rdi]	; cmp chars
	cmp byte[rsi], al
	jne _le
	cmp byte[rsi], 0	; check for null
	jne _lc
	mov rax, 0			; return 0
	jmp _r
_lc:
	inc	rsi				; incr ptrs
	inc rdi
	jmp _l
_le:
	mov rax, 0			; calculate char diff
	mov al, byte[rdi]
	mov r8, 0
	mov r8b, byte[rsi]
	sub rax, r8
_r:
	pop rsi				; epilogue
	pop rdi
	ret
