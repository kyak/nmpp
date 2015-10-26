//------------------------------------------------------------------------
//
//  $Workfile:: Cnv08to16.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:08 $
//
//! \if file_doc
//!
//! \file   Cnv08to16.asm
//! \author ������ �������
//! \brief  ������� �������������� ��������� �������.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vConvert.h"

extern vec_vsum_data_0:label;
data ".data"
    WConvert8to16: long[16] =  ( 1l, 10000hl, 100000000hl, 1000000000000hl, 0l dup 8,
								 1l, 10000hl, 100000000hl, 1000000000000hl);
end ".data";

begin ".text_nmplv"
/////////////////////////////////////////////////////////////////////////////////



//! \fn void VEC_Cnv( nm8s* pSrcVec, nm16s* pDstVec, int nSize);
//!
//! \perfinclude _VEC_Cnv__FPcPSsi.html

global _void._.8.8VEC_Cnv.1char._.0.9._short._.0.9._int.2 :label;
<_void._.8.8VEC_Cnv.1char._.0.9._short._.0.9._int.2>
.branch;
 	delayed goto JumpFromSigned;
		nb1 = 80008000h;

/////////////////////////////////////////////////////////////////////////////////

//! \fn void VEC_Cnv( nm8u* pSrcVec, nm16u* pDstVec, int nSize);
//!
//! \perfinclude _VEC_Cnv__FPUcPUsi.html

global _VEC_Cnv__FPUcPUsi:label;
global _void._.8.8VEC_Cnv.1unsigned._char._.0.9._unsigned._short._.0.9._int.2 :label;
<_VEC_Cnv__FPUcPUsi>
<_void._.8.8VEC_Cnv.1unsigned._char._.0.9._unsigned._short._.0.9._int.2>
.branch;

	nb1 = 80808080h;
	<JumpFromSigned>
	ar5 = WConvert8to16;
	sb  = 02020202h;
	rep 16 wfifo =[ar5++],ftw;

	ar5 = sp - 2;
	push ar0,gr0	with gr0=false;
	push ar5,gr5	with gr0++;
	push ar6,gr6	with gr0++;		//gr0=2

	ar0 = [--ar5]	with gr6=gr0;	// pSrcVec , gr6=2
	ar6 = [--ar5] ;					// pDstVec
	gr5 = [--ar5] ;					// nSize in 8-bit elements 
	gr7 = ar0		with gr5>>=3;
	ar5 = ar6+gr6	with gr6<<=1;	// gr6=4
		
	delayed call vec_vsum_data_0;
		wtw;
		ftw;		
		
	ar0 = gr7;
	ar6 = ar5;
	delayed call vec_vsum_data_0;
		wtw;
		nul;

	pop ar6,gr6;
	pop ar5,gr5;
	pop ar0,gr0;
	return;
.wait;
end ".text_nmplv";