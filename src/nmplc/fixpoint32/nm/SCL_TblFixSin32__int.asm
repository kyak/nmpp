//***************************************************************************/
//*                                                                         */
//*                    Neuroprocessor NM6403 SDK v.1.2                      */
//*                                                                         */
//*				Signed Fixed Point 32-bit Routine                           */
//*                                                                         */
//*             ���������� ������ ����� � ������������� �������             */
//*                                                                         */
//*                                                                         */
//*                1999 (c) RC Module Inc., Moscow, Russia                  */
//***************************************************************************/
//	Arg1 - Angle
//--------------------------
//	Res1 - Sin
//!!!!!!!!!!!!!!!!!!! ������ ����� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
const FIXPOINT=16; //��������� �������� ����� � 32-� ��������� �����
const N=9;//804-����� - ��������� ������������ ������ ������� �������� ������ 
//const N=10//1608-�����
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
const PI2 = (6487ed51h >> (30-FIXPOINT)) ;//PI2=90 ����.
const MAXINDEX=PI2 >> (FIXPOINT-N);//������ ������� �������� ������

import from macros.mlb;
extern FixSinDat:word;
begin ".text_nmpl�"
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//                            Fixed  Point Sine                             //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//! \fn int SCL_TblFixSin32(int nArg)
//! 
//! \perfinclude _SCL_TblFixSin32__Fi.html
global _SCL_TblFixSin32:label;
<_SCL_TblFixSin32>
.branch;
	ar5 = sp-2;
	gr7 = [--ar5];
	push ar1,gr1 with gr7;
	//with gr7=Arg;// �������� ���������� ����� gr7			 
	//���������� ������ ����
	if >= delayed skip 4 with gr1=gr7;
		ar1=FixSinDat ;
	gr1=-gr1;
	nul;
	//����������� �������� ,�������������� ������� ����
		gr1 >>=(FIXPOINT-N);	//���������� ������� �� �������� ����
		gr7=[ar1+=gr1] with gr7;
	//��������� ����� ���������	 
	if >= delayed skip 4;
		pop ar1,gr1;
		nul;
	gr7=-gr7;
	nul;
	return;


.wait;
end ".text_nmpl�";