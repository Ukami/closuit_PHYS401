#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
int main(void)
{
	double Test=7, Test1, Root=2, Root1=1, temp;
	while (std::abs(Test) > .00000000000001)
	{
		Test=pow(Root,2)-2;
		Test1=pow(Root1,2)-2;
		temp=Root;
		Root-=(Test*(Root-Root1))/(Test-Test1);
		Test=pow(Root,2)-2;
		Root1=temp;
		
	}
	      
	printf("2^(1/2) = {%1.14f}\n", Root); 
}
