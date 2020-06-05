section .text
	global ft_strcpy

ft_strcpy:
	push rdi
	push rsi
l:
	mov	al, byte[rsi]
	mov byte[rdi], al
	cmp byte[rsi], 0
	je e
	inc	rsi
	inc rdi
	jmp l
e:
	pop rsi
	pop rdi
	mov rax, rdi
	ret
