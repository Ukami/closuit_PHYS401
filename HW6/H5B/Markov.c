#include <unistd.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cmath>
#include <iomanip>
#include "mtrand.h"
#include <sys/time.h>
#include <sys/resource.h>

long seedgen()
{
    long int seconds;
    return ((time(&seconds)*181)*((getpid() - 83)*359))%104729;
}


int main(void)
{
    int k=7;  //controls number of trials 
    MTRand_open irand;
    irand.seed(seedgen());
    double hit;   //counts hits
    double p=.58; //this controls stepsize for the chain
    double pi[k];
    double reject[k];
    double rejects=0;
    double x,y;
    double dx,dy;
    int j;
    double ave;
    int m=10;
    for(j=1;j<=k;++j)
    {
        ave=0;
        for(int n=1; n<=m;++n)
        {
            hit=0;
            x=0;
            y=0;
            for(int i=1; i<=pow(10,j); ++i)
            {
                dx=p*2*(irand()-.5);
                dy=p*2*(irand()-.5);
                if(fabs(x+dx)<1 && fabs(y+dy)<1)
                {
                    x=x+dx;
                    y=y+dy;
                }
                else
                {
                    ++rejects;
                }
                
                if(pow(x,2.0)+pow(y,2.0)<1.0)
                {
                    hit++;
                }
            }
            ave=ave+4.0*double(hit/pow(10,j));    
        }
        pi[j-1]=ave/m;
        reject[j-1]=rejects/((double)m);
        
    }
    std::ofstream output("Markov.dat");
    for(int h=0; h<k ; ++h)
    {
        output<<pow(10,h+1)<<"   "<<fabs(pi[h]-3.1415926535898)<<std::endl;
        std::cout<<"10^"<<h+1<<"="<<pi[h]<<" error="<<fabs(pi[h]-3.1415926535898)<<" and with a acceptence coeffcient of "<<(pow(10.0,(double) h+1)-reject[h])/pow(10,h+1)<<std::endl;
    }
}


