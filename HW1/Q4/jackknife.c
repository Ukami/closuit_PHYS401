#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
int main(void)
{
	std::vector<double> data;//change this to a double for non integer numbers
	std::string numbers;
	double tempdata, tempmean, valuecount=0;
	double mean, total=0;
	std::cout << "input file name ";
	std::cin >> numbers;
	std::cout << std::endl;
	std::ifstream file;
	file.open(numbers.c_str());
	while(file)
	{
		file >> tempdata;
		if (file)		//prevents double entries at end of the read
			data.push_back(tempdata); 
	}
	for(int I=0; I<data.size();++I)
	{
		total+=data.at(I);
	}
	for(int J=0; J<data.size();++J)
		{
		tempmean=(total-data.at(J))/(data.size()-1);
		valuecount+=tempmean;
		}
	mean=valuecount/data.size();
	std::cout<<"the jack knife mean is="<< mean << std::endl;
	 	
}	
		 
