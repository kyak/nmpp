//------------------------------------------------------------------------
//
//  $Workfile:: vSelect.h  $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.2 $      $Date: 2005/07/13 14:19:56 $
//
//	author: S. Mushkaev
//------------------------------------------------------------------------

#ifndef VSELECT_H
#define VSELECT_H


    /**
    \defgroup VEC_MaxVal VEC_MaxVal
    \ingroup vSelect
    \brief
        \ru ����� �������� ������������� �������� �������. 
        \en Search of the maximum vec element value.  
    
		\~
    
	\f[
         nMaxValue  =  \mathop {max}\limits_{i} \left({pSrcVec[i]} \right)
    \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nSize    
        \ru ������  ������� � ���������.  
        \en Vector size in elements. 
		\~
    \retval nMaxValue 
        \ru �������� ������������� ������� �������. 
        \en maximum vec element value. 
		\~
    \return \e void 
    \restr
        \ru ����������� �� ��������� ���������� � �������� ������ �� �������.
        \en Restrictions on parameters are defined in the descriptions of functions.
		\~
    \par
    \xmlonly
        <testperf> 
			<param> pSrcVec   </param> <values> L G 	  </values>
			<param> nMaxValue </param> <values> n 		  </values>
			<param> nSize 	  </param> <values> 10240 </values>
			<init2>	
					VEC_Fill(pSrcVec,0,nSize);
					VEC_SetVal(pSrcVec,nSize-1,1);
			</init2>
        </testperf>
        <testperf> 
			<param> pSrcVec   </param> <values> G 		  </values>
			<param> nMaxValue </param> <values> n 		  </values>
			<param> nSize 	  </param> <values> 8 128 1024 10240 </values>
			<init2>	
					VEC_Fill(pSrcVec,0,nSize);	
					VEC_SetVal(pSrcVec,nSize-1,1);
			</init2>
        </testperf>
    \endxmlonly
    
    */
    //! \{
/**
 \restr
	\ru ���������� ������ ������� ������ ���� ������ ����� �� 32-� 64�. ���� 
	\en Actual size of vec should be divisible by block of 32 64bit words.

		\~
		\ru ������������ � ����������� �������� ������� ������ ��������� �� ����� ��� �� 127. \n
         ������� ���������� ���������� ������� �����:\n
     \en The difference between the maximum and minimum elements of the array should not be more than 127. \n
         Here are some examples of admissible ranges for input numbers: \n
     \~  [00h..7Fh]=[   0..+127]	 
         [FFh..7Eh]=[  -1..+126]	 
	        [C0h..3Fh]=[-64..+63]	   
         [80h..00h]=[-128..0	]	
*/
void VEC_MaxVal(nm8s* pSrcVec, int nSize, int8b& nMaxValue);
/**
\restr
\ru ������������ � ����������� �������� ������� ������ ��������� �� ����� ��� �� 2^15-1. \n
	������� ���������� ���������� ������� �����:\n 
\en The difference between the maximum and minimum elements of the array should not be more than 2^15-1. \n
	Here are some examples of admissible ranges for input numbers: \n
    [0000h..7FFFh]=[     0..+32767	] 
    [FFFFh..7FFEh]=[    -1..+32766	] 
    [C000h..3FFFh]=[-16384..+16383	] 
    [8000h..0000h]=[-32768..0		]     
*/
void VEC_MaxVal(nm16s* pSrcVec, int nSize, int16b& nMaxValue);
/**
\restr
\ru ������������ � ����������� �������� ������� ������ ��������� �� ����� ��� �� 2^31-1. \n
	������� ���������� ���������� ������� �����:\n
\en The difference between the maximum and minimum elements of the array should not be more than 2^31-1. \n
	Here are some examples of admissible ranges for input numbers: \n
\~
    [00000000h..7FFFFFFFh]=[	  0..+2^31-1]   
    [FFFFFFFFh..7FFFFFFEh]=[    -1..+2^31-2	]	
    [C0000000h..3FFFFFFFh]=[ -2^30..+2^30-1	] 
    [80000000h..00000000h]=[ -2^31..0		]     
*/
void VEC_MaxVal(nm32s* pSrcVec, int nSize, int& nMaxValue);
void VEC_MaxVal(nm64s63b *pSrcVec, int nSize, int64b &nMaxValue);

    //! \}

//*****************************************************************************

    /**
    \defgroup VEC_MinVal VEC_MinVal
    \ingroup vSelect
    \brief
        \ru ����� �������� ������������ �������� �������. 
        \en Search of the minimum vec element value.  
    
		\~
    
	\f[
         nMinValue  =  \mathop {min}\limits_{i} \left({pSrcVec[i]} \right)
    \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nSize    
        \ru ������  ������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval nMinValue 
        \ru �������� ������������ �������. 
        \en minimum element value. 
		\~
    \return \e void 
    \restr
        \ru ����������� �� ��������� ���������� � �������� ������ �� �������.
        \en Restrictions on parameters are defined in the descriptions of functions.
		\~
    \par
    \xmlonly
        <testperf> 
			<param> pSrcVec		</param> <values> L G	</values>
			<param> nMinValue	</param> <values> n	</values>
			<param> nSize		</param> <values> 10240 </values>
			<init2>	
					VEC_Fill(pSrcVec,0,nSize);		
					VEC_SetVal(pSrcVec,nSize-1,-1); 
			</init2>
        </testperf>
        <testperf> 
			<param> pSrcVec		</param> <values> G		</values>
			<param> nMinValue	</param> <values> n	</values>
			<param> nSize		</param> <values> 8 128 1024 10240 </values>
			<init2>
					VEC_Fill(pSrcVec,0,nSize);		
					VEC_SetVal(pSrcVec,nSize-1,-1); 
			</init2>
        </testperf>
    \endxmlonly
    
    */
    //! \{
/**
\restr
	\ru ���������� ������ ������� ������ ���� ������ ����� �� 32-� 64�. ���� 
	\en Actual size of vec should be divisible by block of 32 64bit words.

		\~
    \ru ������������ � ����������� �������� ������� ������ ��������� �� ����� ��� �� 127. \n
        ������� ���������� ���������� ������� �����:\n
    \en The difference between the maximum and minimum elements of the array should not be more than 127. \n
        Here are some examples of admissible ranges for input numbers: \n
    \~    
        [00h..7Fh]=[   0..+127]	
        [FFh..7Eh]=[  -1..+126]	
        [C0h..3Fh]=[-64..+63]	  
        [80h..00h]=[-128..0	]	  
*/
void VEC_MinVal(nm8s* pSrcVec, int nSize, int8b& nMinValue);
/**
\restr
    \ru ������������ � ����������� �������� ������� ������ ��������� �� ����� ��� �� 2^15-1. \n
        ������� ���������� ���������� ������� �����:\n
    \en The difference between the maximum and minimum elements of the array should not be more than 2^15-1. \n
        Here are some examples of admissible ranges for input numbers: \n
    \~  [0000h..7FFFh]=[     0..+32767	] 
        [FFFFh..7FFEh]=[    -1..+32766	] 
        [C000h..3FFFh]=[-16384..+16383	] 
        [8000h..0000h]=[-32768..0		]     
*/
void VEC_MinVal(nm16s* pSrcVec, int nSize, int16b& nMinValue);
/**
\restr
    \ru ������������ � ����������� �������� ������� ������ ��������� �� ����� ��� �� 2^31-1. \n
        ������� ���������� ���������� ������� �����:\n
    \en The difference between the maximum and minimum elements of the array should not be more than 2^31-1. \n
        Here are some examples of admissible ranges for input numbers: \n
    \~  [00000000h..7FFFFFFFh]=[	  0..+2^31-1]   
        [FFFFFFFFh..7FFFFFFEh]=[    -1..+2^31-2	]	
        [C0000000h..3FFFFFFFh]=[ -2^30..+2^30-1	] 
        [80000000h..00000000h]=[ -2^31..0		]     
*/
void VEC_MinVal(nm32s* pSrcVec, int nSize, int& nMinValue);
    //! \}

