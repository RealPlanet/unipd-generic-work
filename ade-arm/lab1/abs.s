.text @Calcola il valore assoluto di una sottrazione
.global main
main: mov r1, #0X2
      mov r2, #0X12
      subs r0, r1, r2 @Sottrai i due numeri
      rsbmi r0, r0, #0 @Sè l'operazione è negativa allora cambia segno
      mov pc, lr
