section .text
	global ft_strlen

ft_strlen:
	push rdi
	mov rax, 0
l:
	cmp byte[rdi], 0
	je e
	inc rdi
	inc rax
	jmp l
e:
	pop rdi
	ret
