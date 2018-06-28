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

	call test_all

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

%macro op_gb_eb1 2
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

%macro op_gb_eb2 2
	%1 %2, [SI]
	%1 %2, [DI]
%endmacro

%macro op_eb_gb1 2
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

%macro op_eb_gb2 2
	%1 [SI], %2
	%1 [DI], %2
%endmacro

%macro op_ev_gv1 2
	%1 word [BX + SI], %2
	%1 word [BX + DI], %2
	%1 word [BP + SI], %2
	%1 word [BP + DI], %2
	%1 word [test_arr_b0], %2
	%1 word [BX], %2

	%1 word [BX + SI + 1], %2
	%1 word [BX + DI + 1], %2
	%1 word [BP + SI + 1], %2
	%1 word [BP + DI + 1], %2
	%1 word [BP + 1], %2
	%1 word [BX + 1], %2

	%1 word [BX + SI + 0x101], %2
	%1 word [BX + DI + 0x101], %2
	%1 word [BP + SI + 0x101], %2
	%1 word [BP + DI + 0x101], %2
	%1 word [BP + 0x101], %2
	%1 word [BX + 0x101], %2
%endmacro

%macro op_ev_gv2 2
	%1 word [SI], %2
	%1 word [DI], %2
%endmacro

%macro op_sf_gb_gb 3
	%3
	%1 %2, AL
	%3
	%1 %2, CL
	%3
	%1 %2, DL
	%3
	%1 %2, BL
	%3
	%1 %2, AH
	%3
	%1 %2, CH
	%3
	%1 %2, DH
	%3
	%1 %2, BH
%endmacro

%macro op_sf_gv_gv 3
	%3
	%1 %2, AX
	%3
	%1 %2, CX
	%3
	%1 %2, DX
	%3
	%1 %2, BX
	%3
	%1 %2, SP
	%3
	%1 %2, BP
	%3
	%1 %2, SI
	%3
	%1 %2, DI
%endmacro

%macro op_sf_eb_gb1 3
	%3
	%1 %2, [BX + SI]
	%3
	%1 %2, [BX + DI]
	%3
	%1 %2, [BP + SI]
	%3
	%1 %2, [BP + DI]
	%3
	%1 %2, [test_arr_b0]
	%3
	%1 %2, [BX]

	%3
	%1 %2, [BX + SI + 1]
	%3
	%1 %2, [BX + DI + 1]
	%3
	%1 %2, [BP + SI + 1]
	%3
	%1 %2, [BP + DI + 1]
	%3
	%1 %2, [BP + 1]
	%3
	%1 %2, [BX + 1]

	%3
	%1 %2, [BX + SI + 0x101]
	%3
	%1 %2, [BX + DI + 0x101]
	%3
	%1 %2, [BP + SI + 0x101]
	%3
	%1 %2, [BP + DI + 0x101]
	%3
	%1 %2, [BP + 0x101]
	%3
	%1 %2, [BX + 0x101]
%endmacro

%macro op_sf_eb_gb2 3
	%3
	%1 %2, [SI]
	%3
	%1 %2, [DI]
%endmacro

%macro op_sf_gb_eb1 3
	%3
	%1 [BX + SI], %2
	%3
	%1 [BX + DI], %2
	%3
	%1 [BP + SI], %2
	%3
	%1 [BP + DI], %2
	%3
	%1 [test_arr_b0], %2
	%3
	%1 [BX], %2

	%3
	%1 [BX + SI + 1], %2
	%3
	%1 [BX + DI + 1], %2
	%3
	%1 [BP + SI + 1], %2
	%3
	%1 [BP + DI + 1], %2
	%3
	%1 [BP + 1], %2
	%3
	%1 [BX + 1], %2

	%3
	%1 [BX + SI + 0x101], %2
	%3
	%1 [BX + DI + 0x101], %2
	%3
	%1 [BP + SI + 0x101], %2
	%3
	%1 [BP + DI + 0x101], %2
	%3
	%1 [BP + 0x101], %2
	%3
	%1 [BX + 0x101], %2
%endmacro

