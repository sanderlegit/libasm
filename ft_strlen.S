section .text
	global ft_strlen

; size_t	ft_strlen(const char *str);

ft_strlen:
	push rdi
	mov rax, 0
l:
	cmp byte[rdi], 0
	je le
	inc rdi
	inc rax
	jmp l
le:
	pop rdi
	ret
