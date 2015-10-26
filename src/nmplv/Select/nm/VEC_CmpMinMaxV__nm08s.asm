//------------------------------------------------------------------------
//
//  $Workfile:: CompareMinMaxV_8s.asm             $
//
//  Vector-processing library
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:09 $
//
//! \if file_doc
//!
//! \file   CompareMinV_8s.asm
//! \author ������ ���������
//! \brief  Elementwise min/max comparision
//!
//! \endif
//!
//------------------------------------------------------------------------


extern vec_CompareMinMax:label;


begin ".text_nmplv"

//! \fn void  VEC_CmpMinMaxV (nm8s *pSrcVec1, nm8s *pSrcVec2, nm8s *pDstMin, nm8s *pDstMax, int nSize)
//!
//! \perfinclude _VEC_CmpMinMaxV__FPcPcPcPci.html

global _VEC_CmpMinMaxV__FPcPcPcPci:label;
global _void._.8.8VEC_CmpMinMaxV.1char._.0.9._char._.0.9._char._.0.9._char._.0.9._int.2 :label;
<_VEC_CmpMinMaxV__FPcPcPcPci>
<_void._.8.8VEC_CmpMinMaxV.1char._.0.9._char._.0.9._char._.0.9._char._.0.9._int.2>
.branch;
	ar5=sp-2;
	push ar0,gr0 with gr0=false;
	push ar1,gr1 with gr0++;
    push ar2,gr2 with gr0++;
	push ar3,gr3 with gr1=gr0;
	push ar4,gr4 with gr3=gr0;
	push ar5,gr5 with gr4=gr0;
	push ar6,gr6;

	ar0 = [--ar5];		        // pSrcVec1
	ar1 = [--ar5];			    // pSrcVec2
	gr6 = [--ar5];			    // pDstMin
    ar6 = [--ar5];              // pDstMax
	gr7 = [--ar5]with gr5=gr0;  // nSize
	ar5=gr6 with gr6=gr0;
	
	nb1 =80808080h with gr7>>=3;
	wtw;
	delayed call vec_CompareMinMax;
		f1cr=80808080h;
		
	pop ar6,gr6;
	pop ar5,gr5;
    pop ar4,gr4;
	pop ar3,gr3;
	pop ar1,gr1;
    pop ar2,gr2;
	pop ar0,gr0;
return;
.wait;
end ".text_nmplv";