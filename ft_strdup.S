; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strdup.S                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: averheij <averheij@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/18 13:28:31 by averheij      #+#    #+#                  ;
;    Updated: 2020/06/18 13:28:31 by averheij      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_strdup

extern _ft_strlen
extern _ft_strcpy
extern malloc

; char *strdup(const char *s);

_ft_strdup:
	push rsi		; prologue
	push rdi
	call _ft_strlen	; count *s
	inc	rax			; + '\0'
	mov rdi, rax	; count to arg reg
	call malloc
	cmp	rax, 0		; check fail
	je _error
	mov rdi, rax	; copy into dest
	mov rsi, [rsp]
	call _ft_strcpy
	pop rdi			; epilogue
	pop rsi
	ret
_error:
	mov rax, 0		; return null
	ret
