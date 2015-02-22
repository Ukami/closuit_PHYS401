#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cmath>

double I(double x)
{
    double result;
    result=1.0/(1+x);
    return result;
}

int main(void)
{
    double value=0;
    double lbound=0, ubound=1;
    double integral=0;
    double k = 13;
    double error;
    double h=pow(2.0,k);        //the is h in the equation but h^-1
    for(int M=1; M < h*(ubound-lbound);M++)
    {
        value+=I(M*(ubound-lbound)/h);
    }
integral=(1/h)*((I(lbound)+I(ubound))/2+value);
error=fabs(integral-0.6931471806);
printf("The trapezium rule gives %.10f",integral);
std::cout<<std::endl;
printf("The error to ten digits is %.10f",error);
std::cout<<std::endl;
}


