section .text
	global ft_strcmp

ft_strcmp:
	push rdi
	push rsi
l:
	mov al, byte[rdi]
	cmp byte[rsi], al
	jg gr8r
	jl less
	cmp byte[rsi], 0
	jne lc
	mov rax, 0
	jmp r
lc:
	inc	rsi
	inc rdi
	jmp l
gr8r:
	mov rax, 1
	jmp r
less:
	mov rax, -1
r:
	pop rsi
	pop rdi
	ret