%macro op_sf_gb_eb2 3
	%3
	%1 [SI], %2
	%3
	%1 [DI], %2
%endmacro

%macro func_no_cf_eb_gb 1
	mov [backup_sp], sp
	mov AL, 01h
	mov CL, 02h
	mov DL, 03h
	mov BL, 05h
	mov AH, 08h
	mov CH, 13h
	mov DH, 21h
	mov BH, 34h

	op_gb_gb %1, AL
	op_gb_gb %1, CL
	op_gb_gb %1, DL
	op_gb_gb %1, BL
	op_gb_gb %1, AH
	op_gb_gb %1, CH
	op_gb_gb %1, DH
	op_gb_gb %1, BH

	mov BX, test_arr_b0
	mov BP, test_arr_b1
	mov SI, 1
	mov DI, 2

	op_eb_gb1 %1, AL
	op_eb_gb1 %1, CL
	op_eb_gb1 %1, DL
	op_eb_gb1 %1, AH
	op_eb_gb1 %1, CH
	op_eb_gb1 %1, DH

	mov SI, test_arr_b1 + 3
	mov DI, test_arr_b2 + 4

	op_eb_gb2 %1, AL
	op_eb_gb2 %1, CL
	op_eb_gb2 %1, DL
	op_eb_gb2 %1, AH
	op_eb_gb2 %1, CH
	op_eb_gb2 %1, DH

	mov sp, [backup_sp]
	ret

%endmacro

%macro func_no_cf_ev_gv 1
	mov [backup_sp], sp
	mov AX, 01h
	mov CX, 02h
	mov DX, 03h
	mov BX, 05h
	mov SP, 08h
	mov BP, 13h
	mov SI, 21h
	mov DI, 34h

	op_gv_gv %1, AX
	op_gv_gv %1, CX
	op_gv_gv %1, DX
	op_gv_gv %1, BX
	op_gv_gv %1, SP
	op_gv_gv %1, BP
	op_gv_gv %1, SI
	op_gv_gv %1, DI

	mov BX, test_arr_w0
	mov BP, test_arr_w1
	mov SI, 1
	mov DI, 2

	op_eb_gb1 %1, AX
	op_eb_gb1 %1, CX
	op_eb_gb1 %1, DX
	op_eb_gb1 %1, SP

	mov SI, test_arr_w1 + 3
	mov DI, test_arr_w2 + 4

	op_eb_gb2 %1, AX
	op_eb_gb2 %1, CX
	op_eb_gb2 %1, DX
	op_eb_gb2 %1, SP

	mov sp, [backup_sp]
	ret

%endmacro

%macro func_no_cf_gb_eb 1
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

	op_gb_eb1 %1, AL
	op_gb_eb1 %1, CL
	op_gb_eb1 %1, DL
	op_gb_eb1 %1, AH
	op_gb_eb1 %1, CH
	op_gb_eb1 %1, DH

	mov SI, test_arr_b1 + 3
	mov DI, test_arr_b2 + 4

	op_gb_eb2 %1, AL
	op_gb_eb2 %1, CL
	op_gb_eb2 %1, DL
	op_gb_eb2 %1, AH
	op_gb_eb2 %1, CH
	op_gb_eb2 %1, DH

	mov sp, [backup_sp]
	ret
%endmacro

%macro func_no_cf_gv_ev 1
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

	op_gb_eb1 %1, AX
	op_gb_eb1 %1, CX
	op_gb_eb1 %1, DX
	op_gb_eb1 %1, SP

	mov SI, test_arr_w1 + 3
	mov DI, test_arr_w2 + 4

	op_gb_eb2 %1, AX
	op_gb_eb2 %1, CX
	op_gb_eb2 %1, DX
	op_gb_eb2 %1, SP

	mov sp, [backup_sp]
	ret
%endmacro

