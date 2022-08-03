/* Some routines for the AE lab 2020 */

.text

/* A function to print in the output standard an
 integer stored in register R0. */
.global print_int
print_int:
	push {r0-r12, lr}
	mov r1, r0
	ldr r0, =str_print_int
	bl printf
	pop  {r0-r12, lr}
	mov pc, lr

.global read_int
read_int:
	push {r1-r12, lr}
	sub sp, sp, #4
	mov r1, sp
	bl  scanf
	ldr r0, [sp]
	add sp, sp, #4
	pop {r1-r12, lr}
	mov pc, lr


/* A function to end a program and to return the control to the operating system.*/
.global exit_program
exit_program:
    /* syscall exit(int status) */
    mov     r0, #0     /* status := 0 */
    mov     r7, #1     /* exit is syscall #1 */
    swi     #0          /* invoke syscall */


.data
.align 4
/*A string required by function print_int*/
str_print_int: .asciz "%d\n"


