//------------------------------------------------------------------------
//
//  $Workfile:: MultipleAdd16.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   MultipleAdd16.Asm
//! \author ������ �������
//! \brief  ������� ��������� � ����������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------
//#include "vArithm.h"


data ".data_nmplv_G"
	WeightsMultipeAdd:long[4]=(
				0000000000000001hl,
				0000000000010000hl,
				0000000100000000hl,
				0001000000000000hl
					  );

end ".data_nmplv_G";

import from macros.mlb;

begin ".text_nmplv"



/////////////////////////////////////////////////////////////////////////////////////////
//! \fn void VEC_AddNV (nm16s **ppSrcVec, nm16s *pDstVec, int nSize, int nNumberOfVectors) 
//!
//! \perfinclude _VEC_AddNV__FPPSsPSsii.html

global _VEC_AddNV__FPPSsPSsii:label;
global _void._.8.8VEC_AddNV.1short._.0.0.9._short._.0.9._int.9._int.2 :label;
<_VEC_AddNV__FPPSsPSsii>
<_void._.8.8VEC_AddNV.1short._.0.0.9._short._.0.9._int.9._int.2>
.branch;
	ar5 = sp - 2;

	
	PUSH_REGS();
	gr0 = [--ar5];	// Buffers
	ar6 = [--ar5];	// DstBuffer
	gr4 = [--ar5];	// SizeOfBuffers
	gr5 = [--ar5];	// NumbersOfBuffers
	
	nb1 = 80008000h with gr4>>=2;	// nSize in 64-bit longs
	sb  = 00020002h;
	ar4 = WeightsMultipeAdd;
	rep 4 wfifo=[ar4++],ftw;
    
	//gr4>>=5;
	gr5 --;
	//gr6 = 2;
	gr1 = 0;
	gr2 = 2;//64;
	wtw;
	<Next_SelectBlock_rep32>
		ar0 = gr0;
		gr7 = gr5-1;	
		ar1 =[ar0++];
		nul;
		ar1 +=gr1;
		rep 1 data=[ar1++] with vsum ,data,0;			// Buffer[0] 
		<Next_BufferAdd_rep32>
			ar1=[ar0++];								// ar1=Buffer[i]
			nul;
		if <>0 delayed  goto Next_BufferAdd_rep32 with gr7--; 
			ar1+=gr1;									// ar1=Buffer[i]+i*32*2;
			rep 1 data=[ar1++] with vsum ,data,afifo;	// +=Buffer[i]
		
		rep 1 [ar6++]=afifo;
	
		gr1+=gr2;
		with gr4--;										// Buffer nSize in rep32
	if<>0 delayed goto Next_SelectBlock_rep32;
		nul;
		nul;
	<Finish>
	
	POP_REGS();
	return ;
.wait;
end ".text_nmplv";
 

