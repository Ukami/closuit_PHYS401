#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
int main(void)
{
	double x=0, t=0, y=1, v=0;
	std::ofstream output("Trajectory_0.dat");
	while (y > .000001)
	{
		x=x+.01*t;
		y=y+.01*(-.5*pow(t,2));
		t=t+0.1;
		output<<x<<"  "<<y<<std::endl;
	}
	output.close(); 
}
