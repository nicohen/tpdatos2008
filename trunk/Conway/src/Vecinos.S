#include <mips/regdef.h>

        .text
	.globl vecinos
vecinos:
	subu	sp,sp,16	# Armo STACK de 16 Bytes
	sw	$fp,12(sp)
	sw	gp,8(sp)
	move	$fp,sp
	sw	a0,16($fp)	#Guardo los parametros en el STACK del CALLE
	sw	a1,20($fp)
	sw	a2,24($fp)
	sw	a3,28($fp)

	li	v0,0		# Recupero los parametros e inicializo la respuesta
	li	t7, 49		# '1'
	lw	t0,16($fp)	# a
	lw	t1,20($fp)	# i
	lw	t2,24($fp)	# j
	lw	t3,28($fp)	# M
	lw	t4,32($fp)	# N

	beq	zero,t1,$LABEL1	# busco veciono superior izquierdo
	subu	t5,t1,1		# calculo fila superior
	b	$LABEL2

$LABEL1:
	subu	t5,t3,1

$LABEL2:
	mult	t5,t4		#calculo offset por fila
	mflo	t5

	beq	zero,t2,$LABEL3 #calculo columna izquieda
	subu	t6,t2,1
	b	$LABEL4

$LABEL3:
	subu	t6,t4,1

$LABEL4:
	addu	t6,t5,t6	#calculo offset final
	addu	t6,t0,t6
	lb	t6,0(t6)	#recupero caracter y comparo
	bne	t6,t7,$LABEL5
	addi	v0,v0,1

$LABEL5:
	addu	t6,t2,t5	# busco veciono superior
	addu	t6,t0,t6	#calculo offset final
	lb	t6,0(t6)	#recupero caracter y comparo
	bne	t6,t7,$LABEL6
	addi	v0,v0,1

$LABEL6:
	addi	t6,t2,1		# busco veciono superior derecho
	bne	t6,t4,$LABEL7	#calculo columna derecha
	move	t6,zero

$LABEL7:
	addu	t6,t5,t6	#calculo offset final
	addu	t6,t0,t6
	lb	t6,0(t6)	#recupero caracter y comparo
	bne	t6,t7,$LABEL8
	addi	v0,v0,1

$LABEL8:
	mult t1,t4		# busco vecino izquierdo
	mflo	t5		#calculo offset por fila

	beq	zero,t2,$LABEL9	#calculo columna izquieda
	subu	t6,t2,1	
	b	$LABEL10

$LABEL9:
	subu	t6,t4,1

$LABEL10:
	addu	t6,t5,t6	#calculo offset final
	addu	t6,t0,t6
	lb	t6,0(t6)	#recupero caracter y comparo
	bne	t6,t7,$LABEL11
	addi	v0,v0,1

$LABEL11:
	addi	t6,t2,1		# busco veciono derecho
	bne	t6,t4,$LABEL12	#calculo columna derecha
	move	t6,zero

$LABEL12:
	addu	t6,t5,t6	#calculo offset final
	addu	t6,t0,t6
	lb	t6,0(t6)	#recupero caracter y comparo
	bne	t6,t7,$LABEL13
	addi	v0,v0,1

$LABEL13:
	addi	t5,t1,1		# busco veciono inferior izquierdo
	bne	t5,t3,$LABEL14	# calculo fila inferior
	move	t5,zero

$LABEL14:
	mult	t5,t4		#calculo offset por fila
	mflo	t5

	beq	zero,t2,$LABEL15#calculo columna izquierda
	subu	t6,t2,1
	b	$LABEL16

$LABEL15:
	subu	t6,t4,1

$LABEL16:
	addu	t6,t5,t6	#calculo offset final
	addu	t6,t0,t6
	lb	t6,0(t6)	#recupero caracter y comparo
	bne	t6,t7,$LABEL17
	addi	v0,v0,1

$LABEL17:
	addu	t6,t2,t5	# busco veciono inferior
	addu	t6,t0,t6	#calculo offset final
	lb	t6,0(t6)	#recupero caracter y comparo
	bne	t6,t7,$LABEL18
	addi	v0,v0,1

$LABEL18:
	addi	t6,t2,1		# busco veciono inferior derecho
	bne	t6,t4,$LABEL19	#calculo columna derecha
	move	t6,zero

$LABEL19:
	addu	t6,t5,t6	#calculo offset final
	addu	t6,t0,t6
	lb	t6,0(t6)	#recupero caracter y comparo
	bne	t6,t7,$LABEL20
	addi	v0,v0,1

$LABEL20:
	move	sp,$fp
	lw	$fp,12(sp)
	addu	sp,sp,16
	j	ra
