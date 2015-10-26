//------------------------------------------------------------------------
//
//  $Workfile:: Filter32to32.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.2 $      $Date: 2005/01/26 13:23:47 $
//
//! \if file_doc
//!
//! \file   Filter16to32.asm
//! \author S. Mushkaev
//! \brief  ������ ���������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

data ".data_nmpls_L"
mul02,mul0N:label;
mul12,mul1N:label;

	addrmul0: word[4]=(0,0,mul02,mul0N);
	addrmul1: word[4]=(0,0,mul12,mul1N);
	disp:word;
end ".data_nmpls_L";


begin ".text_nmpls"

    //--------------------------------------------------------------------
    //! \fn void SIG_Filter(nm16s* pSrcVec, nm32s* pDstVec, int nSize, nm64s* pKernel)
	//!
	// \perfinclude _SIG_Filter__FPSsPiiPl.html
    //--------------------------------------------------------------------
extern vec_ClipMulNDNW4_AddVr:label;
extern vec_Mul2D2W4_AddVr:label;


global _SIG_Filter__FPSsPiiPl:label;
global _void._.8.8SIG_Filter.1short._.0.9._int._.0.9._int.9._long._.0.2 :label;
<_SIG_Filter__FPSsPiiPl>
<_void._.8.8SIG_Filter.1short._.0.9._int._.0.9._int.9._long._.0.2>
.branch;
	ar5 = sp - 2;

	push ar0,gr0;
	push ar1,gr1;
	push ar2,gr2;
	push ar3,gr3;
	push ar4,gr4;
	push ar5,gr5;
	push ar6,gr6;
	
 	ar0 = [--ar5];	// pSrcVec
	ar6 = [--ar5];	// pDstVec
	gr5 = [--ar5];	// nSize
	ar5 = [--ar5] with	// pKernel
	gr5 >>=2;

	sb	= 00020002h;
	gr4 = 80000000h;
	nb1 = gr4;
	f1cr= 0;
	vr  = 0;
	gr6 = 4;
//	ar4=ar5+6;
//	[disp]=ar4;

	//========== mul 0 ==========
	push ar0,gr0;
	push ar6,gr6;
	gr1 = [ar5++];					// Number of arrays
	with gr7=gr1>>2;
	if > delayed goto lab0;
		ar1 = mul0N;				
	ar1 = addrmul0;
	ar1 = [ar1+=gr1];
	<lab0>
	delayed goto ar1;
		ar1 = [ar5++];				// Displacement to ar0
		ar4 = [ar5++];				// Pointer to weight array 
	
	<mul02>
	gr0 = [ar1];
	nul;
	ar0+= gr0;
	gr0 = 2;
	delayed call vec_Mul2D2W4_AddVr with gr7=false;
		ar1=ar0+gr0 with gr1=gr0;		
		f1cr = gr7;

	delayed goto finish0;
		pop ar6,gr6;
		pop ar0,gr0;
	
	<mul0N>
	delayed call vec_ClipMulNDNW4_AddVr;
		gr0 = 2;
		
	pop ar6,gr6;
	pop ar0,gr0;
	<finish0>
	//=========== mul 1 ====================
	ar6+= 2;
	push ar0,gr0;
	push ar6,gr6;
	gr1 = [ar5++];					// Number of arrays
	with gr7=gr1>>2;		
	if > delayed goto lab1;
		ar1 = mul1N;
	ar1 = addrmul1;
	ar1 = [ar1+=gr1];
	<lab1>
	delayed goto ar1;
		ar1 = [ar5++];				// Displacement to ar0
		ar4 = [ar5++];				// Pointer to weight array 
	
	<mul12>
	gr0 = [ar1];
	nul;
	ar0+= gr0;
	gr0 = 2;
	delayed call vec_Mul2D2W4_AddVr;
		ar1=ar0+gr0 with gr1=gr0;		
		nul;

	delayed goto finish1;
		pop ar6,gr6;
		pop ar0,gr0;
	
	<mul1N>
	delayed call vec_ClipMulNDNW4_AddVr;
		gr0 = 2;
		
	pop ar6,gr6;
	pop ar0,gr0;
	<finish1>
	//=========== finish ====================

	<finish>

    pop ar6,gr6;
	pop ar5,gr5;
	pop ar4,gr4;
	pop ar3,gr3;
	pop ar2,gr2;
	pop ar1,gr1;
	pop ar0,gr0;
	
 
	return;

.wait;
end ".text_nmpls";