%macro func_cf_eb_gb 1
	mov [backup_sp], sp
	mov AL, 01h
	mov CL, 02h
	mov DL, 03h
	mov BL, 05h
	mov AH, 08h
	mov CH, 13h
	mov DH, 21h
	mov BH, 34h

	op_sf_gb_gb %1, AL, stc
	op_sf_gb_gb %1, CL, stc
	op_sf_gb_gb %1, DL, stc
	op_sf_gb_gb %1, BL, stc
	op_sf_gb_gb %1, AH, stc
	op_sf_gb_gb %1, CH, stc
	op_sf_gb_gb %1, DH, stc
	op_sf_gb_gb %1, BH, stc

	op_sf_gb_gb %1, AL, clc
	op_sf_gb_gb %1, CL, clc
	op_sf_gb_gb %1, DL, clc
	op_sf_gb_gb %1, BL, clc
	op_sf_gb_gb %1, AH, clc
	op_sf_gb_gb %1, CH, clc
	op_sf_gb_gb %1, DH, clc
	op_sf_gb_gb %1, BH, clc

	mov BX, test_arr_b0
	mov BP, test_arr_b1
	mov SI, 1
	mov DI, 2

	op_sf_eb_gb1 %1, AL, stc
	op_sf_eb_gb1 %1, CL, stc
	op_sf_eb_gb1 %1, DL, stc
	op_sf_eb_gb1 %1, AH, stc
	op_sf_eb_gb1 %1, CH, stc
	op_sf_eb_gb1 %1, DH, stc

	op_sf_eb_gb1 %1, AL, clc
	op_sf_eb_gb1 %1, CL, clc
	op_sf_eb_gb1 %1, DL, clc
	op_sf_eb_gb1 %1, AH, clc
	op_sf_eb_gb1 %1, CH, clc
	op_sf_eb_gb1 %1, DH, clc

	mov SI, test_arr_b1 + 3
	mov DI, test_arr_b2 + 4

	op_sf_eb_gb2 %1, AL, stc
	op_sf_eb_gb2 %1, CL, stc
	op_sf_eb_gb2 %1, DL, stc
	op_sf_eb_gb2 %1, AH, stc
	op_sf_eb_gb2 %1, CH, stc
	op_sf_eb_gb2 %1, DH, stc

	op_sf_eb_gb2 %1, AL, clc
	op_sf_eb_gb2 %1, CL, clc
	op_sf_eb_gb2 %1, DL, clc
	op_sf_eb_gb2 %1, AH, clc
	op_sf_eb_gb2 %1, CH, clc
	op_sf_eb_gb2 %1, DH, clc

	mov sp, [backup_sp]
	ret
%endmacro

%macro func_cf_ev_gv 1
	mov [backup_sp], sp
	mov AX, 01h
	mov CX, 02h
	mov DX, 03h
	mov BX, 05h
	mov SP, 08h
	mov BP, 13h
	mov SI, 21h
	mov DI, 34h

	op_sf_gv_gv %1, AX, stc
	op_sf_gv_gv %1, CX, stc
	op_sf_gv_gv %1, DX, stc
	op_sf_gv_gv %1, BX, stc
	op_sf_gv_gv %1, SP, stc
	op_sf_gv_gv %1, BP, stc
	op_sf_gv_gv %1, SI, stc
	op_sf_gv_gv %1, DI, stc

	op_sf_gv_gv %1, AX, clc
	op_sf_gv_gv %1, CX, clc
	op_sf_gv_gv %1, DX, clc
	op_sf_gv_gv %1, BX, clc
	op_sf_gv_gv %1, SP, clc
	op_sf_gv_gv %1, BP, clc
	op_sf_gv_gv %1, SI, clc
	op_sf_gv_gv %1, DI, clc

	mov BX, test_arr_w0
	mov BP, test_arr_w1
	mov SI, 1
	mov DI, 2

	op_sf_eb_gb1 %1, AX, stc
	op_sf_eb_gb1 %1, CX, stc
	op_sf_eb_gb1 %1, DX, stc
	op_sf_eb_gb1 %1, SP, stc

	op_sf_eb_gb1 %1, AX, clc
	op_sf_eb_gb1 %1, CX, clc
	op_sf_eb_gb1 %1, DX, clc
	op_sf_eb_gb1 %1, SP, clc

	mov SI, test_arr_w1 + 3
	mov DI, test_arr_w2 + 4

	op_sf_eb_gb2 %1, AX, stc
	op_sf_eb_gb2 %1, CX, stc
	op_sf_eb_gb2 %1, DX, stc
	op_sf_eb_gb2 %1, SP, stc

	op_sf_eb_gb2 %1, AX, clc
	op_sf_eb_gb2 %1, CX, clc
	op_sf_eb_gb2 %1, DX, clc
	op_sf_eb_gb2 %1, SP, clc

	mov sp, [backup_sp]
	ret
