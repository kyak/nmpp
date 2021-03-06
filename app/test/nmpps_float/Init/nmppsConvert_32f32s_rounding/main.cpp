#include <nmtype.h>
#include <malloc32.h>
#include "nmpp.h"
#include <stdio.h>

#define 				SIZE					1024

int main()
{
	nm32f* src_32f = (nm32f*) nmppsMalloc_32f(SIZE);
	nm32s* dst_32s = (nm32s*) nmppsMalloc_32s(SIZE + 11);
	nmppsRand_32f(src_32f, SIZE, 5, -15);
	// for(int i = 0; i < SIZE; i++) {
	// 	src_32f[i] = float(i) / 0.09090909;
	// 	//src_32f[i] = 12.0f;
	// }

	for(int i = 0; i < SIZE + 11; i++) {
		dst_32s[i] = 777;
	}

	// nmppsConvert_32f32s_rounding(src_32f, dst_32s, -3, SIZE);
	// for(int i = 0; i < SIZE + 11-11; i++) {
	// 	printf("dst_32s[%d] = %d\n", i, dst_32s[i]);
	// }

	unsigned crc = 0;
	//
	for(int iSize = 2; iSize < SIZE; iSize += 2) {
		for(int scale = -10; scale < 11; scale++) {
			nmppsConvert_32f32s_rounding(src_32f, dst_32s, scale, iSize);
			nmppsCrcAcc_32s(dst_32s, SIZE + 11, &crc);
		}
		// for(int i = 0; i < SIZE; i++) {
		// 	printf("dst_32s[%d] = %d\n", i, dst_32s[i]);
		// }
	}
	// nmppsConvert_32f32s_rounding(src_32f, dst_32s, SIZE);
	// for(int i = 0; i < SIZE + 11; i++) {
	// 	printf("dst_32s[%d] = %d\n", i, dst_32s[i]);
	// }
	nmppsFree(src_32f);
	nmppsFree(dst_32s);

	return crc >> 2;
}

// crc = 342391388
