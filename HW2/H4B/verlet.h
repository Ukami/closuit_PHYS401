#ifndef VERLET_H
#define VERLET_H
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "datstruct.h"
double func1(double a)
{
	return -pow(a, 3.0);  // change this is function changes
}	

data verlet(double x, double p, double h) 
//x and p position and momentum, h is step size
{
	double half;
    data c;
    half = p+(h/2.0)*func1(x);
    c.x=x+h*half;
    c.p=half+(h/2)*func1(c.x);
	return c; 	
	 
}
#endif
