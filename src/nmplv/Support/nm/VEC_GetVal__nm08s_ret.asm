//------------------------------------------------------------------------
//
//  $Workfile:: CharShortAccess.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:11 $
//
//! \if file_doc
//!
//! \file   CharShortAccess.asm
//! \author ������ �������
//! \brief  ������� ������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vConvert.h"

//! \fn int8b VEC_GetVal (nm8s *pVec, int nIndex) 
//!
//! \perfinclude _VEC_GetVal__FPci.html

begin ".text_nmplv"
global _VEC_GetVal__FPci:	label;
global _int._.8.8VEC_GetVal.1char._.0.9._int.2 :label;
<_VEC_GetVal__FPci>
<_int._.8.8VEC_GetVal.1char._.0.9._int.2>
.branch;
	ar5 = ar7 - 2;
	push ar0, gr0;
	ar0 = [--ar5];	// pVec				
	gr7 = [--ar5];	// nIndex				
	gr0 = gr7>>2;
	gr7 = [ar0+=gr0] with gr0=gr7<<30;
	with gr0>>=28;
	gr0++;
	gr0++;
	delayed skip gr0;
		pop ar0, gr0;
		nul;
		nul;

	delayed return with	gr7<<=24;
		gr7 A>>=24;
		nul;
		nul;
	delayed return with	gr7<<=16;
		gr7 A>>=24;
		nul;
		nul;
	delayed return with	gr7<<=8;
		gr7 A>>=24;
		nul;
		nul;
	delayed return with	gr7 A>>=24;
		nul;
		nul;
		nul;
.wait;




end ".text_nmplv";