//*****************************************************************************

    /**
    \defgroup VEC_MaxPos VEC_MaxPos
    \ingroup vSelect
    \brief
        \ru ����� �������� ������������� �������� ������� 
               �  ��� ��������� (���������) � �������. 
        \en Search of the maximum vec element value and its position(s) in the vec  
    
		\~
    
	\f[
         nMaxValue  =  \mathop {max} \limits_{i} \left(pSrcVec[i] \right)
    \f]
    
    \param pSrcVec      
        \ru ������� ������. 
        \en Input vec.   
		\~
    \param nSize        
        \ru ������ ������� � ���������. ���������� ���� �������� ����� ������ ������ ���� ������ 64 ������� ������ (nm64s[64,128,...]). 
        \en Size of vec in elements. Size of allocated memory in 64-bit words must be divisible by 64 (nm64s[64,128,...])
		\~
    \param pLTmpBuf      
        \ru ��������� ������ �� ��������� ����  �� nSize ���������.
        \en Temporary array on Local bus  of nSize elements. 
		\~
	\param pGTmpBuf      
        \ru ��������� ������ �� ���������� ���� . 
        \en Temporary array on Global bus. 
		\~
    \param nSearchDir   
        \ru ����������� ������ ���������. \n
            ��� nSearchDir = 1, ����� ������� �� ������ �������.\n
            ��� nSearchDir = -1, ����� ������� �� ����� �������.\n
        \en The maximum search direction. \n
    	    When nSearchDir = 1, the search starts from the beginning of the array.\n
            When nSearchDir = -1, the search starts from the end of the array.\n
    \retval nMaxValue   
        \ru �������� ������������� ��������. 
        \en Value of the maximum element 
		\~
    \retval nIndex   
        \ru ������ ������� ���������� ��������� ����� ������. 
        \en Index of the first found maximum among equals. 
		\~
    \return \e void	
    \restr
        \ru ����������� �� ��������� ���������� � �������� ������ �� �������.
        \en Restrictions on parameters are defined in the descriptions of functions.
		\~
	\restr 
		\ru ��������� ������� ��������� ����� ���� "����������"  \n
			�������� ��� ������ nm16s15b ������������ � ����������� �������� ������� ������ ��������� �� ����� ��� �� 2^15-1.
            ������� ���������� ���������� ������� ����� ��� ���� nm16s15b :
       \en The range of input data may be floating \n
			For example: if nm16s15b type is used the difference between the maximum and minimum elements of the array should not be more than 2^15-1.
		\~
			Here are some examples of admissible ranges for input numbers: \n 
       \~  [0000h..7FFFh]=[     0..+32767	] 
           [FFFFh..7FFEh]=[    -1..+32766	] 
           [C000h..3FFFh]=[-16384..+16383	] 
           [8000h..0000h]=[-32768..0		]   
    \par
	\xmlonly
		<testperf> 
			<param> pSrcVec		</param> <values> L G	</values>
			<param> pLTmpBuf	</param> <values> L		</values>
			<param> pGTmpBuf	</param> <values> G		</values>
			<param> nMaxValue	</param> <values> n	</values>
			<param> nIndex		</param> <values> n	</values>
			<param> nSearchDir	</param> <values> 1 -1	</values>
			<param> nSize		</param> <values> 64 1024 10240 </values>
			<init2>	
					VEC_Fill(pSrcVec,0,nSize);		
					VEC_SetVal(pSrcVec,nSize-1,1);	
			</init2>
		</testperf>
    \endxmlonly
	*/
    //! \{
void VEC_MaxPos (nm8s7b  *pSrcVec, int nSize, int& nIndex, int8b &nMaxValue, void *pLTmpBuf,void *pGTmpBuf, int nSearchDir=1);
void VEC_MaxPos (nm16s15b *pSrcVec, int nSize, int& nIndex, int16b &nMaxValue, void *pLTmpBuf,void *pGTmpBuf, int nSearchDir=1);
void VEC_MaxPos (nm32s31b *pSrcVec, int nSize, int& nIndex, int32b &nMaxValue, void *pLTmpBuf,void *pGTmpBuf, int nSearchDir=1);
    //! \}


//*****************************************************************************

    /**
    \defgroup VEC_MinPos VEC_MinPos
    \ingroup vSelect
    \brief
        \ru ����� �������� ������������ �������� ������� 
               �  ��� ��������� (���������) � �������. 
        \en Search of the minimum vec element value and its position(s) in the vec  
    
		\~
    
	\f[
         nMinValue  =  \mathop {min} \limits_{i} \left(pSrcVec[i] \right)
    \f]
    
    \param pSrcVec      
        \ru ������� ������. 
        \en Input vec.   
		\~
    \param nSize        
        \ru ������ ������� � ���������. ���������� ���� �������� ����� ������ ������ ���� ������ 64 ������� ������ (nm64s[64,128,...]). 
        \en Size of vec in elements. Size of allocated memory in 64-bit words must be divisible by 64 (nm64s[64,128,...])
		\~
    \param pLTmpBuf      
        \ru ��������� ������ �� ��������� ���� . 
        \en Temporary array on Local bus. 
		\~
	\param pGTmpBuf      
        \ru ��������� ������ �� ���������� ����  �� nSize ���������. 
        \en Temporary array on Global bus of  nSize elements. 
		\~
    \param nSearchDir   
        \ru ����������� ������ ��������. \n
            ��� nSearchDir = 1, ����� ������� �� ������ �������.\n
            ��� nSearchDir = -1, ����� ������� �� ����� �������.\n
        \en The minimum search direction. \n
    	    When nSearchDir = 1, the search starts from the beginning of the array.\n
            When nSearchDir = -1, the search starts from the end of the array.\n
    \retval nMinValue   
        \ru �������� ������������ ��������. 
        \en Value of the minimum element 
		\~
    \retval nIndex   
        \ru ������ ������� ���������� �������� ����� ������. 
        \en Index of the first found minimum among equals. 
		\~
    \return \e void	
    \restr
        \ru ����������� �� ��������� ���������� � �������� ������ �� �������.
        \en Restrictions on parameters are defined in the descriptions of functions.
		\~
	\restr 
		\ru ��������� ������� ��������� ����� ���� "����������"  \n
			�������� ��� ������ nm16s15b ������������ � ����������� �������� ������� ������ ��������� �� ����� ��� �� 2^15-1.
            ������� ���������� ���������� ������� ����� ��� ���� nm16s15b :
       \en The range of input data may be floating \n
			For example: if nm16s15b type is used the difference between the maximum and minimum elements of the array should not be more than 2^15-1.
		\~
			Here are some examples of admissible ranges for input numbers: \n 
       \~  [0000h..7FFFh]=[     0..+32767	] 
           [FFFFh..7FFEh]=[    -1..+32766	] 
           [C000h..3FFFh]=[-16384..+16383	] 
           [8000h..0000h]=[-32768..0		]   
    \par
	\xmlonly
		<testperf> 
			<param> pSrcVec		</param> <values> L G	</values>
			<param> pLTmpBuf	</param> <values> L		</values>
			<param> pGTmpBuf	</param> <values> G		</values>
			<param> nMinValue	</param> <values> n	</values>
			<param> nIndex		</param> <values> n	</values>
			<param> nSearchDir	</param> <values> 1 -1	</values>
			<param> nSize		</param> <values> 64 1024 10240 </values>
			<init2>	
					VEC_Fill(pSrcVec,0,nSize);		
					VEC_SetVal(pSrcVec,nSize-1,-1);	
			</init2>
		</testperf>
	\endxmlonly
	*/
    //! \{
