#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
int main(void)
{
	double dsumup=0;
	double dsumdown=0;
	float fsumup=0;
	float fsumdown=0;
	double updiff, downdiff;
	int iter;
	for(int N=2; N<=8 ;++N)
	{
		iter=pow(10,N);
		for(int I=1; I<=iter;++I)
		{
			dsumup += ((double)1.0)/((double)I);
			fsumup += ((float)1.0)/((float)I);		
		}
		for(int J=iter; J>0;--J)
		{	
			dsumdown += ((double)1.0)/((double)J);
			fsumdown += ((float)1.0)/((float)J);
		}
		updiff=std::abs(fsumup-dsumup);
		downdiff=std::abs(fsumdown-dsumdown);
		std::cout<<"sum up diff="<<updiff<<"  sum down diff="<<downdiff<<std::endl;	
	}
}

