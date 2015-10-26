//------------------------------------------------------------------------
//
//  $Workfile:: SubNV.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   SubNV.asm
//! \author ������ �������
//! \brief  ������� ��������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

extern vec_ram_sub_data:label;
extern  _VEC_TmpBuffer16_G:long;

begin ".text_nmplv"


/////////////////////////////////////////////////////////////////////////////////////////
//! \fn void VEC_SubC_Neg (nm16s *pSrcVec, int16b nVal, nm16s *pDstVec, int nSize) 
//!
//! \perfinclude _VEC_SubC_Neg__FPSsiPSsi.html

global _VEC_SubC_Neg__FPSsiPSsi:label;
global _void._.8.8VEC_SubC_Neg.1short._.0.9._int.9._short._.0.9._int.2 :label;
<_VEC_SubC_Neg__FPSsiPSsi>
<_void._.8.8VEC_SubC_Neg.1short._.0.9._int.9._short._.0.9._int.2>
.branch;
	ar5 = sp - 2	with gr7=false;
	push ar0,gr0	with gr7++;
	push ar1,gr1	with gr7++;
	push ar5,gr5	with gr0=gr7;
	push ar6,gr6	with gr6=gr7;
	ar0 = [--ar5];						// pSrcVec
	gr1 = [--ar5];						// SrcN
	ar6 = [--ar5]	with gr7 = gr1<<16;	// pDstVec
	gr5 = [--ar5]	with gr1 = gr7>>16;		// nSize
	
	ar1 = _VEC_TmpBuffer16_G+2	with gr1 = gr1 or gr7;
	nb1 = 80008000h;
	wtw;
	delayed call vec_ram_sub_data 	with gr5>>=2;		// nSize in 64-bit longs
		[--ar1]=gr1;	
		[--ar1]=gr1;
	
	pop ar6,gr6;
	pop ar5,gr5;
	pop ar1,gr1;
	pop ar0,gr0;
return;
.wait;



end ".text_nmplv";