%endmacro

%macro func_cf_gb_eb 1
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

	op_sf_gb_eb1 %1, AL, stc
	op_sf_gb_eb1 %1, CL, stc
	op_sf_gb_eb1 %1, DL, stc
	op_sf_gb_eb1 %1, AH, stc
	op_sf_gb_eb1 %1, CH, stc
	op_sf_gb_eb1 %1, DH, stc

	op_sf_gb_eb1 %1, AL, clc
	op_sf_gb_eb1 %1, CL, clc
	op_sf_gb_eb1 %1, DL, clc
	op_sf_gb_eb1 %1, AH, clc
	op_sf_gb_eb1 %1, CH, clc
	op_sf_gb_eb1 %1, DH, clc

	mov SI, test_arr_b1 + 3
	mov DI, test_arr_b2 + 4

	op_sf_gb_eb2 %1, AL, stc
	op_sf_gb_eb2 %1, CL, stc
	op_sf_gb_eb2 %1, DL, stc
	op_sf_gb_eb2 %1, AH, stc
	op_sf_gb_eb2 %1, CH, stc
	op_sf_gb_eb2 %1, DH, stc

	op_sf_gb_eb2 %1, AL, clc
	op_sf_gb_eb2 %1, CL, clc
	op_sf_gb_eb2 %1, DL, clc
	op_sf_gb_eb2 %1, AH, clc
	op_sf_gb_eb2 %1, CH, clc
	op_sf_gb_eb2 %1, DH, clc

	mov sp, [backup_sp]
	ret
%endmacro

%macro func_cf_gv_ev 1
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

	op_sf_gb_eb1 %1, AX, stc
	op_sf_gb_eb1 %1, CX, stc
	op_sf_gb_eb1 %1, DX, stc
	op_sf_gb_eb1 %1, SP, stc

	op_sf_gb_eb1 %1, AX, clc
	op_sf_gb_eb1 %1, CX, clc
	op_sf_gb_eb1 %1, DX, clc
	op_sf_gb_eb1 %1, SP, clc

	mov SI, test_arr_w1 + 3
	mov DI, test_arr_w2 + 4

	op_sf_gb_eb2 %1, AX, stc
	op_sf_gb_eb2 %1, CX, stc
	op_sf_gb_eb2 %1, DX, stc
	op_sf_gb_eb2 %1, SP, stc

	op_sf_gb_eb2 %1, AX, clc
	op_sf_gb_eb2 %1, CX, clc
	op_sf_gb_eb2 %1, DX, clc
	op_sf_gb_eb2 %1, SP, clc

	mov sp, [backup_sp]
	ret
%endmacro

; Test ADD instrcution
test_00_ADD_Eb_Gb:
	func_no_cf_eb_gb add

test_01_ADD_Ev_Gv:
	func_no_cf_ev_gv add

test_02_ADD_Gb_Eb:
	func_no_cf_gb_eb add

test_03_ADD_Gv_Ev:
	func_no_cf_gv_ev add

test_ADD:
	call test_00_ADD_Eb_Gb
	call test_01_ADD_Ev_Gv
	call test_02_ADD_Gb_Eb
	call test_03_ADD_Gv_Ev
	add AL, 0xf0
	add AX, 0xf0f0
	ret

; Test ADC instrcution
test_10_ADC_Eb_Gb:
	func_cf_eb_gb adc

test_11_ADC_Ev_Gv:
	func_cf_ev_gv adc

test_12_ADC_Gb_Eb:
	func_cf_gb_eb adc

test_13_ADC_Gv_Ev:
	func_cf_gv_ev adc


