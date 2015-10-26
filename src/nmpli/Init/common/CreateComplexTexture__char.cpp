//------------------------------------------------------------------------
//
//  $Workfile:: CellTexture.cpp             $
//
//  <�������� ����������>
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/02/10 12:36:38 $
//
//! \if file_doc
//!
//! \file   CellTexture.cpp
//! \author Sergey V. Vaganov esq.
//! \brief  <������� ��������>
//!
//! \endif
//!
//------------------------------------------------------------------------
#define NOMINMAX

#include "nmpli.h"
//#include "internal.h"
#include "nmplc.h"





int PointInRectangle(RPoint& p, RPoint *borders)
{
	int i;
	double a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, c3, c4;
	double cx, cy;

	cx=0; cy=0;
	for(i=0; i<4; i++)
	{
		cx+=borders[i].x;
		cy+=borders[i].y;
	}
	cx*=0.25;
	cy*=0.25;

	a1=borders[1].y-borders[0].y;
	b1=borders[0].x-borders[1].x;
	c1=borders[1].x*borders[0].y-borders[0].x*borders[1].y;
	a2=borders[3].y-borders[2].y;
	b2=borders[2].x-borders[3].x;
	c2=borders[3].x*borders[2].y-borders[2].x*borders[3].y;
	a3=borders[2].y-borders[1].y;
	b3=borders[1].x-borders[2].x;
	c3=borders[2].x*borders[1].y-borders[1].x*borders[2].y;
	a4=borders[0].y-borders[3].y;
	b4=borders[3].x-borders[0].x;
	c4=borders[0].x*borders[3].y-borders[3].x*borders[0].y;
	if((!a1 && !b1) || (!a2 && !b2) || (!a3 && !b3) || (!a4 && !b4))
		return 0;


	if(((a1*p.x+b1*p.y+c1)*(a1*cx+b1*cy+c1))>=0 && 
		((a2*p.x+b2*p.y+c2)*(a2*cx+b2*cy+c2))>=0 &&
		 ((a3*p.x+b3*p.y+c3)*(a3*cx+b3*cy+c3))>=0 && 
		 ((a4*p.x+b4*p.y+c4)*(a4*cx+b4*cy+c4))>=0)
		return 1;
	else
		return 0;
}



//!
//! \perfinclude _IMG_CreateCellTexture__FPUcii.html
//!

void IMG_CreateCellTexture(unsigned char *texture_img, int width, int height)
{
	VEC_Fill(texture_img, 0, width*height);

	for(int j=0; j<height; j+=50)
		for(int i=0; i<width; i+=50)
			for(int l=0; l<50; l++)
				for(int k=0; k<50; k++) {
					int m1 = (j+l < height-1)? j+l : height-1;
					int m2 = (i+k < width-1)? i+k : width-1;
					VEC_SetVal(texture_img,width*m1+m2,(i+j)%256);
				}

}


//!
//! \perfinclude _IMG_CreateSCL_RandomCellTexture__FPUcii.html
//!

void IMG_CreateRandomCellTexture(unsigned char *texture_img, int width, int height)
{
	VEC_Fill(texture_img, 0, width*height);
	//sSCL_Rand((unsigned)time( NULL ) );
	//time=VEC_SCL_Rand()

	int i, j=0, di, dj;
	while(j<height)
	{
		dj=SCL_Rand(20,59);//%40+20;
		i=0;
		while(i<width)
		{
			di=SCL_Rand(20,59);
			int color=SCL_Rand(0,255);
			for(int l=0; l<dj; l++)
				for(int k=0; k<di; k++) {
					int m1 = (j+l < height-1)? j+l : height-1;
					int m2 = (i+k < width-1)? i+k : width-1;
					VEC_SetVal(texture_img,width*m1+m2,color);
				}
			i+=di;
		}
		j+=dj;
	}

}



//!
//! \perfinclude _IMG_CreateComplexTexture__FPUcii.html
//!

void IMG_CreateComplexTexture(unsigned char *texture_img, int width, int height)
{
	VEC_Fill(texture_img, 0, width*height);
//	sSCL_Rand((unsigned)time( NULL ) );

	int side=width>>2;
	int side2=side>>1;
	int side4=side>>2;
	RPoint border[4];
	int y[4];
	for(int j=0; j<height; j+=side)
		for(int i=0; i<width; i+=side)
		{
			for(int n=0; n<4; n++)
				y[n]=SCL_Rand();
			border[0]=RPoint(SCL_Rand(0,side4-1)+i, y[0]%side4+j);
			border[1]=RPoint(SCL_Rand(0,side4-1)+i, y[1]%side4+j+side2+side4);
			border[2]=RPoint(SCL_Rand(0,side4-1)+i+side2+side4, y[1]%side4+j+side2+side4);
			border[3]=RPoint(SCL_Rand(0,side4-1)+i+side2+side4, y[0]%side4+j);
			int color=100+SCL_Rand()%156;
			for(int l=0; l<side; l++)
				for(int k=0; k<side; k++)
				{
					RPoint kk(i+k, j+l);
					if(PointInRectangle(kk, border))
					{
						int m1 = (j+l < height-1)? j+l : height-1;
						int m2 = (i+k < width-1)? i+k : width-1;
						VEC_SetVal(texture_img,width*m1+m2,color);
					}

				}
		}
}
//}
