#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
int main(void)
{
	double Test=7, Root1=1, Root=2, deriv, temp; //the value on Test is for the begining of the for loop
	while (std::abs(Test) > .00000000000001)
	{
		deriv=pow(Root,2)*3-4;
		temp=Root;
		Test=pow(Root,3)-4*Root+2;
		Root -= Test/deriv;
		std::cout<<Root<<std::endl;
	}
	      
	Test=7;
	while (std::abs(Test) > .00000000000001)
        {
                deriv=(pow(Root1,2)*3)-4;
                Test = pow(Root1,3)-4*Root1+2;
                Root1 -= Test/deriv;
		std::cout<<Root1<<std::endl;
        }
	printf("The positive roots are = {%1.14f,%1.14f}\n", Root, Root1); 
}
