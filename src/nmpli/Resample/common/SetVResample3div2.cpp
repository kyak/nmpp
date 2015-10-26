/*
#include "internal.h"
#include "math.h"
#include "internal.h"
#include "fstream.h"
double PolyphaseFilter3x4[3*4*2+1] = {     
		 0,
   -0.0057,
   -0.0062,
         0,
    0.0323,
    0.0367,
   -0.0000,
   -0.1120,
   -0.1394,
    0.0000,
    0.3983,
    0.7956,
    1.0000,
    0.7956,
    0.3983,
    0.0000,
   -0.1394,
   -0.1120,
   -0.0000,
    0.0367,
    0.0323,
         0,
   -0.0062,
   -0.0057,
   0};


//!
//! \n
//!

void IMG_CreateTable_VResample3div2()
{

	double* pFilter=PolyphaseFilter3x4;

	nmvec8s vBankA(8);
	nmvec8s vBankB(8);
	
	float K=64;
	
	nmint8s nBank1   =(int)floor(pFilter[12]*K+0.5);

	vBankA[0]=(int)floor(pFilter[2]*K+0.5);
	vBankA[1]=(int)floor(pFilter[5]*K+0.5);
	vBankA[2]=(int)floor(pFilter[8]*K+0.5);
	vBankA[3]=(int)floor(pFilter[11]*K+0.5);
	vBankA[4]=(int)floor(pFilter[14]*K+0.5);
	vBankA[5]=(int)floor(pFilter[17]*K+0.5);
	vBankA[6]=(int)floor(pFilter[20]*K+0.5);
	vBankA[7]=(int)floor(pFilter[23]*K+0.5);
	
	vBankB[0]=(int)floor(pFilter[1]*K+0.5);
	vBankB[1]=(int)floor(pFilter[4]*K+0.5);
	vBankB[2]=(int)floor(pFilter[7]*K+0.5);
	vBankB[3]=(int)floor(pFilter[10]*K+0.5);
	vBankB[4]=(int)floor(pFilter[13]*K+0.5);
	vBankB[5]=(int)floor(pFilter[16]*K+0.5);
	vBankB[6]=(int)floor(pFilter[19]*K+0.5);
	vBankB[7]=(int)floor(pFilter[22]*K+0.5);
	

	nmmtr8s mPack(12,16);
	mPack.reset();

	int i;
	for(int y=0,x=3;y<12;y+=3,x+=2)
	{
		for(i=0;i<6;i++)
			mPack[y][x+i]=vBankA[i+1];

		mPack[y+1][x+3]=nBank1;
	
		for(i=0;i<6;i++)
			mPack[y+2][x+i+1]=vBankB[i+1];
	}
	cout << mPack << flush;
	nmmtr8s mBanksRam (mPack.m_data,12,8,16);
	nmmtr8s mBanksData(mPack.m_data+8,12,8,16);
	
	ofstream fout_asm("VResample3div2Tbl.asm");
	fout_asm << "// Generated by IMG_CreateTable_VResample3div2()\n ";
	fout_asm << "global _VResample3div2Banks_Ram: ";
	AsmArray(fout_asm,mBanksRam);

	fout_asm << "global _VResample3div2Banks_Data: ";
	AsmArray(fout_asm,mBanksData);

	//ofstream fout_cpp("fDctTable.cpp");

	//fout_cpp << "double tblDCT_left[8][8]=" << tblDCT_left;
	//fout_cpp << "double tblDCT_right[8][8]=" << tblDCT_left;
	
}
*/