void VEC_MinPos (nm8s7b   *pSrcVec, int nSize, int& nIndex, int8b &nMinValue, void *pLTmpBuf,void *pGTmpBuf, int nSearchDir=1);
void VEC_MinPos (nm16s15b *pSrcVec, int nSize, int& nIndex, int16b &nMinValue, void *pLTmpBuf,void *pGTmpBuf, int nSearchDir=1);
void VEC_MinPos (nm32s31b *pSrcVec, int nSize, int& nIndex, int32b &nMinValue, void *pLTmpBuf,void *pGTmpBuf, int nSearchDir=1);
    //! \}


//*****************************************************************************

    /**
    \defgroup VEC_MinPosVN VEC_MinPosVN
    \ingroup vSelect
	\brief 
        \ru ����� �������� ������������ �������� �������  ����� N � ��� ��������� � �������. 
        \en Search of the minimum vec element value and its position in the vec  with size of N elements
		
		\~
	\param pSrcVec 
	    \ru ������ �� N ���������, ��� N ������������ ������ � ����� �������. 
        \en array of N numbers, where N is suffix in function name
		\~
	\param nStride
	    \ru ��� ����� ���������� � 32�. ������ 
        \en jump between numbers in nm32s words
		\~
	\retval
		\ru ������ ������� ���������� ��������.
		\en Index of the first found minimum. 
		\~
	\return 
	    \ru �������� ������������ ��������. 
        \en Value of the minimum element 

		\~
	\par
	\xmlonly
		<testperf> 
			 <param> pSrcVec </param> <values> L G  </values>
			 <param> nStride </param> <values> 2    </values>
			 <param> nPos    </param> <values> n	</values>
			 <size>  1 </size>
		</testperf>
	\endxmlonly
	\restr
		\ru ���������� ����������� �� ��������� ����, ������� ��������� �� ������ pSrcVec ����� ��������� �� �������� �����.
		\en Calculation is performed on scalar RISC core, therefore pointer pSrcVec may refer to odd address.
		\~
	*/

	//! \{
int VEC_MinPosV9(int* pSrcVec,int nStride,int& nPos);
int VEC_MinPosV16(int* pSrcVec,int nStride,int& nPos);
int VEC_MinPosV25(int* pSrcVec,int nStride,int& nPos);
int VEC_MinPosV256(int* pSrcVec,int nStride,int& nPos);
int VEC_MinPosV1024(int* pSrcVec,int nStride,int& nPos);
	//! \}

//*****************************************************************************

    /**
    \defgroup VEC_FirstZeroPos VEC_FirstZeroPos
    \ingroup vSelect
	\brief 
        \ru ����� ������� ������� �������� �������� � ������� . 
        \en Search of first zero element position in the vec 
		
		\~
	\param pSrcVec 
	    \ru ������� ������. 
        \en Input array
		\~
	\param nIndex
	    \ru ������ �������. 
        \en Array size
		\~
	\return 
	    \ru ������� �������� �������� ��� -1 � ������ ���� ������� ������� �� ������ 
        \en Position of zero element or -1 if zero element was not found. 
		\~
	\restr
		\ru ���������� ����������� �� ��������� ����, ������� ��������� �� ������ pSrcVec ����� ��������� �� �������� �����.
			����� ������������ �� ������� �������� ��������.
		\en Calculation is performed on scalar RISC core, therefore pointer pSrcVec may refer to odd address.
			Search is performed until first zero element is found.

		\~
	\par
	\xmlonly
		<testperf> 
			 <param> pSrcVec </param> <values> L G  </values>
			 <param> nSize   </param> <values> 8 64 512 </values>
			 <init2>  VEC_Fill(pSrcVec,1,nSize); </init2>
		</testperf>
	\endxmlonly
	*/
	//! \{
int VEC_FirstZeroPos(int* pSrcVec, int nSize);
	//! \}
//*****************************************************************************

    /**
    \defgroup VEC_FirstNonZeroPos VEC_FirstNonZeroPos
    \ingroup vSelect
	\brief 
        \ru ����� ������� ������� ���������� �������� � ������� . 
        \en Search of first nonzero element position in the vec 
		
		\~
	\param pSrcVec 
	    \ru ������� ������. 
        \en Input array
		\~
	\param nIndex
	    \ru ������ �������. 
        \en Array size
		\~
	\return 
	    \ru ������� ���������� �������� ��� -1 � ������ ���� ��������� ������� �� ������ 
        \en Position of nonzero element or -1 if zero element was not found. 
		\~
	\restr
		\ru ���������� ����������� �� ��������� ����, ������� ��������� �� ������ pSrcVec ����� ��������� �� �������� �����.
			����� ������������ �� ������� ���������� ��������.
		\en Calculation is performed on scalar RISC core, therefore pointer pSrcVec may refer to odd address.
			Search is performed until first nonzero element is found.

		\~
	\par
	\xmlonly
		<testperf> 
			 <param> pSrcVec </param> <values> L G  </values>
			 <param> nSize   </param> <values> 8 64 512 </values>
			 <init2> VEC_Fill(pSrcVec,0,nSize); </init2>
		</testperf>
	\endxmlonly
	*/
	//! \{
int VEC_FirstNonZeroPos(int* pSrcVec, int nSize);
	//! \}

//*****************************************************************************

    /**
    \defgroup VEC_LastZeroPos VEC_LastZeroPos
    \ingroup vSelect
	\brief 
        \ru ����� ������� ���������� �������� �������� � ������� . 
        \en Search of last zero element position in the vec 
		
		\~
	\param pSrcVec 
	    \ru ������� ������. 
        \en Input array
		\~
	\param nIndex
	    \ru ������ �������. 
        \en Array size
		\~
	\return 
	    \ru ������� �������� �������� ��� -1 � ������ ���� ������� ������� �� ������ 
        \en Position of zero element or -1 if zero element was not found. 

		\~
	\restr
		\ru ���������� ����������� �� ��������� ����, ������� ��������� �� ������ pSrcVec ����� ��������� �� �������� �����.
			����� ������������ � ����� �� ������� �������� ��������.
		\en Calculation is performed on scalar RISC core, therefore pointer pSrcVec may refer to odd address.
			Search is performed from end to start until first zero element is found.
		\~
	\par
	\xmlonly
		<testperf> 
			 <param> pSrcVec </param> <values> L G  </values>
			 <param> nSize   </param> <values> 8 64 512 </values>
			 <init2> VEC_Fill(pSrcVec,1,nSize); </init2>
		</testperf>
	\endxmlonly
	*/
	//! \{
