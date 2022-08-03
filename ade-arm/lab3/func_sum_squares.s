.text
@ Semplice funzione che calcola (r0+r1)^2 e salva il risultato in r0
sum_square: 
	push {r1, r2}
	add r2, r0, r1
	mul r0, r2, r2
	pop {r1, r2}
	mov pc, lr

.global main
main:
	push {r0, r1, lr}
	mov r0, #5
	mov r1, #3
	bl sum_square
	nop
	pop {r0, r1, lr}
	mov pc,lr
