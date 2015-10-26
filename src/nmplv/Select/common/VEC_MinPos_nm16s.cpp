//------------------------------------------------------------------------
//
//  $Workfile:: GetMin.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   GetMin.cpp
//! \author ������ �������
//! \brief  �������������� ������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmplv.h"
//!
//! \perfinclude _VEC_MinPos__FPSsiRiRiPvPvi.html
//! 
void VEC_MinPos (nm16s15b *pSrcVec, int nSize, int& nIndex, int16b &nMinValue, void *pLTmpBuff,void *pGTmpBuff, int nSearchDir)
{
	int nPos;
	void* pTmp1;
	void* pTmp2;
	
	//if ((int)pSrcVec>0){
		pTmp1=pGTmpBuff;
		pTmp2=pLTmpBuff;
	//}
	//else	{
	//	pTmp1=pLTmpBuff;
	//	pTmp2=pGTmpBuff;
	//}

	VEC_MinVal(pSrcVec, nSize, nMinValue);
	VEC_SubC(pSrcVec,nMinValue,(nm16s*)pTmp1,nSize);
	VEC_CmpEq0((nm16u15b*)pTmp1,(nm1*)pTmp2,nSize,0); //Create min bitmap

	if(nSearchDir > 0){
		nPos  =VEC_FirstNonZeroPos((int*)pTmp2,nSize>>5);
		int n=((int*)pTmp2)[nPos];	
		for(nIndex=0; nIndex<32; nIndex++){
			if (n&1)
				break;
			n>>=1;
		}
	} else {
		nPos  =VEC_LastNonZeroPos((int*)pTmp2,nSize>>5); 
		int n=((int*)pTmp2)[nPos];	
		for(nIndex=31; nIndex>=0; nIndex--){
			if (n&0x80000000)
				break;
			n<<=1;
		}
	}
	nIndex+=nPos*32;
}
