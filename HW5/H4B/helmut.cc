#include <unistd.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cmath>
#include <iomanip>
#include "helmutrand.h"
#include <sys/time.h>
#include <sys/resource.h>

long seedgen()
{
    long int seconds;
    return ((time(&seconds)*181)*((getpid() - 83)*359))%104729;
}

double func(double *x, int n)
{
    double total=0;
    for(int i=0;i<n;++i)
    {
        total+=x[i]-.5;
    }
    return sqrt(12.0/n)*total;
}

int main(void)
{
    int n=12000;
    int runs=pow(10,6);
    double random[n];
    double x, xa, xb, xc, xd, xe, xf; //for the 6 differnt moments.
    long seed = seedgen();
    sethelmutrand(seed);
    for(int i=1;i<=runs;++i)
    {
        for(int j=0; j < n;++j)
        {
            random[j]=helmutrand(); 
        }
        x=func(random,n);
        xa+=x;
        xb+=pow(x,2);
        xc+=pow(x,3);
        xd+=pow(x,4);
        xe+=pow(x,5);
        xf+=pow(x,6);
    }
    std::cout<<"<x^1>="<<xa/runs<<std::endl;
    std::cout<<"<x^2>="<<xb/runs<<std::endl;
    std::cout<<"<x^3>="<<xc/runs<<std::endl;
    std::cout<<"<x^4>="<<xd/runs<<std::endl;
    std::cout<<"<x^5>="<<xe/runs<<std::endl;
    std::cout<<"<x^6>="<<xf/runs<<std::endl;

}


