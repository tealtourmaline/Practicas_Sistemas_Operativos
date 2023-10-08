.text
.globl main

main:   li $t0, 8
        li $t1, 8
        li $t2, 1

loop:   beq $t2, $t0, end
        sub $t0, $t0, $t2
        mul $t1, $t1, $t0
        j	loop


end:    move $t7, $t1
