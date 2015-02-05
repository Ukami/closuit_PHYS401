#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
int main(void)
{
	double Test=7, Root=2, deriv, temp;
	while (std::abs(Test) > .00000000000001)
	{
		deriv=Root*2;
		temp=Root;
		Test=pow(Root,2)-2;
		Root -= Test/deriv;
	//	std::cout<<Root<<std::endl;
	}
	      
	printf("2^(1/2) = {%1.14f}\n", Root); 
}
