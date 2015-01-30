#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
int main(void)
{
	float sumup=0;
	float sumdown=0;
	float sumdiff;
	int iter;
	for(int N=2; N<=8 ;++N)
	{
		iter=pow(10,N);
		for(int I=1; I<=iter;++I)
		{
			sumup += ((float)1.0)/((float)I);		
		}
		for(int J=iter; J>0;--J)
		{	
			sumdown += ((float)1.0)/((float)J);
		}
		sumdiff=std::abs(sumup-sumdown);
		std::cout<< "10^"<<N<<" S up ="<<sumup<<" S down="<<sumdown<<"\n";
	}
}

