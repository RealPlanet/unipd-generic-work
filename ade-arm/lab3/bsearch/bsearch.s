.text
.global bsearch
	@Input
	@ FP+8 key
	@ FP+12 estremo dx
	@ FP+16 estremo sx
	@ FP+20 indirizzo vettore
bsearch: 
	push {fp,lr} 
    mov fp, sp
    push {r1-r5}
    ldr r1, [fp, #8]    @	key
    ldr r2, [fp, #12]	@	j indice dx
    ldr r3, [fp, #16]   @	i indice sx
    ldr r4, [fp, #20]   @	ind vettore
    cmp r2, r3 @ if r3>r2 return -1
    bhs N_empty
    pop {r1-r5}
	mov sp, fp
	pop {fp,lr}
	mov r0, #-1
	mov pc, lr

N_empty:
	add r5, r2, r3
    mov r5, r5, asr #1
    ldr r0, [r4, r5, ASL #2]
    cmp r1, r0   
    bne  not_key@do search on dx
    mov r0, r5
    pop {r1-r5}
	mov sp, fp
	pop {fp,lr}
	mov pc, lr

not_key:
	blt  elsesx @do search on sx
	add r5, r5, #1
	mov r0, r4
	push {r0} @ r4 = ind vettore
	mov r0, r5
	push {r0} @ r5 = i
	mov r0, r2
	push {r0} @ r2 = j, 
	mov r0, r1
	push {r0} @ r1 = key
	bl bsearch
	add sp, sp, #16	@ rimuovo parametri input per bsearch nello stack
	mov sp, fp
	pop {fp,lr}
	mov pc, lr

elsesx: @saves each arg in the correct order for bsearch
	sub r5, r5, #1
	mov r0, r4
	push {r0} @r4 = ind vettore
	mov r0, r3
	push {r0} @ r3 = i
	mov r0, r5
	push {r0} @ r5 = j
	mov r0, r1
	push {r0} @r1 = key
	bl bsearch
	add sp, sp, #16	@ rimuovo parametri input per bsearch nello stack
	mov sp, fp
	pop {fp,lr}
	mov pc, lr