//------------------------------------------------------------------------
//
//  $Workfile:: Abs.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   Abs.Asm
//! \author ������ �������
//! \brief  ���������� �������� ��������� �������.
//!
//! \endif
//!
//------------------------------------------------------------------------
//#include "vArithm.h"

extern _VEC_TBL_Diagonal_FFh_G:long;
extern vec_Abs:label;

begin ".text_nmplv"


//! \fn void VEC_Abs (nm8s *pSrcVec, nm8s *pDstVec, int nSize) 
//!
//! \perfinclude _VEC_Abs__FPcPci.html

global _VEC_Abs__FPcPci:label;
global _void._.8.8VEC_Abs.1char._.0.9._char._.0.9._int.2 :label;
<_VEC_Abs__FPcPci>
<_void._.8.8VEC_Abs.1char._.0.9._char._.0.9._int.2>
.branch;
	ar5 = sp - 2	with gr7=gr5;
	push ar0,gr0	with gr0=false;
	push ar6,gr6	with gr0++;
	
	sb	= 02020202h	with gr0++;
	nb1 = 80808080h	with gr6=gr0;
	ar6 = _VEC_TBL_Diagonal_FFh_G;
	rep 8 wfifo=[ar6++],ftw;
	
	ar0 = [--ar5];	// pSrcVec
	ar6 = [--ar5];	// pDstVec
	gr5 = [--ar5];	// nSize
	wtw;
						
	delayed call  vec_Abs with gr5>>=3;	// nSize in 64-bit longs
		f1cr= 80808080h;   

	pop ar6,gr6;
	pop ar0,gr0		with gr5=gr7;
	return;
.wait;
end ".text_nmplv";