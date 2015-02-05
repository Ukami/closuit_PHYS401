#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
int main(void)
{
	double Test=7, Root=2;
	while (std::abs(Test) > .00000000000001)
	{
		Root=.5*(Root+(2/Root));
		Test=pow(Root,2)-2;
	//	std::cout<<Root<<std::endl;
	}
	      
	printf("2^(1/2) = {%1.14f}\n", Root); 
}