int VEC_LastZeroPos(int* pSrcVec, int nSize);
	//! \}

//*****************************************************************************

    /**
    \defgroup VEC_LastNonZeroPos VEC_LastNonZeroPos
    \ingroup vSelect
	\brief 
        \ru ����� ������� ���������� ���������� �������� � ������� . 
        \en Search of last nonzero element position in the vec 
		
		\~
	\param pSrcVec 
	    \ru ������� ������. 
        \en Input array
		\~
	\param nIndex
	    \ru ������ �������. 
        \en Array size
		\~
	\return 
	    \ru ������� �������� �������� ��� -1 � ������ ���� ������� ������� �� ������ 
        \en Position of zero element or -1 if zero element was not found. 

		\~
	\restr
		\ru ���������� ����������� �� ��������� ����, ������� ��������� �� ������ pSrcVec ����� ��������� �� �������� �����.
			����� ������������ � ����� �� ������� ���������� ��������.
		\en Calculation is performed on scalar RISC core, therefore pointer pSrcVec may refer to odd address.
			Search is performed from end to start until first nonzero element is found.
		\~
	\par
	\xmlonly
		<testperf> 
			 <param> pSrcVec </param> <values> L G  </values>
			 <param> nSize   </param> <values> 8 64 512 </values>
			 <init2> VEC_Fill(pSrcVec,0,nSize); </init2>

		</testperf>
	\endxmlonly
	
	*/
	//! \{
int VEC_LastNonZeroPos(int* pSrcVec, int nSize);
	//! \}