test_ADC:
	call test_10_ADC_Eb_Gb
	call test_11_ADC_Ev_Gv
	call test_12_ADC_Gb_Eb
	call test_13_ADC_Gv_Ev
	stc
	adc AL, 0xf0
	stc
	adc AX, 0xf0f0
	clc
	adc AL, 0xf0
	clc
	adc AX, 0xf0f0
	ret

; Test SUB instrcution
test_28_SUB_Eb_Gb:
	func_no_cf_eb_gb sub

test_29_SUB_Ev_Gv:
	func_no_cf_ev_gv sub

test_2A_SUB_Gb_Eb:
	func_no_cf_gb_eb sub

test_2B_SUB_Gv_Ev:
	func_no_cf_gv_ev sub

test_SUB:
	call test_28_SUB_Eb_Gb
	call test_29_SUB_Ev_Gv
	call test_2A_SUB_Gb_Eb
	call test_2B_SUB_Gv_Ev
	sub AL, 0xf0
	sub AX, 0xf0f0
	ret

; Test SBB instrcution
test_18_SBB_Eb_Gb:
	func_cf_eb_gb sbb

test_19_SBB_Ev_Gv:
	func_cf_ev_gv sbb

test_1A_SBB_Gb_Eb:
	func_cf_gb_eb sbb

test_1B_SBB_Gv_Ev:
	func_cf_gv_ev sbb

test_SBB:
	call test_18_SBB_Eb_Gb
	call test_19_SBB_Ev_Gv
	call test_1A_SBB_Gb_Eb
	call test_1B_SBB_Gv_Ev
	stc
	sbb AL, 0xf0
	stc
	sbb AX, 0xf0f0
	clc
	sbb AL, 0xf0
	clc
	sbb AX, 0xf0f0
	ret

; Test AND instrcution
test_20_AND_Eb_Gb:
	func_no_cf_eb_gb and

test_21_AND_Ev_Gv:
	func_no_cf_ev_gv and

test_22_AND_Gb_Eb:
	func_no_cf_gb_eb and

test_23_AND_Gv_Ev:
	func_no_cf_gv_ev and

test_AND:
	call test_20_AND_Eb_Gb
	call test_21_AND_Ev_Gv
	call test_22_AND_Gb_Eb
	call test_23_AND_Gv_Ev
	and AL, 0xf0
	and AX, 0xf0f0
	ret

; Test XOR instrcution
test_30_XOR_Eb_Gb:
	func_no_cf_eb_gb xor

test_31_XOR_Ev_Gv:
	func_no_cf_ev_gv xor

test_32_XOR_Gb_Eb:
	func_no_cf_gb_eb xor

test_33_XOR_Gv_Ev:
	func_no_cf_gv_ev xor

test_XOR:
	call test_30_XOR_Eb_Gb
	call test_31_XOR_Ev_Gv
	call test_32_XOR_Gb_Eb
	call test_33_XOR_Gv_Ev
	xor AL, 0xf0
	xor AX, 0xf0f0
	ret

; Test OR instrcution
test_08_OR_Eb_Gb:
	func_no_cf_eb_gb or

test_09_OR_Ev_Gv:
	func_no_cf_ev_gv or

test_0A_OR_Gb_Eb:
	func_no_cf_gb_eb or

test_0B_OR_Gv_Ev:
	func_no_cf_gv_ev or

test_OR:
	call test_08_OR_Eb_Gb
	call test_09_OR_Ev_Gv
	call test_0A_OR_Gb_Eb
	call test_0B_OR_Gv_Ev
	or AL, 0xf0
	or AX, 0xf0f0
	ret

; Test CMP instrcution
test_38_CMP_Eb_Gb:
	func_no_cf_eb_gb cmp

test_39_CMP_Ev_Gv:
	func_no_cf_ev_gv cmp

test_3A_CMP_Gb_Eb:
	func_no_cf_gb_eb cmp

test_3B_CMP_Gv_Ev:
	func_no_cf_gv_ev cmp

