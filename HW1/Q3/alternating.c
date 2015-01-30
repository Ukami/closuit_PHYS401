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
	float fsumup=0;
	double updiff;
	int iter;
	double altingone; //this will be used to make the sum alternate
	for(int N=2; N<=9 ;++N)
	{
		iter=pow(10,N);
		for(int I=1; I<=iter;++I)
		{
			altingone=pow(-1,I+1);
			dsumup += altingone*((double)1.0)/((double)I);
			fsumup += altingone*((float)1.0)/((float)I);		
		}
		updiff=std::abs(fsumup-dsumup);
		std::cout<<"float sum up ="<<fsumup<<"  double sum up="<<dsumup<<std::endl;	
		updiff=std::abs(dsumup-std::log(2)); // std::log() means base e in c++ ie it is ln()
	}
}