//*****************************************************************************
    /**
    \defgroup VEC_MinV VEC_MinV
    \ingroup vSelect
    \brief
        \ru ������������ ������� �� ���� ��������. 
        \en Generation of the vec of two vectors elementwise minima. 
    
		\~
    
	\f[ pDstMinVec[i] = \min (pSrcVec1[i], pSrcVec2[i]) \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstMinVec
        \ru ������ ������������ ��������� ��� ������� ��������. 
        \en The array of elementwise minima for source arrays. 
		\~
    \return \e void 
    
    \restr 
        \ru ������������ ���� ����� ���� �������� ������ ��������� �� ����� ��� �� \f$ 2^{15}-1 \f$. \n
                  ������� ���������� ���������� ������������ ��� �����:\n
        \en The difference between the comparable pairs of numbers in two arrays 
		\~
               should not be more than \f$ 2^{15}-1 \f$. \n
               Here are some examples of admissible ranges for comparable pairs of numbers: \n  
        \~     [0000h..7FFFh]=[     0..+32767	]     \n
               [FFFFh..7FFEh]=[    -1..+32766	]     \n
               [C000h..3FFFh]=[-16384..+16383	]     \n
               [8000h..0000h]=[-32768..0		]
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstMinVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> pSrcVec2 </param> <values> L </values>
             <param> pDstMinVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void VEC_MinV(nm8s7b*   pSrcVec1, nm8s7b*   pSrcVec2, nm8s7b*   pDstMinVec, int nSize);
void VEC_MinV(nm16s15b* pSrcVec1, nm16s15b* pSrcVec2, nm16s15b* pDstMinVec, int nSize);
void VEC_MinV(nm32s31b* pSrcVec1, nm32s31b* pSrcVec2, nm32s31b* pDstMinVec, int nSize);
void VEC_MinV(nm64s63b* pSrcVec1, nm64s63b* pSrcVec2, nm64s63b* pDstMinVec, int nSize);

    //! \}
//*****************************************************************************
// numVecs > 2
void VEC_MinNV(nm8s7b**   pSrcVecs, int numVecs, nm8s7b*   pDstMinVec, int nSize);
void VEC_MinNV(nm16s15b** pSrcVecs, int numVecs, nm16s15b* pDstMinVec, int nSize);
void VEC_MinNV(nm32s31b** pSrcVecs, int numVecs, nm32s31b* pDstMinVec, int nSize);
void VEC_MinNV(nm64s63b** pSrcVecs, int numVecs, nm64s63b* pDstMinVec, int nSize);

//*****************************************************************************

    /**
    \defgroup VEC_MaxV VEC_MaxV
    \ingroup vSelect
    \brief
        \ru ������������ �������� �� ���� ��������. 
        \en Generation of the vec of two vectors elementwise minimum. 
    
		\~
    
	\f[ pDstMaxVec[i] = \max (pSrcVec1[i], pSrcVec2[i]) \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstMaxVec 
        \ru ������ ������������ ��������� ��� ������� ��������. 
        \en The array of elementwise Maxima for source arrays. 
		\~
    \return \e void 
    
    \restr 
        \ru ������������ ���� ����� ���� �������� ������ ��������� �� ����� ��� �� \f$ 2^{15}-1 \f$. \n
                  ������� ���������� ���������� ������������ ��� �����:\n
        \en The difference between the comparable pairs of numbers in two arrays 
		\~
               should not be more than \f$ 2^{15}-1 \f$. \n
               Here are some examples of admissible ranges for comparable pairs of numbers: \n  
        \~     [0000h..7FFFh]=[     0..+32767	]     \n
               [FFFFh..7FFEh]=[    -1..+32766	]     \n
               [C000h..3FFFh]=[-16384..+16383	]     \n
               [8000h..0000h]=[-32768..0		]
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1		</param> <values> L G </values>
             <param> pSrcVec2		</param> <values> L G </values>
             <param> pDstMaxVec		</param> <values> L G </values>
             <param> pDstSignMask	</param> <values> L G </values>
             <param> nSize			</param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1		</param> <values> L </values>
             <param> pSrcVec2		</param> <values> L </values>
             <param> pDstMaxVec		</param> <values> G </values>
             <param> pDstSignMask	</param> <values> G </values>
             <param> nSize			</param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void VEC_MaxV(nm8s7b*   pSrcVec1, nm8s7b* pSrcVec2,   nm8s7b*  pDstMaxVec,  int nSize);
void VEC_MaxV(nm16s15b* pSrcVec1, nm16s15b* pSrcVec2, nm16s15b* pDstMaxVec, int nSize);
void VEC_MaxV(nm32s31b* pSrcVec1, nm32s31b* pSrcVec2, nm32s31b* pDstMaxVec, int nSize);
void VEC_MaxV(nm64s63b* pSrcVec1, nm64s63b* pSrcVec2, nm64s63b* pDstMaxVec, int nSize);

    //! \}

//*****************************************************************************

    /**
    \defgroup VEC_MinCmpLtV VEC_MinCmpLtV
    \ingroup vSelect
    \brief
        \ru ������������ ������� �� ���� ��������. 
        \en Generation of the vec of two vectors elementwise minima. 
    
		\~
    
	\f[ pDstMin[i] = \min (pSrcVec1[i], pSrcVec2[i]) \f]
    
	\f[ 
        pDstSignMask[i] = \left\{
            \begin{array}{ll}
                11 \ldots 1b,  & pSrcVec1[i] < pSrcVec2[i] \\
                00 \ldots 0b,  & pSrcVec1[i] <= pSrcVec2[i] \\
            \end{array}
        \right.
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstMin 
        \ru ������ ������������ ��������� ��� ������� ��������. 
        \en The array of elementwise minima for source arrays. 
		\~
    \retval pDstSignMask 
        \ru ������ ������ ������������ ��������� 
                             ������� � ������� ��������. 
        \en The array of signed elementwise differences of the first and the second vectors. 
		\~
    \return \e void 
    
    \restr 
        \ru ������������ ���� ����� ���� �������� ������ ��������� �� ����� ��� �� \f$ 2^{15}-1 \f$. \n
                  ������� ���������� ���������� ������������ ��� �����:\n
        \en The difference between the comparable pairs of numbers in two arrays 
		\~
               should not be more than \f$ 2^{15}-1 \f$. \n
               Here are some examples of admissible ranges for comparable pairs of numbers: \n  
        \~     [0000h..7FFFh]=[     0..+32767	]     \n
               [FFFFh..7FFEh]=[    -1..+32766	]     \n
               [C000h..3FFFh]=[-16384..+16383	]     \n
               [8000h..0000h]=[-32768..0		]
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1		</param> <values> L G </values>
             <param> pSrcVec2		</param> <values> L G </values>
             <param> pDstMin		</param> <values> L G </values>
             <param> pDstSignMask	</param> <values> L G </values>
             <param> nSize			</param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1		</param> <values> L </values>
             <param> pSrcVec2		</param> <values> L </values>
             <param> pDstMin		</param> <values> G </values>
             <param> pDstSignMask	</param> <values> G </values>
             <param> nSize			</param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void VEC_MinCmpLtV(nm16s15b* pSrcVec1, nm16s15b* pSrcVec2, nm16s15b* pDstMin, nm16s15b* pDstSignMask, int nSize);
    //! \}


//*****************************************************************************

    /**
    \defgroup VEC_CmpLt0 VEC_CmpLt0
    \ingroup vSelect
    \brief
        \ru ���������� �������� ������� �� ������ ����. 
        \en Compares the array elements less zero.  
    
		\~
    
	\f[
     pDstVec(i)  =  \{ \begin{array}{*{20}c}
        11 \ldots 1b,   &  if &  pSrcVec(i) < 0  \\
        00 \ldots 0b,   &  if &  pSrcVec(i) \ge 0  \\
     \end{array}
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \ru ���� ������� �������� ������� ������ 0, �� ��� ���� 
        ���������������� �������� ��������� ������� ������������ 1. 
    \en If an element of the input vec is less than zero then 
        1 is beeing written to all bits of output vec element. 

		\~
		\~
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 

		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 

		\~
    \return \e void 
    

    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec	</param> <values> L G </values>
             <param> pDstVec	</param> <values> L G </values>
             <param> nSize		</param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec	</param> <values> L </values>
             <param> pDstVec	</param> <values> G </values>
             <param> nSize		</param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void VEC_CmpLt0(nm8s* pSrcVec,  nm8s* pDstVec,  int nSize);
void VEC_CmpLt0(nm16s* pSrcVec, nm16s* pDstVec, int nSize);
void VEC_CmpLt0(nm32s* pSrcVec, nm32s* pDstVec, int nSize);
void VEC_CmpLt0(nm64s* pSrcVec, nm64s* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup VEC_CmpEq0 VEC_CmpEq0
    \ingroup vSelect
    \brief
        \ru ���������� �������� ������� �� ������� ��������� ����. 
        \en Compare vec elements to zero equlity. 
    
		\~
    
	\f[
        pDstVec(i)  =  \{ \begin{array}{*{20}c}
            1,    &  if &  pSrcVec(i) = 0  \\
            0,    &  if &  pSrcVec(i) \neq 0\\
        \end{array}, if~ nTrueFlag=1
    \f]
	
	\f[
        pDstVec(i)  =  \{ \begin{array}{*{20}c}
            0,    &  if &  pSrcVec(i) = 0  \\
            1,    &  if &  pSrcVec(i) \neq 0\\
        \end{array}, if~ nTrueFlag=0
    \f]

    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
  
		\~
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nSize     \ru ������ �������� � ���������. 
                     \ru Vector size in elements. 
    \param nTrueFlag \ru ������� ��� nTrueFlag ���������� �������� ��������� ���� ��� ���������� �������.
                     \en Lowest  bit of nTrueFlag is set in result bit if condition is true. 

		\~
    \retval pDstVec 
        \ru �������������� �������� ������. 
        \en Destination binary vec. 

		\~
    \return \e void 
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec	</param> <values> L G </values>
             <param> pDstVec	</param> <values> L G </values>
             <param> nTrueFlag	</param> <values> -1 </values>
             <param> nSize		</param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec	</param> <values> L </values>
             <param> pDstVec	</param> <values> G </values>
             <param> nTrueFlag	</param> <values> 0 -1 </values>
             <param> nSize		</param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec	</param> <values> L </values>
             <param> pDstVec	</param> <values> G </values>
             <param> nTrueFlag	</param> <values> -1 </values>
             <param> nSize		</param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
/**
	\note nSize =[1,2,3,4...]
*/
void VEC_CmpEq0(nm8u7b* pSrcVec, nm1* pDstVec, int nSize, int nTrueFlag);
/**
	\note nSize =[1,2,3,4...]
*/
void VEC_CmpEq0(nm16u15b* pSrcVec, nm1* pDstVec, int nSize, int nTrueFlag);
/**
	\note nSize =[1,2,3,4...]
*/
void VEC_CmpEq0(nm32u31b* pSrcVec, nm1* pDstVec, int nSize, int nTrueFlag);
    //! \}

    /**
    \defgroup VEC_CmpMinMaxV VEC_CmpMinMaxV
    \ingroup vSelect
	
    \brief
        \ru ������������ ��������� ���� ��������. 
        \en Elementwise comparision of two vectors. 
    
		\~
    
	\f[ pDstMin[i] = \min (pSrcVec1[i], pSrcVec2[i]) \f]
	
	\f[ pDstMax[i] = \max (pSrcVec1[i], pSrcVec2[i]) \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vectors size in elements. 
		\~
    \retval pDstMin
        \ru ������ ������������ ��������� ��� ������� ��������. 
        \en The array of elementwise minimums for source arrays. 
		\~
    \retval pDstMax
        \ru ������ ������������ ���������� ��� ������� ��������. 
        \en The array of elementwise maximums for source arrays. 
		\~
    \return \e void 
    
    \restr 
        \ru ������������ ���� ����� ���� �������� ������ ��������� �� ����� ��� �� \f$ 2^{15}-1 \f$. \n
                  ������� ���������� ���������� ������������ ��� �����:\n
        \en The difference between the comparable pairs of numbers in two arrays 
		\~
               should not be more than \f$ 2^{15}-1 \f$. \n
               Here are some examples of admissible ranges for comparable pairs of numbers: \n  
        \~     [0000h..7FFFh]=[     0..+32767	]     \n
               [FFFFh..7FFEh]=[    -1..+32766	]     \n
               [C000h..3FFFh]=[-16384..+16383	]     \n
               [8000h..0000h]=[-32768..0		]

    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1	</param> <values> L G </values>
             <param> pSrcVec2	</param> <values> L G </values>
             <param> pDstMin	</param> <values> L G </values>
             <param> pDstMax	</param> <values> L G </values>
             <param> nSize		</param> <values> 10240 </values>
        </testperf>
    \endxmlonly


		*/
    //! \{