test_CMP:
	call test_38_CMP_Eb_Gb
	call test_39_CMP_Ev_Gv
	call test_3A_CMP_Gb_Eb
	call test_3B_CMP_Gv_Ev
	cmp AL, 0xf0
	cmp AX, 0xf0f0
	ret

; Test XCHG instrcution
test_86_XCHG_Eb_Gb:
	func_no_cf_eb_gb xchg

test_87_XCHG_Ev_Gv:
	func_no_cf_ev_gv xchg

test_XCHG:
	call test_86_XCHG_Eb_Gb
	call test_86_XCHG_Eb_Gb
	mov [backup_sp], SP
	XCHG AX, CX
	XCHG AX, DX
	XCHG AX, BX
	XCHG AX, SP
	XCHG AX, BP
	XCHG AX, SI
	XCHG AX, DI
	mov SP, [backup_sp]
	ret

; Test TEST instrcution
test_84_TEST_Eb_Gb:
	func_cf_eb_gb test

test_85_TEST_Ev_Gv:
	func_cf_ev_gv test

test_86_TEST_Gb_Eb:
	func_cf_gb_eb test

test_87_TEST_Gv_Ev:
	func_cf_gv_ev test

test_TEST:
	call test_84_TEST_Eb_Gb
	call test_85_TEST_Ev_Gv
	call test_86_TEST_Gb_Eb
	call test_87_TEST_Gv_Ev
	test AL, 0xf0
	test AX, 0xf0f0
	ret

; Test MOV instrcution
test_88_MOV_Eb_Gb:
	func_cf_eb_gb mov

test_89_MOV_Ev_Gv:
	func_cf_ev_gv mov

test_8A_MOV_Gb_Eb:
	func_cf_gb_eb mov

test_8B_MOV_Gv_Ev:
	func_cf_gv_ev mov

test_A0_MOV:
	mov AL, byte [test_arr_b0]
	mov byte [test_arr_b0 + 1], AL
	mov AX, word [test_arr_b0]
	mov word [test_arr_b0 + 1], AX
	ret

test_B0_B7_MOV_Gv_Iv:
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

test_8C_MOV_Ev_Sw:
	mov [backup_sp], SP

	mov BX, test_arr_b0
	mov BP, test_arr_b1
	mov SI, 1
	mov DI, 2

	op_eb_gb1 mov, ES
	op_eb_gb1 mov, DS
	op_eb_gb1 mov, CS
	op_eb_gb1 mov, SS
	op_eb_gb1 mov, FS
	op_eb_gb1 mov, GS

	;op_gb_eb1 mov, ES
	;op_gb_eb1 mov, DS
	;op_gb_eb1 mov, CS
	;op_gb_eb1 mov, SS
	op_gb_eb1 mov, FS
	op_gb_eb1 mov, GS

	mov SI, test_arr_b1 + 3
	mov DI, test_arr_b2 + 4

	op_eb_gb2 mov, ES
	op_eb_gb2 mov, DS
	op_eb_gb2 mov, CS
	op_eb_gb2 mov, SS
	op_eb_gb2 mov, FS
	op_eb_gb2 mov, GS

	;op_gb_eb2 mov, ES
	;op_gb_eb2 mov, DS
	;op_gb_eb2 mov, CS
	;op_gb_eb2 mov, SS
	op_gb_eb2 mov, FS
	op_gb_eb2 mov, GS

	mov SP, [backup_sp]
	ret

test_8E_MOV_Sw_Ev:
	mov [backup_sp], SP

	mov BX, test_arr_b0
	mov BP, test_arr_b1
	mov SI, 1
	mov DI, 2

	mov SI, test_arr_b1 + 3
	mov DI, test_arr_b2 + 4

	mov SP, [backup_sp]
	ret

test_Segment_Prefix:
	mov AX, [DS:DI]
	mov BX, [CS:DI]
	mov CX, [SS:DI]
	mov DX, [ES:BX]
	ret

test_MOV:
	call test_A0_MOV
	call test_B0_B7_MOV_Gv_Iv
	call test_88_MOV_Eb_Gb
	call test_89_MOV_Ev_Gv
	call test_8A_MOV_Gb_Eb
	call test_8B_MOV_Gv_Ev
	call test_8C_MOV_Ev_Sw
	;call test_8E_MOV_Sw_Ev
	call test_Segment_Prefix
	ret

