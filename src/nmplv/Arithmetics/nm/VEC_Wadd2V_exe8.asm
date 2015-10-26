//------------------------------------------------------------------------
//
//  $Workfile:: VEC_Wadd2V_set8.asm             $
//
//  <nmplv>
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:04 $
//
//! \if file_doc
//!
//! \file   VEC_Wadd2V_exe8.asm
//! \author ������ ���������
//! \brief  <���������� ����� ���� �������� ���� nm8s>
//!
//! \endif
//!
//------------------------------------------------------------------------

begin ".text_nmplv"
extern vec_Mul2D2W8_AddVr:label;

// void VEC_WAdd2V_Exe(nm8s* pSrcVec1,nm8s* pSrcVec2, S_VEC_WAdd2V* kerW, nm16s* pDstVec, int nSize);

global _void._.8.8VEC_WAdd2V_Exe.1char._.0.9._char._.0.9._class._S_VEC_WAdd2V._.0.9._short._.0.9._int.2 :label;
<_void._.8.8VEC_WAdd2V_Exe.1char._.0.9._char._.0.9._class._S_VEC_WAdd2V._.0.9._short._.0.9._int.2>
  ar5=ar7-2;
  push ar0,gr0; push ar1,gr1;  push ar2,gr2; push ar4,gr4; push ar6,gr6;
  ar0=[--ar5]with gr4=false;// pSrcVec1
  ar1=[--ar5]with gr0=gr4+1;// pSrcVec2
  ar4=[--ar5]with gr0<<=1;  // kerW
  ar6=[--ar5]with gr1=gr0;  // pDstVec
     push ar5,gr5;
  gr5=[--ar5]with gr6=gr0<<1;  // nSize, gr6=4
  vr=gr4 with gr5>>=3;
  gr4=80008000h;// 4x16 on Y Vport
  nb1=gr4;
  ar5=ar6;
  ar2=ar0;gr2=ar1;
  ar4=ar4+8;
delayed call vec_Mul2D2W8_AddVr;
  sb=2020202h; // 8x8 on X Vport
  ar6=ar5+2;

  ar0=ar2;ar1=gr2;
delayed call vec_Mul2D2W8_AddVr;
  ar4=ar4-8;
  pop ar5,gr5;
  pop ar6,gr6;
  pop ar4,gr4; pop ar2,gr2;
  pop ar1,gr1; pop ar0,gr0;
  return;
///==========================================

end ".text_nmplv";