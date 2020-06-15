section .text
	global ft_strcpy

; char		*ft_strcpy(char *dest, const char *src);

ft_strcpy:
	push rdi
	push rsi
l:
	mov	al, byte[rsi]
	mov byte[rdi], al
	cmp byte[rsi], 0
	je le
	inc	rsi
	inc rdi
	jmp l
le:
	pop rsi
	pop rdi
	mov rax, rdi
	ret
