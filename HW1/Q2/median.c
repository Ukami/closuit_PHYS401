#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
int main(void)
{
	std::vector<int> data;//change this to a double for non integer numbers
	//std::vector<int>  sample;
	int * sample;
	double * medians;
	std::string numbers;
	int tempdata, I=0, iterBoot, value, median=0, tempsample;
	double N, ave, strap ;
	std::cout << "input file name ";
	std::cin >> numbers;
	std::cout << std::endl;
	std::cout << "number of iteration for bootstrap ";
        std::cin >> iterBoot;
	std::cout << std::endl;
	std::ifstream file;
	file.open(numbers.c_str());
	while(file)
	{
		file >> tempdata;
		if (file)		//prevents double entries at end of the read
			data.push_back(tempdata); 
	}
	sample = new int[data.size()];
	medians = new double[iterBoot];
	for(int iter=0; iter<iterBoot; ++iter)
	{
		for(int I=0; I<data.size(); ++I)
		{	
			sample[I] = data[rand() % data.size()];
		}
		std::sort (sample, sample+data.size());  // sorts each sample
		if (data.size()%2==0) //take the middle 2 numbers and averages them to get the median
		{
			tempsample = data.size() / 2;
			N = (sample[tempsample]+sample[tempsample+1])/2.0;
			median+=N;
			medians[iter]=N;
			
		}
		else	//takes the middle number and assigns that as the median
		{
			N=(data.size()-1)/2.0+1.0;
			median+=N;
			medians[iter]=N;
		}
	}	 
	strap = iterBoot;
	ave=median/strap;
	std::cout << "the ave median is = " << ave << std::endl;
	double deviation, diffs=0;
	for(int J=0; J < iterBoot; ++J) //iterBoot is number of iterations for the method
	{
		diffs+=pow(medians[J]-ave,2); // the is just (x-ave)^2 for the standard devation 
	}
	deviation=sqrt(diffs/iterBoot); // ends up giving (1/ave* sequencesum(x-ave)^2)^(1/2)
	std::cout << "the standard devation is + or - " << deviation<< std::endl; 
	
}	
		 
