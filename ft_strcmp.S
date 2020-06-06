section .text
	global ft_strcmp

ft_strcmp:
	push rdi
	push rsi
l:
	mov al, byte[rdi]
	cmp byte[rsi], al
	jne le
	cmp byte[rsi], 0
	jne lc
	mov rax, 0
	jmp r
lc:
	inc	rsi
	inc rdi
	jmp l
le:
	mov rax, 0
	mov al, byte[rdi]
	mov r8, 0
	mov r8b, byte[rsi]
	sub rax, r8
r:
	pop rsi
	pop rdi
	ret