test_INC_DEC:
	mov [backup_sp], SP

	mov AX, 0xfffe
	mov CX, 0xfffe
	mov DX, 0xfffe
	mov BX, 0xfffe
	mov SP, 0xfffe
	mov BP, 0xfffe
	mov SI, 0xfffe
	mov DI, 0xfffe

	inc AX
	inc CX
	inc DX
	inc BX
	inc SP
	inc BP
	inc SI
	inc DI

	inc AX
	inc CX
	inc DX
	inc BX
	inc SP
	inc BP
	inc SI
	inc DI

	dec AX
	dec CX
	dec DX
	dec BX
	dec SP
	dec BP
	dec SI
	dec DI

	dec AX
	dec CX
	dec DX
	dec BX
	dec SP
	dec BP
	dec SI
	dec DI

	mov SP, [backup_sp]
	ret

test_PUSH_POP:
	mov [backup_sp], SP
	;push SP
	;push SS
	;push ES
	;push CS
	;push DS
	push AX
	push CX
	push DX
	push BX
	push BP
	push SI
	push DI

	pop DI
	pop SI
	pop BP
	pop BX
	pop DX
	pop CX
	pop AX
	;pop DS
	;pop CS
	;pop ES
	;pop SS
	;pop AX

	pusha
	popa
	mov SP, [backup_sp]
	ret

test_LEA:
	mov [backup_sp], SP
	op_gb_eb1 lea, AX
	op_gb_eb1 lea, CX
	op_gb_eb1 lea, DX
	op_gb_eb1 lea, SP

	op_gb_eb2 lea, AX
	op_gb_eb2 lea, CX
	op_gb_eb2 lea, DX
	op_gb_eb2 lea, SP
	mov SP, [backup_sp]
	ret

test_Group_1_80:
	op_eb_gb1 add, byte 1
	op_eb_gb1 or, byte 1
	stc
	op_eb_gb1 adc, byte 1
	clc
	op_eb_gb1 adc, byte 1
	stc
	op_eb_gb1 sbb, byte 1
	clc
	op_eb_gb1 sbb, byte 1
	op_eb_gb1 and, byte 1
	op_eb_gb1 sub, byte 1
	op_eb_gb1 xor, byte 1
	op_eb_gb1 cmp, byte 1
	ret

test_Group_1_81:
	op_eb_gb1 add, word 1
	op_eb_gb1 or, word 1
	stc
	op_eb_gb1 adc, word 1
	clc
	op_eb_gb1 adc, word 1
	stc
	op_eb_gb1 sbb, word 1
	clc
	op_eb_gb1 sbb, word 1
	op_eb_gb1 and, word 1
	op_eb_gb1 sub, word 1
	op_eb_gb1 xor, word 1
	op_eb_gb1 cmp, word 1
	ret

test_Group_1_83:
	op_ev_gv1 add, byte 1
	op_ev_gv1 or, byte 1
	stc
	op_ev_gv1 adc, byte 1
	clc
	op_ev_gv1 adc, byte 1
	stc
	op_ev_gv1 sbb, byte 1
	clc
	op_ev_gv1 sbb, byte 1
	op_ev_gv1 and, byte 1
	op_ev_gv1 sub, byte 1
	op_ev_gv1 xor, byte 1
	op_ev_gv1 cmp, byte 1
	ret

test_Group_1:
	mov BX, test_arr_b0
	mov BP, test_arr_b1
	mov SI, 1
	mov DI, 2
	call test_Group_1_80
	call test_Group_1_81
	call test_Group_1_83
	ret

