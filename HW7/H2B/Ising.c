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
int *spinsfunc(int N)
{
    MTRand_open irand;
    int * spins = new int[N];
    for(int i=0;i<N;++i)
    {
        if (irand()<=.5)
        {
            spins[i]=-1;
        }
        else
        {
            spins[i]=1;
        }
    }
    return spins;
}

int main(void)
{
    MTRand_open drand;
    drand.seed(seedgen());
    int N=1000; // controls number of spins
    double delta;
    int nb[2][N];
    int *spin;
    int sweep=6000; // controls number of sweeps note this needs to include the number of sweeps thermailized
    double M[sweep]; memset(M, 0, sizeof(M));
    double E[sweep]; memset(E, 0, sizeof(E));
    double sqM[sweep]; memset(sqM, 0, sizeof(sqM));
    double sqE[sweep]; memset(sqE, 0, sizeof(sqE));
    int thermalize=0; // controls number of of sweeps to thermailize
    int trials = 100; // controls number of trials to avergage each temperature over
    double total=0;
    double sqtotal=0;
    double energy;
    double aveTemp;
    double sqAveTemp;
    double Mcount;
    double step=.5; // controls the temperature increment step size
    double maxtemp=.5;// controls the highest temerature to measure to
    double starttemp=.5; // this is the temp where measurements start
    for(int i=0;i < N;++i)
    {
        if (i==0)
        {
            nb[0][i]=N-1;
            nb[1][i]=i+1;
        }
        else if (i==N-1)
        {
            nb[0][i]=i-1;
            nb[1][i]=0;
        }
        else
        {
            nb[0][i]=i-1;
            nb[1][i]=i+1;
        }
    }
    std::ofstream output("Ising.dat"); // controls output file name
    for(starttemp;starttemp<=maxtemp;starttemp=starttemp+step) // note start temp is being incremented
    {
        aveTemp=0;
        sqAveTemp=0;
        for(int k=1; k<=trials;++k)
        {
            std::cout<<k<<std::endl;
            spin=spinsfunc(N);
            energy=0;
            for(int y=0;y<N;++y)
            {
                energy-= spin[y]*spin[nb[1][y]];
            }
            total=0;
            //sqtotal=0;
            for(int i=0;i < sweep;++i)
            {
                for (int w = 0; w < N; w++) 
                {
                    
                    int s=(N)*drand();
                    delta=0;
                    for(int j=0;j<=1;++j)
                    {
                        delta+=2*spin[s]*(spin[nb[j][s]]);
                    
                    }
                    if (drand() < (exp(-1.0*delta/starttemp)))
                    {
                        spin[s]=(-1)*spin[s];
                        energy+= ((double)delta);
                    }
                }
                if (i>thermalize) //starts the averages after a set number of sweeps
                {
                    if(i % 10 == 0) 
                    {
                        total+=energy;
                        //sqtotal+=pow(energy,2.0);
                    }
                }
                Mcount=0.0;
                for(int u=0;u<N;++u)
                {
                    Mcount+=spin[u];
                    M[i]+=spin[u];
                }
            sqM[i]+=pow(Mcount,2);
            E[i]+=energy;
            }
           // aveTemp+=(total/((sweep-thermalize)/trials))/N;
            //sqAveTemp+=sqtotal/((sweep-thermalize)/10.0);
           // sqAveTemp+=pow((total/((sweep-thermalize)/trials))/N,2.0);
        }
        //output<<starttemp<<"  "<<(aveTemp/trials)<<"  "<<sqrt((sqAveTemp/trials)-pow((aveTemp/trials),2.0))<<std::endl;
        for(int h=0; h<sweep;++h)
        {
            output<<h+1<<"  "<<E[h]/trials/N<<"  "<<sqM[h]/trials/N<<std::endl;
        }
    }
}


