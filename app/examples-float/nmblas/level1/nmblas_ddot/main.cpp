#include <stdio.h>
#include <stdlib.h>
#include "nmblas.h"


#define SIZE 10

#ifdef __GNUC__ // NMC-GCC C++ compilier 
double x[SIZE] __attribute__ ((section (".data_imu1")));
double y[SIZE] __attribute__ ((section (".data_imu2")));
#else 			// NMSDK C++ compiler
#pragma data_section ".data_imu1"
double x[SIZE];
#pragma data_section ".data_imu2"
double y[SIZE];
#endif 


int main(){
	for(int i=0;i<SIZE;i++){
		x[i] = i;
		y[i] = i;
		printf("x[%d]=%f\ty[%d]=%f\n",i,x[i],i,y[i]);
	}
	
	double result = nmblas_ddot(SIZE,x,1,y,1);
	printf("result=%f\n",result);

	return 0;
}

