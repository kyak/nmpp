//------------------------------------------------------------------------
//
//  $Workfile:: Sub.as $
//
//  <�������� ����������>
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file Sub.Asm
//! \author ������ ������� 
//! \brief ��������� ������� � ��������� �� �������.
//!
//! \endif
//!
//------------------------------------------------------------------------


extern vec_Sub:label;

begin ".text_nmplv"


/////////////////////////////////////////////////////////////////////////////////////////

//! \fn void VEC_SubV (nm32s *pSrcVec1, nm32s *pSrcVec2, nm32s *pDstVec, int nSize) 
//!
//! \perfinclude _VEC_SubV__FPiPiPii.html

global _VEC_SubV__FPiPiPii:label;
global _void._.8.8VEC_SubV.1int._.0.9._int._.0.9._int._.0.9._int.2 :label;
<_VEC_SubV__FPiPiPii>
<_void._.8.8VEC_SubV.1int._.0.9._int._.0.9._int._.0.9._int.2>
.branch;
	ar5 = sp - 2 with gr7=false;
	push ar0,gr0 with gr7++;
	push ar1,gr1 with gr0=gr7+1;	// gr0=2
	push ar5,gr5 with gr1=gr0;		// gr1=2 
	push ar6,gr6 with gr6=gr0;		// gr6=2

	ar0 = [--ar5];	// pSrcVec1
	ar1 = [--ar5];	// pSrcVec2
	ar6 = [--ar5];	// pDstVec
	gr5 = [--ar5];	// nSize in 32-bit elements
	
	nb1 = 80000000h with gr5>>=1;	// nSize in 64-bit words
	delayed call vec_Sub;
		nul;
		wtw;						

	pop ar6,gr6;
	pop ar5,gr5;
	pop ar1,gr1;
	pop ar0,gr0;
return;
.wait;



end ".text_nmplv";