test_Group_1A:
	mov BX, test_arr_b0
	mov BP, test_arr_b1
	mov SI, 1
	mov DI, 2

	push AX
	pop word [BX + SI]
	push AX
	pop word [BX + DI]
	push AX
	pop word [BP + SI]
	push AX
	pop word [BP + DI]
	push AX
	pop word [test_arr_b0]
	push AX
	pop word [BX]

	push AX
	pop word [BX + SI + 1]
	push AX
	pop word [BX + DI + 1]
	push AX
	pop word [BP + SI + 1]
	push AX
	pop word [BP + DI + 1]
	push AX
	pop word [BP + 1]
	push AX
	pop word [BX + 1]

	push AX
	pop word [BX + SI + 0x101]
	push AX
	pop word [BX + DI + 0x101]
	push AX
	pop word [BP + SI + 0x101]
	push AX
	pop word [BP + DI + 0x101]
	push AX
	pop word [BP + 0x101]
	push AX
	pop word [BX + 0x101]
	ret

%macro op_shift 2
	%1 AL, %2
	%1 CL, %2
	%1 DL, %2
	%1 BL, %2
	%1 AH, %2
	%1 CH, %2
	%1 DH, %2
	%1 BH, %2

	%1 AX, %2
	%1 CX, %2
	%1 DX, %2
	%1 BX, %2
	%1 SP, %2
	%1 BP, %2
	%1 SI, %2
	%1 DI, %2
%endmacro

%macro all_op_shift 1
	op_shift rol, %1
	op_shift ror, %1
	op_shift rcl, %1
	op_shift rcr, %1
	op_shift shl, %1
	op_shift shr, %1
	op_shift sar, %1
%endmacro

test_Group_2:
	mov [backup_sp], SP
	mov AX, 0xfedc
	mov DX, 0xcba9
	mov CX, 0xa987
	mov BX, 0x8765
	mov SP, 0x6543
	mov BP, 0x4321
	mov SI, 0x1234
	mov DI, 0xcdef

	all_op_shift 3
	all_op_shift 23
	all_op_shift 1
	all_op_shift cl
	mov SP, [backup_sp]
	ret

%macro unary_op 1
	%1 AX
	%1 AL
	%1 word [BX]
	%1 byte [BP]
%endmacro

test_Group_3:
	mov BX, test_arr_b0
	mov BP, test_arr_w0
	mov AX, 0x1234

	test AX, word 0x1234
	test AL, byte 0x34
	test [BX], word 0x2345
	test [BP], byte 0xcd

	mov AX, 0x2345
	mov [BX], AX
	mov AX, 0xabcd
	mov [BP], AX

	unary_op not
	unary_op neg
	unary_op mul
	unary_op imul

	mov DX, 0x1000
	mov AX, 0x2000
	div AX
	mov AX, 55h
	div AL

	mov DX, 0x1000
	mov AX, 0x7000
	idiv AX
	mov AX, 0xad
	idiv AL

	ret

test_Group_4_5:
	mov BX, test_arr_b0
	mov BP, test_arr_w0
	mov AX, 0x1234
	mov SI, 1
	mov DI, 2

	inc AL
	inc AX
	inc byte [BX+SI]
	inc byte [BP+DI]
	inc word [BX+SI]
	inc word [BP+DI]

	dec AL
	dec AX
	dec byte [BX+SI]
	dec byte [BP+DI]
	dec word [BX+SI]
	dec word [BP+DI]

	call near test_Group_1
	ret

test_Group_11:
	mov BX, word test_arr_b0
	mov BP, word test_arr_w0
	mov AX, 0x1234
	mov SI, 1
	mov DI, 2

	mov byte [BX+SI+1], 1
	mov byte [BX+DI+2], 1
	mov byte [BX+3], 1
	mov byte [BP+4], 1

	mov word [BX+SI+1], 1
	mov word [BX+DI+2], 1
	mov word [BX+3], 1
	mov word [BP+4], 1

	ret

test_all:
	call test_MOV
	call test_ADD
	call test_ADC
	call test_SUB
	call test_SBB
	call test_AND
	call test_OR
	call test_XOR
	call test_CMP
	call test_TEST
	call test_XCHG
	call test_INC_DEC
	call test_PUSH_POP
	call test_LEA
	call test_Group_1
	call test_Group_1A
	call test_Group_2
	call test_Group_3
	call test_Group_4_5
	call test_Group_11
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
