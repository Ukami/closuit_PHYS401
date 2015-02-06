#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "rk4.h"
#include "datstruct.h"
int main()
{
	double x, p, h, t=0;
	data d;
	std::cout<<"input position";
	std::cin>>x;
	std::cout<<std::endl;
	std::cout<<"input momentum(velocity)";
        std::cin>>p;
        std::cout<<std::endl;
	std::cout<<"input stepsize";
        std::cin>>h;
        std::cout<<std::endl;


	std::ofstream output("rk4a.dat");
	for(int j;j< 1000 ; j++)
	{		
        output<<t<<"  "<<x<<"  "<<p<<std::endl;
		d=rk4(x,p,h);
		x=d.x;
		p=d.p;
        t+=h;
	}
	output<<t<<"  "<<x<<"  "<<p<<std::endl;
	output.close();
}
