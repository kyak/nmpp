//------------------------------------------------------------------------
//
//  $Workfile:: Neg_8s $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   Neg_8s.Asm
//! \author ������ �������
//! \brief  ��������� ����� ��������� ������� �� ���������������.
//!
//! \endif
//!
//------------------------------------------------------------------------
//#include "vArithm.h"


extern vec_0_sub_data:label;

begin ".text_nmplv"


/////////////////////////////////////////////////////////////////////////////////////////

//! \fn void VEC_Neg (nm32s *pSrcVec, nm32s *pDstVec, int nSize) 
//!
//! \perfinclude _VEC_Neg__FPiPii.html

global _VEC_Neg__FPiPii:label;
global _void._.8.8VEC_Neg.1int._.0.9._int._.0.9._int.2 :label;
<_VEC_Neg__FPiPii>
<_void._.8.8VEC_Neg.1int._.0.9._int._.0.9._int.2>
.branch;
	ar5 = sp - 2	with gr7=gr5;
	push ar0,gr0	with gr0=false;
	push ar6,gr6	with gr0++;
	
	
	nb1 = 80000000h	with gr0++;
	
	ar0 = [--ar5]with gr6=gr0;	// pSrcVec
	ar6 = [--ar5];				// pDstVec
	gr5 = [--ar5];	// nSize
						
	delayed call  vec_0_sub_data with gr5>>=1;	// nSize in 64-bit longs
		wtw;
		nul;
	
	pop ar6,gr6;
	pop ar0,gr0		with gr5=gr7;
	return;
.wait;




end ".text_nmplv";