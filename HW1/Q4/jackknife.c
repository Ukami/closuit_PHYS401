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
	double *aves;		//for the callculation of the deviation
	double tempdata, tempmean, valuecount=0, deviation=0, dcount=0;
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
	aves = new double[data.size()];
	for(int J=0; J<data.size();++J)
		{
		tempmean=(total-data.at(J))/(data.size()-1);
		valuecount+=tempmean;
		aves[J]=tempmean;
		}
	mean=valuecount/data.size();
	for(int k=0; k<data.size(); ++k)
	{
		dcount+=pow(aves[k]-mean,2);
	}
	deviation = sqrt(dcount/data.size());
	std::cout<<"the jack knife mean is="<< mean <<" + or - "<<deviation<< std::endl;
	 	
}	
		 