void VEC_CmpMinMaxV(nm8s*  pSrcVec1, nm8s* pSrcVec2,  nm8s*  pDstMin,  nm8s*  pDstMax, int nSize);
void VEC_CmpMinMaxV(nm16s*  pSrcVec1, nm16s* pSrcVec2,  nm16s*  pDstMin,  nm16s*  pDstMax, int nSize);
void VEC_CmpMinMaxV(nm32s*  pSrcVec1, nm32s* pSrcVec2,  nm32s*  pDstMin,  nm32s*  pDstMax, int nSize);
    //! \}


//*****************************************************************************

    /**
    \defgroup VEC_ClipPowC VEC_ClipPowC
    \ingroup vSelect
    \brief
        \ru ������� ���������. 
        \en Saturation function. 
    
		\~
    
	\f[
        pDstVec[i]  =  \left \{ \begin{array}{*{20}l}
            -2^{nClipFactor},  & if & pSrcVec[i] < -2^{nClipFactor}  \\    
            pSrcVec[i],        & if & -2^{nClipFactor} \le pSrcVec[i] \le 2^{nClipFactor}-1  \\
            2^{nClipFactor}-1, & if & pSrcVec[i] > 2^{nClipFactor}-1 \\
        \end{array} \right.
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nClipFactor 
        \ru ���������� �������, ������������ ������� � ������ ������ ���������. 
        \en Index of the degree defining the upper and the lower saturation thresholds. 
		\~
    \param nSize    
        \ru ������ ������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nClipFactor </param> <values> 2 </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
             <param> nClipFactor </param> <values> 2 3 5 </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
             <param> nClipFactor </param> <values> 2 </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void VEC_ClipPowC(nm8s*  pSrcVec, int nClipFactor, nm8s*  pDstVec, int nSize);
void VEC_ClipPowC(nm16s* pSrcVec, int nClipFactor, nm16s* pDstVec, int nSize);
void VEC_ClipPowC(nm32s* pSrcVec, int nClipFactor, nm32s* pDstVec, int nSize);
void VEC_ClipPowC(nm64s* pSrcVec, int nClipFactor, nm64s* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup VEC_ClipCC VEC_ClipCC
    \ingroup vSelect
    \brief
        \ru ������� ��������� � ������������� ��������. 
        \en Saturation function with arbitrary thresholds. 
    
		\~
    
	\f[
        pDstVec[i]  =  \left \{ \begin{array}{*{20}l}
            nPosThresh,   & if & pSrcVec[i] > nPosThresh \\
            pSrcVec[i],   & if & nNegThresh \le pSrcVec[i] \le nPosThresh  \\
            nNegThresh,   & if & pSrcVec[i] < nNegThresh  \\    
        \end{array} \right.
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec      
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nNegThresh   
        \ru ������ ����� ���������. 
        \en The lower saturation threshold. 
		\~
    \param nPosThresh   
        \ru ������� ����� ���������. 
        \en The upper saturation threshold. 
		\~
    \param nSize        
        \ru ������ ������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec     
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
    \restr
        \ru
            - �������� ��������� ��� \f$ nPosThresh \subset [0 \ldots 2^{30}-1] \f$. 
            - �������� ��������� ��� \f$ nNegThresh \subset [-2^{30} \ldots 0] \f$. \n 
        \en
            - Range of changing for \f$ nPosThresh \subset [0 \ldots 2^{30}-1] \f$. 
            - Range of changing for \f$ nNegThresh \subset [-2^{30} \ldots 0] \f$. \n 
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec	</param> <values> L G </values>
             <param> pDstVec	</param> <values> L G </values>
             <param> nNegThresh </param> <values> -127 </values>
             <param> nPosThresh </param> <values> 127 </values>
             <param> nSize		</param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec	</param> <values> L </values>
             <param> pDstVec	</param> <values> G </values>
             <param> nNegThresh </param> <values> -255 -127 </values>
             <param> nPosThresh </param> <values> 127 255 </values>
             <param> nSize		</param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec	</param> <values> L </values>
             <param> pDstVec	</param> <values> G </values>
             <param> nNegThresh </param> <values> -127 </values>
             <param> nPosThresh </param> <values> 127 </values>
             <param> nSize		</param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void VEC_ClipCC(nm32s30b* pSrcVec, int30b nNegThresh, int30b nPosThresh, nm32s30b* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup VEC_ClipArshCnv_AddC VEC_ClipArshCnv_AddC
    \ingroup vSelect
    \brief
        \ru ���������� ����������� ������ c ��������������� �� ����������. 
        \en Data word-length reduction with their preprocessing. 
	
		\~
    
	\f[
	    pDstVec[i] = Convert(Clip(pSrcVec[i],nClipFactor) >> nShift) + nAddValue
	\f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
	  \ru ���������� ����������� ������ ����������� ����� ��������������� ��������� � �������������� 
	    ����� ������������ ������� �����.  
	  \en Data word-length is reduced after preprocessing and is made by means of the most significant bits truncation. 

		\~
		\~
    \param pSrcVec    
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nClipFactor 
        \ru ���������� �������, ������������ ������� � ������ ������ ���������. =[1,2,3...15] 
        \en Index of the degree defining the upper and the lower saturation thresholds. =[1,2,3...15] 
		\~
    \param nShift      
        \ru �������� ���������� �� ������� ������� =[2,4,6...14] �����
                           �������� ���� ��������� �������; 
        \en This parameter defines for how many positions =[2,4,6...14] vec elements should be shifted 
		\~
    \param nAddValue   
        \ru ����������� ���������. 
        \en Additive constant. 
		\~
    \param nSize      
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 

		\~
    \retval pDstVec   
        \ru �������������� ������. 
        \en The result vec. 

		\~
    \return \e void 
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec	</param> <values> L G </values>
             <param> pDstVec	</param> <values> L G </values>
             <param> nClipFactor</param> <values> 4 </values>
             <param> nShift		</param> <values> 2 </values>
             <param> nAddValue	</param> <values> 127 </values>
             <param> nSize		</param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec	</param> <values> L </values>
             <param> pDstVec	</param> <values> G </values>
             <param> nClipFactor</param> <values> 1 4 15 </values>
             <param> nShift		</param> <values> 2 </values>
             <param> nAddValue	</param> <values> 127 </values>
             <param> nSize		</param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec	</param> <values> L </values>
             <param> pDstVec	</param> <values> G </values>
             <param> nClipFactor</param> <values> 4 </values>
             <param> nShift		</param> <values> 2 4 6 </values>
             <param> nAddValue	</param> <values> 127 </values>
             <param> nSize		</param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec	</param> <values> L </values>
             <param> pDstVec	</param> <values> G </values>
             <param> nClipFactor</param> <values> 4 </values>
             <param> nShift		</param> <values> 2 </values>
             <param> nAddValue	</param> <values> 0 64 127 </values>
             <param> nSize		</param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec	</param> <values> L </values>
             <param> pDstVec	</param> <values> G </values>
             <param> nClipFactor</param> <values> 4 </values>
             <param> nShift		</param> <values> 2 </values>
             <param> nAddValue	</param> <values> 127 </values>
             <param> nSize		</param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void VEC_ClipArshCnv_AddC(nm16s* pSrcVec, int nClipFactor,int nShift, int8b nAddValue,nm8s* pDstVec, int nSize);
void VEC_ClipArshCnv_AddC(nm32s* pSrcVec, int nClipFactor,int nShift, int8b nAddValue,nm8s* pDstVec, int nSize);
    //! \}

extern "C" nm64u VEC_TBL_Diagonal_01h_G[8];
extern "C" nm64u VEC_TBL_Diagonal_01h_L[8];
/**	
\defgroup VEC_ClipCnv_AddC VEC_ClipCnv_AddC
    \ingroup vSelect
    \brief
        \ru ���������� ����������� ������ c ��������������� �� ����������. 
        \en Data word-length reduction with their preprocessing. 
	
		\~
    
	\f[
	    pDstVec[i] = Convert(Clip(pSrcVec[i],nClipFactor)) + nAddValue
	\f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
	  \ru ���������� ����������� ������ ����������� ����� ��������������� ��������� � �������������� 
	    ����� ������������ ������� �����.  
	  \en Data word-length is reduced after preprocessing and is made by means of the most significant bits truncation. 

		\~
		\~
    \param pSrcVec    
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nClipFactor 
        \ru ���������� �������, ������������ ������� � ������ ������ ���������. =[1,2,3...15] 
        \en Index of the degree defining the upper and the lower saturation thresholds. =[1,2,3...15] 
		\~
    \param nAddValue   
        \ru ����������� ���������. 
        \en Additive constant. 
		\~
    \param nSize      
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
	\param weights      
        \ru ��������� �� ������� ������������ ��� ���������� ����������. ��� ���������. 
        \en Vector size in elements. 

		\~
    \retval pDstVec   
        \ru �������������� ������. 
        \en The result vec. 

		\~
    \return \e void 
    
    \par
    */
    //! \{
