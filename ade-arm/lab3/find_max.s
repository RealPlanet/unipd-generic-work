.text
.global find_max

@ Input: 
@   * FP+4 indirizzo in memoria del vettore di interi con segno; 
@   * FP+8 numero di elementi del vettore; 

@ Output:
@   * r0: il valor massimo del vettore

find_max: 
   @@@ istruzioni della funzione max
   push {fp} 
   mov fp, sp
   push {r1-r4}@ temp, save max in r2, r3 is iterator, r4 holds value of V[i]
   
   mov r3, #0
   mov r2, #0
   ldr r0, [fp, #4]
   ldr r1, [fp, #8]
loop:
	ldr r4, [r0, r3, lsl #2] @load in r2 the item at r0+i*4
	cmp r2, r4 @if r2-r3 < 0 then r3 > r2
	ldrmi r2, [r0, r3, lsl #2] @save element at i into r2
	add r3, r3, #1 @Iteration done, increment counter
	cmp r3, r1 @ r3-r1
	bmi loop @If r3 < r1 then continue iteration
	mov r0, r2
	pop {r1-r4} @Restore initial value of r1 to r4

	mov sp, fp
	pop {fp}

    mov pc, lr   @ ritorna alla funzione chiamante.

