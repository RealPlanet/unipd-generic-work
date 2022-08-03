.data
   addr_n: .word 15		@ Word in memoria con il valore di n 
.bss
   addr_sum: .skip 4		@ Word in memoria dove salvare il valore finale
.text
   .global main
main:
    mov r0, #0 @@@ somma parziale
    mov r1, #-5 @@@ contatore
    mov r2, #0 @@@ quadrato calcolato ad ogni iterazione (r1*r1)
    ldr R4, =addr_n  
    ldr R3, [R4]
    ldr R5, =addr_sum
loop:
	mul r2, r1, r1 @ calcola il quadrato
    add r1, r1, #1 @ incrementa contatore
    add r0, r0, r2 @ sommalo alla somma parziale
    bl print_int
    cmp r1, r3     @ se r1 è diverso da r3 continua il loop
    ble loop       @ contatore parte da 1 quindi continua il loop
                   @ fino a che non superi il valore di r3
        @Correzzione rispetto ai codici precedenti che partivano da 0 e ottenevano un
        @risultato sbagliato
   		@@@ Parte finale del programma
    bl exit_program