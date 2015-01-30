#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
int main(void)
{
	float sumup, sumdown sumdiff;
	int N, iter;
	std::cout<<"input value to some to noting that the sum will be 10^N ";
	std::cin>> N;
	std::cout<<std::endl;
	iter=pow(10,N);
	for(int I=1; I<iter;++I)
	{
		sumup+=1/I;		
	}
	for(int J=iter; J>0;--J)
	{	
		sumdown+=1/J;
	}
	sumdiff=abs(sumup-sumdown);
	std::cout<<"the difference in S up and S down is "<< sumdiff;
}

