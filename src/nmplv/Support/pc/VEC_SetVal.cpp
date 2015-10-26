//------------------------------------------------------------------------
//
//  $Workfile:: Access.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:16 $
//
//! \if file_doc
//!
//! \file   Access.cpp
//! \author ������ �������
//! \brief  ������� ������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmplv.h"

//================= VEC_SetVal ===========================================    

void VEC_SetVal(nm1*  pVec,  int nIndex, int1b nVal)
{
	nm32u nBase=(nm32u(nIndex))/32;
	nm32u nDisp=(nm32u(nIndex))%32;
	int*  pSrc=((int*)pVec)+nBase;
	int   nSrc=*pSrc;
	int	  nMask=1<<nDisp;
	nSrc&=~nMask;
	nSrc|=(nVal&1)<<nDisp;
	*pSrc=nSrc;
}

void VEC_SetVal(nm2s* pVec,  int nIndex, int2b nVal)
{
	nm32u nBase=(nm32u(nIndex))/16;
	nm32u nDisp=(nm32u(nIndex))%16;
	nDisp*=2;
	int*  pSrc=((int*)pVec)+nBase;
	int   nSrc=*pSrc;
	int	  nMask=3<<nDisp;
	nSrc&=~nMask;
	nSrc|=(nVal&3)<<nDisp;
	*pSrc=nSrc;
}

void VEC_SetVal(nm4s* pVec,  int nIndex, int4b nVal)
{
	nm32u nBase=(nm32u(nIndex))/8;
	nm32u nDisp=(nm32u(nIndex))%8;
	nDisp*=4;
	int*  pSrc=((int*)pVec)+nBase;
	int   nSrc=*pSrc;
	int	  nMask=15<<nDisp;
	nSrc&=~nMask;
	nSrc|=(nVal&15)<<nDisp;
	*pSrc=nSrc;
}

void VEC_SetVal(nm8s* pArray,  int Index, int8b Val)
{
	pArray[Index]=Val;
}

void VEC_SetVal(nm16s* pArray, int Index, int16b Val)
{
	pArray[Index]=Val;
}