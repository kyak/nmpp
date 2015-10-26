//------------------------------------------------------------------------
//
//  $Workfile:: FilterWxH.cp $
//
//  ���������� ��������� �����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/02/10 12:36:38 $
//
//! \if file_doc
//!
//! \file   Cnv16_WxH.cpp
//! \author S. Mushkaev
//! \brief  ������� ���������� ����.
//! 
//! \endif
//!
//------------------------------------------------------------------------

#include "nmpls.h"
#include "nmpli.h"



void IMG_Filter( nm8s * pSrcImg, nm16s* pDstImg, int nWidth, int nHeight, nm64s* pKernel)
{

	SIG_Filter(pSrcImg, pDstImg, nWidth*nHeight, pKernel);
}


