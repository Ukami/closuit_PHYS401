#ifndef RK4_H
#define RK4_H
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "datstruct.h"
double func(double a)
{
	return -pow(a, 3.0);  // change this is function changes
}	

data rk4(double x, double p, double h) 
//x and p position and momentum, h is step size
{
	double kp[4], kx[4];
	data c;
	kx[0]=p;
	kp[0]=func(x);
	kx[1]=p+.5*h*kp[0];
	kp[1]=func(x+.5*h*kx[0]);
	kx[2]=p+.5*h*kp[1];
	kp[2]=func(x+.5*h*kx[1]);
    kx[3]=p+.5*h*kp[2];
	kp[3]=func(x+h*kx[2]);
	c.x=x+(h/6.0)*kx[0]+(h/3.0)*kx[1]+(h/3.0)*kx[2]+(h/6.0)*kx[3];
	c.p=p+(h/6.0)*kp[0]+(h/3.0)*kp[1]+(h/3.0)*kp[2]+(h/6.0)*kp[3];	
	return c; 	
	 
}
#endif
