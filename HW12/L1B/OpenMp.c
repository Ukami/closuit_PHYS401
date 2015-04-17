#include <unistd.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cmath>
#include <iomanip>
#include "omp.h"
#include "mtrand.h"
#include <sys/time.h>
#include <sys/resource.h>

long seedgen()
{
    long int seconds;
    return ((time(&seconds)*181)*((getpid() - 83)*359))%104729;
}

double func(double x)
{
    return pow(x,3);
}


int main(void)
{
    std::cout<<"This workstation has "<<int omp_get_num_procs(void)<<" cores"<<std::endl; //prints number of cores
#pragma omp directive
    {
        std::cout<<"Hello from thread"<<int omp_get_thread_num(void)<<std::endl;
    }
    int k=7;  //controls number of trials 
    double integral=0;
    MTRand_closed irand;
    irand.seed(seedgen());
    int m=100;
    double hit;
    double ave;
    double I[k];
    double count;
    for(int i=1; i<=k;++i)
    {
        ave=0;
        for(int n=1;n<=100;++n)
        {
            count=0;
            for(int j=1;j<=pow(10,i);++j)
            {
                count+=func(irand());
            }
            ave+=count/pow(10,i);
        }
        I[i-1]=ave/m;

    }
    std::ofstream output("carlo.dat");
    for(int t=0;t<k;++t)
    {
        std::cout<<pow(10,t+1)<<"->" <<I[t]<<std::endl;
        output<<pow(10,t+1)<<"  " <<fabs(I[t]-.25)<<std::endl;
    }
}


