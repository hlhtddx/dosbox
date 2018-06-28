;Testname=unoptimized; Arguments=-O0 -fbin -obinexe.exe -i../misc/; Files=stdout stderr binexe.exe
;Testname=optimized;   Arguments=-Ox -fbin -obinexe.exe -i../misc/; Files=stdout stderr binexe.exe

; Demonstration of how to write an entire .EXE format program by using
; the `exebin.mac' macro package.
; To build:
;    nasm -fbin binexe.asm -o binexe.exe -ipath
; (where `path' is such as to allow the %include directive to find
; exebin.mac)
; To test:
;    binexe
; (should print `hello, world')

%include "exebin.mac"

	EXE_begin
	;EXE_stack 64		; demonstrates overriding the 0x800 default

	section .text

	mov ax,cs
	mov ds,ax

	mov dx,hello
	mov ah,9
	int 0x21

	call test_MOV
	call test_ADD

	mov ax,0x4c00
	int 0x21

%macro op_gb_gb 2
	%1 %2, AL
	%1 %2, CL
	%1 %2, DL
	%1 %2, BL
	%1 %2, AH
	%1 %2, CH
	%1 %2, DH
	%1 %2, BH
%endmacro

%macro op_gv_gv 2
	%1 %2, AX
	%1 %2, CX
	%1 %2, DX
	%1 %2, BX
	%1 %2, SP
	%1 %2, BP
	%1 %2, SI
	%1 %2, DI
%endmacro

%macro op_eb_gb1 2
	%1 %2, [BX + SI]
	%1 %2, [BX + DI]
	%1 %2, [BP + SI]
	%1 %2, [BP + DI]
	%1 %2, [test_arr_b0]
	%1 %2, [BX]

	%1 %2, [BX + SI + 1]
	%1 %2, [BX + DI + 1]
	%1 %2, [BP + SI + 1]
	%1 %2, [BP + DI + 1]
	%1 %2, [BP + 1]
	%1 %2, [BX + 1]

	%1 %2, [BX + SI + 0x101]
	%1 %2, [BX + DI + 0x101]
	%1 %2, [BP + SI + 0x101]
	%1 %2, [BP + DI + 0x101]
	%1 %2, [BP + 0x101]
	%1 %2, [BX + 0x101]
%endmacro

%macro op_eb_gb2 2
	%1 %2, [SI]
	%1 %2, [DI]
%endmacro

%macro op_gb_eb1 2
	%1 [BX + SI], %2
	%1 [BX + DI], %2
	%1 [BP + SI], %2
	%1 [BP + DI], %2
	%1 [test_arr_b0], %2
	%1 [BX], %2

	%1 [BX + SI + 1], %2
	%1 [BX + DI + 1], %2
	%1 [BP + SI + 1], %2
	%1 [BP + DI + 1], %2
	%1 [BP + 1], %2
	%1 [BX + 1], %2

	%1 [BX + SI + 0x101], %2
	%1 [BX + DI + 0x101], %2
	%1 [BP + SI + 0x101], %2
	%1 [BP + DI + 0x101], %2
	%1 [BP + 0x101], %2
	%1 [BX + 0x101], %2
%endmacro

%macro op_gb_eb2 2
	%1 [SI], %2
	%1 [DI], %2
%endmacro

test_00_ADD_Eb_Gb:
	mov [backup_sp], sp
	mov AL, 01h
	mov CL, 02h
	mov DL, 03h
	mov BL, 05h
	mov AH, 08h
	mov CH, 13h
	mov DH, 21h
	mov BH, 34h

	op_gb_gb add, AL
	op_gb_gb add, CL
	op_gb_gb add, DL
	op_gb_gb add, BL
	op_gb_gb add, AH
	op_gb_gb add, CH
	op_gb_gb add, DH
	op_gb_gb add, BH

	mov BX, test_arr_b0
	mov BP, test_arr_b1
	mov SI, 1
	mov DI, 2

	op_eb_gb1 add, AL
	op_eb_gb1 add, CL
	op_eb_gb1 add, DL
	op_eb_gb1 add, AH
	op_eb_gb1 add, CH
	op_eb_gb1 add, DH

	mov SI, test_arr_b1 + 3
	mov DI, test_arr_b2 + 4

	op_eb_gb2 add, AL
	op_eb_gb2 add, CL
	op_eb_gb2 add, DL
	op_eb_gb2 add, AH
	op_eb_gb2 add, CH
	op_eb_gb2 add, DH

	mov sp, [backup_sp]
	ret

test_01_ADD_Ev_Gv:
	mov [backup_sp], sp
	mov AX, 01h
	mov CX, 02h
	mov DX, 03h
	mov BX, 05h
	mov SP, 08h
	mov BP, 13h
	mov SI, 21h
	mov DI, 34h

	op_gv_gv add, AX
	op_gv_gv add, CX
	op_gv_gv add, DX
	op_gv_gv add, BX
	op_gv_gv add, SP
	op_gv_gv add, BP
	op_gv_gv add, SI
	op_gv_gv add, DI

	mov BX, test_arr_w0
	mov BP, test_arr_w1
	mov SI, 1
	mov DI, 2

	op_eb_gb1 add, AX
	op_eb_gb1 add, CX
	op_eb_gb1 add, DX
	op_eb_gb1 add, SP

	mov SI, test_arr_w1 + 3
	mov DI, test_arr_w2 + 4

	op_eb_gb2 add, AX
	op_eb_gb2 add, CX
	op_eb_gb2 add, DX
	op_eb_gb2 add, SP

	mov sp, [backup_sp]
	ret

test_02_ADD_Gb_Eb:
	mov [backup_sp], sp
	mov AL, 01h
	mov CL, 02h
	mov DL, 03h
	mov BL, 05h
	mov AH, 08h
	mov CH, 13h
	mov DH, 21h
	mov BH, 34h

	mov BX, test_arr_b0
	mov BP, test_arr_b1
	mov SI, 1
	mov DI, 2

	op_gb_eb1 add, AL
	op_gb_eb1 add, CL
	op_gb_eb1 add, DL
	op_gb_eb1 add, AH
	op_gb_eb1 add, CH
	op_gb_eb1 add, DH

	mov SI, test_arr_b1 + 3
	mov DI, test_arr_b2 + 4

	op_gb_eb2 add, AL
	op_gb_eb2 add, CL
	op_gb_eb2 add, DL
	op_gb_eb2 add, AH
	op_gb_eb2 add, CH
	op_gb_eb2 add, DH

	mov sp, [backup_sp]
	ret

test_03_ADD_Gv_Ev:
	mov [backup_sp], sp
	mov AX, 01h
	mov CX, 02h
	mov DX, 03h
	mov BX, 05h
	mov SP, 08h
	mov BP, 13h
	mov SI, 21h
	mov DI, 34h

	mov BX, test_arr_w0
	mov BP, test_arr_w1
	mov SI, 1
	mov DI, 2

	op_gb_eb1 add, AX
	op_gb_eb1 add, CX
	op_gb_eb1 add, DX
	op_gb_eb1 add, SP

	mov SI, test_arr_w1 + 3
	mov DI, test_arr_w2 + 4

	op_gb_eb2 add, AX
	op_gb_eb2 add, CX
	op_gb_eb2 add, DX
	op_gb_eb2 add, SP

	mov sp, [backup_sp]
	ret

test_ADD:
	call test_00_ADD_Eb_Gb
	call test_01_ADD_Ev_Gv
	call test_02_ADD_Gb_Eb
	call test_03_ADD_Gv_Ev
	add AL, 20
	add AX, 20
	ret

test_88_MOV_Eb_Gb:
	mov [backup_sp], SP
	op_gb_gb mov, AL
	op_gb_gb mov, CL
	op_gb_gb mov, DL
	op_gb_gb mov, BL
	op_gb_gb mov, AH
	op_gb_gb mov, CH
	op_gb_gb mov, DH
	op_gb_gb mov, BH

	mov BX, test_arr_b0
	mov BP, test_arr_b1
	mov SI, 1
	mov DI, 2

	op_eb_gb1 mov, AL
	op_eb_gb1 mov, CL
	op_eb_gb1 mov, DL
	op_eb_gb1 mov, AH
	op_eb_gb1 mov, CH
	op_eb_gb1 mov, DH

	mov SI, test_arr_b1 + 3
	mov DI, test_arr_b2 + 4

	op_eb_gb2 mov, AL
	op_eb_gb2 mov, CL
	op_eb_gb2 mov, DL
	op_eb_gb2 mov, AH
	op_eb_gb2 mov, CH
	op_eb_gb2 mov, DH
	mov SP, [backup_sp]
	ret

test_89_MOV_Ev_Gv:
	mov [backup_sp], SP
	op_gv_gv mov, AX
	op_gv_gv mov, CX
	op_gv_gv mov, DX
	op_gv_gv mov, BX
	op_gv_gv mov, SP
	op_gv_gv mov, BP
	op_gv_gv mov, SI
	op_gv_gv mov, DI

	mov BX, test_arr_w0
	mov BP, test_arr_w1
	mov SI, 1
	mov DI, 2

	op_eb_gb1 mov, AX
	op_eb_gb1 mov, CX
	op_eb_gb1 mov, DX
	op_eb_gb1 mov, SP

	mov SI, test_arr_w1 + 3
	mov DI, test_arr_w2 + 4

	op_eb_gb2 mov, AX
	op_eb_gb2 mov, CX
	op_eb_gb2 mov, DX
	op_eb_gb2 mov, SP

	mov SP, [backup_sp]
	ret

test_8A_MOV_Gb_Eb:
	mov [backup_sp], sp
	mov AL, 01h
	mov CL, 02h
	mov DL, 03h
	mov BL, 05h
	mov AH, 08h
	mov CH, 13h
	mov DH, 21h
	mov BH, 34h

	mov BX, test_arr_b0
	mov BP, test_arr_b1
	mov SI, 1
	mov DI, 2

	op_gb_eb1 mov, AL
	op_gb_eb1 mov, CL
	op_gb_eb1 mov, DL
	op_gb_eb1 mov, AH
	op_gb_eb1 mov, CH
	op_gb_eb1 mov, DH

	mov SI, test_arr_b1 + 3
	mov DI, test_arr_b2 + 4

	op_gb_eb2 mov, AL
	op_gb_eb2 mov, CL
	op_gb_eb2 mov, DL
	op_gb_eb2 mov, AH
	op_gb_eb2 mov, CH
	op_gb_eb2 mov, DH

	mov sp, [backup_sp]
	ret

test_8B_MOV_Gv_Ev:
	mov [backup_sp], sp
	mov AX, 01h
	mov CX, 02h
	mov DX, 03h
	mov BX, 05h
	mov SP, 08h
	mov BP, 13h
	mov SI, 21h
	mov DI, 34h

	mov BX, test_arr_w0
	mov BP, test_arr_w1
	mov SI, 1
	mov DI, 2

	op_gb_eb1 mov, AX
	op_gb_eb1 mov, CX
	op_gb_eb1 mov, DX
	op_gb_eb1 mov, SP

	mov SI, test_arr_w1 + 3
	mov DI, test_arr_w2 + 4

	op_gb_eb2 mov, AX
	op_gb_eb2 mov, CX
	op_gb_eb2 mov, DX
	op_gb_eb2 mov, SP

	mov sp, [backup_sp]
	ret

test_A8_MOV:
	mov AL, byte [test_arr_b0]
	mov byte [test_arr_b0 + 1], AL
	mov AX, word [test_arr_b0]
	mov word [test_arr_b0 + 1], AX
	ret

test_B0_MOV_Gv_Iv:
	mov [backup_sp], SP
	mov AX, 01h
	mov CX, 02h
	mov DX, 03h
	mov BX, 05h
	mov SP, 08h
	mov BP, 13h
	mov SI, 21h
	mov DI, 34h
	mov SP, [backup_sp]
	ret

test_MOV:
	call test_A8_MOV
	call test_B0_MOV_Gv_Iv
	call test_88_MOV_Eb_Gb
	call test_89_MOV_Ev_Gv
	call test_8A_MOV_Gb_Eb
	call test_8B_MOV_Gv_Ev
	ret

	section .data

hello:	  	db 'hello, world', 13, 10, '$'
backup_sp: 	dw 0

test_arr_b0:	db 00h, 01h, 02h, 03h, 04h, 05h, 06h, 07h
test_arr_w0:	dw 00h, 01h, 02h, 03h, 04h, 05h, 06h, 07h
test_arr_b1:	db 10h, 11h, 12h, 13h, 14h, 15h, 16h, 17h
test_arr_w1:	db 10h, 11h, 12h, 13h, 14h, 15h, 16h, 17h
test_arr_b2:	db 20h, 21h, 22h, 23h, 24h, 25h, 26h, 27h
test_arr_w2:	db 20h, 21h, 22h, 23h, 24h, 25h, 26h, 27h

	section .bss
test_data_tbl:	resb 0x10000
	EXE_end
