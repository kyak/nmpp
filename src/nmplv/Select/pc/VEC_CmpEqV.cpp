    //--------------------------------------------------------------------
#include "nmplv.h"
    //--------------------------------------------------------------------
void VEC_CmpEqV(nm16u15b* pSrcVec1, nm16u15b* pSrcVec2, nm16s* pDstVec, int nSize, int16b shTrueFlag)
{
    for(int i=0; i<nSize; i++)
    {
        if(pSrcVec1[i] == pSrcVec2[i])
        {
            pDstVec[i] = shTrueFlag;       
        }
        else
        {
            pDstVec[i] = 0;
        }
    }
}
    //--------------------------------------------------------------------
void VEC_CmpEqV(nm8u7b* pSrcVec1, nm8u7b* pSrcVec2, nm8s* pDstVec, int nSize, int8b chTrueFlag)
{
    for(int i=0; i<nSize; i++)
    {
        if(pSrcVec1[i] == pSrcVec2[i])
        {
            pDstVec[i] = chTrueFlag;       
        }
        else
        {
            pDstVec[i] = 0;
        }
    }
}
    //--------------------------------------------------------------------