void VEC_ClipCnv_AddC(nm16s* pSrcVec, int nClipFactor, int8b nAddValue,nm8s* pDstVec, int nSize, nm64u* weights=VEC_TBL_Diagonal_01h_G);
    //! \}

	
//*****************************************************************************
  /**
  \internal
  \defgroup VEC_ClipArshCnv_AddC_Ext VEC_ClipArshCnv_AddC_Ext
  \ingroup vSelect

	\brief
	  \ru ���������� ����������� ������ c ��������������� �� ����������. 
	  \en Data word-length reduction with their preprocessing. 

		\~
	
	\f[
		pDstVec[i][j] = DstType(Clip(pSrcVec[i][j],pClipFactor[j]) >> pShift[j]) + pAddValue[j]
	\f]
	
	\f[ i = \overline{0 \ldots nSize-1} \f]
	
	\f[ j = \overline{0 \ldots 7} \f]

	\ru ���������� ����������� ������ ����������� ����� ��������������� ��������� � �������������� 
		����� ������������ ������� �����. 
	\en Data word-length is reduced after preprocessing and is made by means of the most significant 
	bits truncation.    

		\~
	\~
	\param pSrcVec    
		\ru ������� ������. 
		\en Input vec.	

		\~
	\param pnClipFactor 
		\ru ������ �� 8 ����������� �������, ������������ ������� � ������ ������ ���������
							��� -2^pnClipFactor[j] and 2^pnClipFactor[j]-1. =[1,2,3...15] 
		\en Array of 8 factors, wich defining the lower and  the upper saturation thresholds 
							as -2^pnClipFactor[j] and 2^pnClipFactor[j]-1.  =[1,2,3...15] 

		\~
	\param pnShift      
	  \ru ������ �� 8 ����������,  ������������  �� ������� ������� =[2,4,6...14] �����
							�������� ���� ��������� �������; 
		\en Array of 8 parameters which defines for how many positions =[2,4,6...14] vec 
		elements should be shifted

		\~
	\param pnAdd		
	  \ru ������ �� 8 �������. 
		\en Array of 8 constants. 

		\~
	\param nSize		
	  \ru ������ �������� � ���������. 
		\en Vector size in elements. 

		\~
	\retval pDstVec   
	  \ru �������������� ������. 
		\en The result vec. 

		\~
	\return \e void 

  \par
	\xmlonly
		<testperf> 
			 <init> 
					int pnV8[8]={2,2,2,2,2,2,2,2};
					nm64s pnAddV8[1]={0};			
			</init>
			<param> pSrcVec			</param> <values> L G  </values>
			<param> pnShift			</param> <values> pnV8 </values>
			<param> pnClipFactor	</param> <values> pnV8 </values>
			<param> pnAdd			</param> <values> pnAddV8 </values>
			<param> pDstVec			</param> <values> L G </values>
			<param> nSize			</param> <values>10240 </values>
		</testperf>
		<testperf> 
			<init>
					int pnV8[8]={2,2,2,2,2,2,2,2};
					nm64s pnAddV8[1]={0};			
			</init>
			 <param> pSrcVec		</param> <values> L  </values>
			 <param> pnShift		</param> <values> pnV8 </values>
			 <param> pnClipFactor	</param> <values> pnV8 </values>
			 <param> pnAdd			</param> <values> pnAddV8 </values>
			 <param> pDstVec		</param> <values> G </values>
			 <param> nSize			</param> <values> 128 1024 10240 </values>
		</testperf>
	\endxmlonly
	*/
	//! \{
//void VEC_ClipArshCnv_AddC_Ext(v8nm16s* pSrcVec, v8nm32s* pnClipFactor, v8nm32s* pnShift, v8nm8s* pnAdd,  v8nm8s* pDstVec, int nSize);
void VEC_ClipArshCnv_AddC_Ext(v8nm16s* pSrcVec, v8nm32s* pnClipFactor, v8nm32s* pnShift, v8nm32s* pnAdd,  v8nm8s* pDstVec, int nSize);

	//! \}
//void VEC_ClipArshCnv_AddC_Ext(v16nm16s* pSrcVec, v16nm32s* pnClipFactor, v16nm32s* pnShift,v16nm4s* pnAdd, 
//							  v16nm4s* pDstVec, int nSize);


