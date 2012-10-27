extern printf
printf_int:
	 db "%d", 10, 0
printf_float:
	 db"%f", 10, 0
global main
global pow
global powF	 ;pow function for floats
section	 .text
pow:	 ;declaration of power function
	push ebp
	mov ebp, esp
	mov ecx, [ebp+8]
	mov ebx, [ebp+12]
	mov eax, [ebp+12]
Loop:
	dec ecx
	cmp ecx, 0
	jle J1
	imul ebx
	jmp Loop
J1:
	leave
	ret

powF:	 ;declaration of floating point power function
	 push ebp
	 mov ebp, esp
	 mov ecx, [ebp+8]	 ;getting the number of repitions needed
	 sub esp, 8	 ;make room for float number
	 fld QWORD [ebp+12]	 ;push the float onto the float stack st(0)
	 fld QWORD [ebp+12]	 ;push on again so st(1) now holds the same value as st(0)
	 fstp QWORD [esp]	 ;put float number into space made available so it can be accessed later
Loop2:
	 dec ecx
	 cmp ecx, 0
	 jle J2
	 fld QWORD [esp]	 ;push the float onto the float stack so st(0) and st(1) are the same
fmul	 ;multiply st(0) by st(1)
	 jmp Loop2
J2:
	 leave
	 ret
anded:	 ;declaration of function to determine the result of anding two booleans
	 push ebp
	 mov ebp, esp
	 mov eax, [ebp+8]
	 cmp eax, 0	 ;compare sum to 0
	 jnz not_true	 ;answer was not 0, thus not true so jump out
	 mov eax, 0	 ;mov 0 to signify it was true
	 jmp done	 ;jump to escape because answer was 0
	 not_true:
	 mov eax, 1	 ;mov one to signify false
	 done:
	 leave
	 ret

noted:	 ;declaration of function to determine the result of not'ing the boolean
	 push ebp
	 mov ebp, esp
	 mov eax, [ebp+8]
	 cmp eax, 0	 ;test if we not a 0
	 jnz not_false	 ;eax was not 0 so we need to not a 1
	 mov eax, 1	 ;not 0 = 1
	 jmp exit
	 not_false:
	 mov eax, 0	 ;eax was originally 1 so we need to not it to a 0
	 exit:
	 leave
	 ret

main:
	push ebp
	mov ebp, esp
	mov eax, 0
	mov ebx, 0
	mov ecx, 0
	mov edx, 0

	 push 0
	 push 1
	 pop ebx
	 pop eax
	 add eax, ebx	 ;adding together to see if sum is 0
	 push DWORD eax	 ;pushing argument on stack
	 call anded	 ;calling function to test the result of anding
	 add esp, 4
	 push DWORD eax

	 pop eax
	 push DWORD eax
	 call noted	 ;calling function to determine what value is returned after the not
	 add esp, 4
	 push DWORD eax

	 push DWORD printf_int	 ;sets up and calls print(extern)
	 call printf
	 add esp, 8	 ;clean up the DWORD and int arg that was on the stack

	 section	 .data	 ;creating global variable stack pointer
	 variable_stack:
	 times 0 db 0

	 section	 .text	 ;going back to code section
	 leave
	 ret
