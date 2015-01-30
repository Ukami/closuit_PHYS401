#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
int main(void)
{
	double sumup=0;
	double sumdown=0;
	double sumdiff;
	int iter;
	for(int N=2; N<=8 ;++N)
	{
		iter=pow(10,N);
		for(int I=1; I<=iter;++I)
		{
			sumup += ((double)1.0)/((double)I);		
		}
		for(int J=iter; J>0;--J)
		{	
			sumdown += ((double)1.0)/((double)J);
		}
		sumdiff=std::abs(sumup-sumdown);
		std::cout<< "10^"<<N<<" S up ="<<sumup<<" S down="<<sumdown<<"\n";
	}
}