//******************************************************************************************

  /**
	\defgroup VEC_CmpEqC VEC_CmpEqC
    \ingroup vSelect
    \brief
        \ru ���������� �������� ������� �� ������� ��������� ���������. 
        \en Compare vec elements to const equality. 
    
		\~
    
	\f[
        pDstVec(i)  =  \{ \begin{array}{*{20}c}
            nTrueFlag,		&  if &  pSrcVec(i) = nCmpVal  \\
            0,				&  if &  pSrcVec(i) \neq nCmpVal   \\
        \end{array}
    \f]
	
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
		\~
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
	\param nCmpVal
		\ru	�������� ��������� ��� �������� 
		\en Comparision constant value 
		\~
    \param nSize   
		\ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \param nTrueFlag
		\ru ������� �����, ���������������� ��� ���������� �������  
        \en Flag value, being set if condition is true. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en Destination vec. 
		\~
    \return \e void 
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec	</param> <values> L G </values>
             <param> pDstVec	</param> <values> L G </values>
             <param> nCmpVal	</param> <values> 0 </values>
			 <param> nTrueFlag	</param> <values> 1 </values>
             <param> nSize		</param> <values> 10240 </values>
        </testperf>
      \endxmlonly
    */

  //! \{
void VEC_CmpEqC(nm16u15b* pSrcVec,  uint15b nCmpVal,   nm16s* pDstVec, int nSize, int16b nTrueFlag);
void VEC_CmpEqC(nm8u7b* pSrcVec,	uint7b nCmpVal,		nm8s* pDstVec, int nSize, int8b nTrueFlag);
  //! \}


//******************************************************************************************

  /**
	\defgroup VEC_CmpNeC VEC_CmpNeC
    \ingroup vSelect
    \brief
        \ru ���������� �������� ������� �� ������� ����������� ���������. 
        \en Compare vec elements to const nonequality. 
    
		\~
    
	\f[
        pDstVec(i)  =  \{ \begin{array}{*{20}c}
            nTrueFlag,		&  if &  pSrcVec(i) \neq nCmpVal  \\
            0,				&  if &  pSrcVec(i) = nCmpVal   \\
        \end{array}
    \f]
	
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
		\~
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
	\param nCmpVal
		\ru	�������� ��������� ��� �������� 
		\en Comparision constant value 
		\~
    \param nSize   
		\ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \param nTrueFlag
		\ru ������� �����, ���������������� ��� ���������� �������  
        \en Flag value, being set if condition is true. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en Destination vec. 
		\~
    \return \e void 
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nCmpVal </param> <values> 0 </values>
             <param> nSize </param> <values> 10240 </values>
			 <param> nTrueFlag </param> <values> 1 </values>
        </testperf>
      \endxmlonly
    */
	//! \{
void VEC_CmpNeC(nm16u15b* pSrcVec,  uint15b nCmpVal,   nm16s* pDstVec, int nSize, int16b nTrueFlag);
void VEC_CmpNeC(nm8u7b* pSrcVec,	uint7b nCmpVal,		nm8s* pDstVec, int nSize, int8b nTrueFlag);
	//! \}

//******************************************************************************************
  
	/**
	\defgroup VEC_CmpEqV VEC_CmpEqV
    \ingroup vSelect
    \brief
        \ru ������������ ��������� ��������� ���� ������� �� ������� ���������. 
        \en Elementwise vec comparision for equality . 
		\~
    
	\f[
        pDstVec(i)  =  \{ \begin{array}{*{20}c}
            nTrueFlag,		&  if &  pSrcVec(i) = nCmpVal  \\
            0,				&  if &  pSrcVec(i) \neq nCmpVal   \\
        \end{array}
    \f]
	
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
		\~
    \param pSrcVec1  
        \ru ������ ������� ������. 
        \en First input vec. 
		\~
    \param pSrcVec2  
        \ru ������ ������� ������. 
        \en Second input vec. 
		\~
    \param nSize   
		\ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \param nTrueFlag
		\ru ������� �����, ���������������� ��� ���������� �������  
        \en Flag value, being set if condition is true. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en Destination vec. 
		\~
    \return \e void 
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
			 <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
			 <param> nTrueFlag </param> <values> 1 </values>
        </testperf>
      \endxmlonly
    */
	//! \{
void VEC_CmpEqV(nm16u15b* pSrcVec1, nm16u15b* pSrcVec2, nm16s* pDstVec, int nSize, int16b nTrueFlag);
void VEC_CmpEqV(nm8u7b* pSrcVec1, nm8u7b* pSrcVec2, nm8s* pDstVec, int nSize, int8b nTrueFlag);
	//! \}

//******************************************************************************************

	/**
	\defgroup VEC_CmpNeV VEC_CmpNeV
    \ingroup vSelect
    \brief
        \ru ������������ ��������� ��������� ���� ������� �� ������� �����������. 
        \en Elementwise vec comparision for nonequality . 
		\~
    
	\f[
        pDstVec(i)  =  \{ \begin{array}{*{20}c}
            nTrueFlag,		&  if &  pSrcVec(i) \neq nCmpVal  \\
            0,				&  if &  pSrcVec(i) = nCmpVal   \\
        \end{array}
    \f]
	
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
		\~
    \param pSrcVec1  
        \ru ������ ������� ������. 
        \en First input vec. 
		\~
    \param pSrcVec2  
        \ru ������ ������� ������. 
        \en Second input vec. 
		\~
    \param nSize   
		\ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \param nTrueFlag
		\ru ������� �����, ���������������� ��� ���������� �������  
        \en Flag value, being set if condition is true. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en Destination vec. 
		\~
    \return \e void 
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1	</param> <values> L G </values>
			 <param> pSrcVec2	</param> <values> L G </values>
             <param> pDstVec	</param> <values> L G </values>
             <param> nSize		</param> <values> 10240 </values>
			 <param> nTrueFlag	</param> <values> 1 </values>
        </testperf>
      \endxmlonly
    */
	//! \{
void VEC_CmpNeV(nm16u15b* pSrcVec1, nm16u15b* pSrcVec2, nm16s* pDstVec, int nSize, int16b nTrueFlag);
void VEC_CmpNeV(nm8u7b* pSrcVec1, nm8u7b* pSrcVec2, nm8s* pDstVec, int nSize, int8b nTrueFlag);
	//! \}

//******************************************************************************************
	

/*
	\internal
    \defgroup VEC_Cnv VEC_Cnv
    \ingroup vInit
    \brief
        \ru ��������� ����������� ��������� ������� � ��������������
        \en Change of vec elements word-length with clipping
    
		\~
        \ru �������������� 32� �������� ������ � ��������������� �������������� 
	        ���������� ����� 16..31.. ,����� �������������� � ���������� ������ 
            ������� ��� ���������. ��� ������������� ������������ ���������
            ��������� ���� nm64s � ������ _F1CR_16_to_x. �� ���������, ��� �����
            ff00_ff00_ff00_ff00 ��������������� ��������� ���������� [-255..256].
            � ������� ����������� 64� ����� ���������� ������������ �������� 
            ���������� ���������� _VR_16_to_x, ������� �� ��������� ����� ����.
        \en Signed data are converted to lesser word-length is made by means of 
            the low significant bits truncation.

		\~
		\~
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 

		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 

		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec	</param> <values> L G </values>
             <param> pDstVec	</param> <values> L G </values>
             <param> nSize		</param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec	</param> <values> L </values>
             <param> pDstVec	</param> <values> G </values>
             <param> nSize		</param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    \{
    */
  //! \{
void Vec_ClipArshCnv_AddC( nm32s* pSrcVec, nm8u* pDstVec, int nSize);
  //! \}



#endif