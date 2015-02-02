#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
int main(void)
{
	double Test=7, Root1, Root, Root2; //the value on Test is for the begining of the for loop
	double Upper=2, Lower=1, Checku, Checkl,Check;
	while(std::abs(Test)>.0001)
	{
		Root=(Lower+Upper)*.5; 
		Test=((Root*Root*Root)-(4.0*Root)+2.0);
		Checku=(pow(Upper,3)-4*Upper+2)*Test;
		Checkl=(pow(Lower,3)-4*Lower+2)*Test;
		if(Checku > 0.0 && Checkl < 0)
		{
			Upper=Root;
		}
		else if (Checkl > 0.0 && Checku < 0)
		{
			Lower=Root;
		}
		else
		{
			std::cout<<"No roots could be found try inputting either a smaller interval or larger interval"<<std::endl;
			
		}
		Root1=Root;
		std::cout<<Root1<<std::endl;
	}
	Test=7;
	Upper=1;
	Lower=0;
        while(std::abs(Test)>.0001)
        {
                Root=(Lower+Upper)*.5;  
                Test=((Root*Root*Root)-(4.0*Root)+2.0);
                Checku=(pow(Upper,3)-4*Upper+2)*Test;
                Checkl=(pow(Lower,3)-4*Lower+2)*Test;
                if(Checku > 0.0 && Checkl < 0)
                {
                        Upper=Root;
                }
                else if (Checkl > 0.0 && Checku < 0)
                {
                        Lower=Root;
                }
                else
                {
                        std::cout<<"No roots could be found try inputting either a smaller interval or larger interval"<<std::endl;

                }
                Root2=Root;
		std::cout<<Root2<<std::endl;
        }
	printf("the positive roots of \n x^3-4x+2 \n={%5.4f,%5.4f}\n",Root1,Root2);
}	
		 
