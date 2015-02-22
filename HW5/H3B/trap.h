#ifndef trap_h
#define trap_h
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cmath>
#include "function.h"

double trap(double lbound, double ubound, int k) // need lower and upper bounds to integrate and k is for number of divisions
{
    double sum=0;
    double integral=0;
    double h=pow(2.0,k);        //the is h in the equation but h^-1
    for(int M=1; M < h;M++)
    {
        sum+=func(lbound+M*(ubound-lbound)/h);
    }
integral=((ubound-lbound)/h)*((func(lbound)+func(ubound))/2+value);
return integral;
}


