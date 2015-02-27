#ifndef Romberg_h
#define Romberg_h
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cmath>
#include "trap.h"
#include "function.h"

double Romberg(double lbound, double ubound, int k) //k controls the number of iterations 2^k 
}
vector <double*> grid;
for (int i=0; i<k;++i)
{
    grid.push_back(new double[i+1]);
    grid[i][0]=trap(lbound, ubound, k);
    for (int j=1; j<=i;++j)
    {
        grid[i][j]=(pow(4,j)*grid[i][j-1]-grid[i-1][j-1])/(pow(4,j)-1);
    }
}
return grid;
}
#endif Romberg_h

