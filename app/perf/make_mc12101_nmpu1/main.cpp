#include "nmpp.h"
#include "nmpp-cpp.h"
#include "time.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#pragma data_section ".data_imu0"
    long long im0[2048];
#pragma data_section ".data_imu1"
    long long im1[2048];
#pragma data_section ".data_imu2"
    long long im2[2048];
#pragma data_section ".data_imu3"
    long long im3[2048];

#pragma data_section ".data_emi"
    long long emi[4096];


int main()
{
  return 0;
}
