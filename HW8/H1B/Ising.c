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
            spins[i]=1;
        }
        else
        {
            spins[i]=-1;
        }
    }
    return spins;
}

int main(void)
{
    MTRand_open drand;
    drand.seed(seedgen());
    int L=32;
    int W=32; //note W needs to be assigned so W<L
    int N=L*W; // controls number of spins
    double delta;
    int nb[4][N];
    int *spin;
    int trials = 10; // controls number of trials to avergage each temperature over
    int thermalize=5000; // controls number of of sweeps to thermailize
    int sweep=60000; // controls number of sweeps note this needs to include the number of sweeps thermailized
    double M[trials]; memset(M, 0, sizeof(M));
    double sqM[trials]; memset(sqM, 0, sizeof(sqM));
    double M4[trials]; memset(M4, 0, sizeof(M4));
    double aveM;
    double avesqM;
    double aveM4;
    double total=0;
    double sqtotal=0;
    double energy, Mag;
    double Mcount;
    double step=.005; // controls the temperature increment step size
    double maxtemp=2.3;// controls the highest temerature to measure to
    double starttemp=2.2; // this is the temp where measurements start
    for(int i=0;i < L;++i)
    {
        for(int j=0;j<W;++j)
        {
            nb[0][i*L+j]=(L*(L-1)+i*L)%N+j;    //up neighbor
            nb[1][i*L+j]=(i+1)*L%N+j;    //down neighbor
            nb[2][i*L+j]=L*i+(W-1+j)%W;    //left neighbor
            nb[3][i*L+j]=i*L+(j+1)%W;    //right neighbor
        }
    }
            

    std::ofstream output("Ising32.dat"); // controls output file name
    for(starttemp;starttemp<=maxtemp+step/10;starttemp=starttemp+step) // note start temp is being incremented the step/10 is to insure the last step happens
    { 
       //std::cout<<starttemp<<std::endl;
        aveM=0;
        avesqM=0;
        aveM4=0;
        for(int k=1; k<=trials;++k)
        {
            memset(M, 0, sizeof(M));
            memset(sqM, 0, sizeof(sqM));
            memset(M4, 0, sizeof(M4));
            spin=spinsfunc(N);
            Mag=0;
            energy=0;
            for(int y=0;y<N;++y)
            {
                energy-= spin[y]*(spin[nb[1][y]]+spin[nb[3][y]]);  // this is the starting energy (the Hamiltonian)
            }
            for(int i=0;i < sweep;++i)
            {
                Mag=0;
                for (int r= 0; r < N; r++) 
                {
                    
                    int s=(N)*drand();
                    delta=0;
                    for(int j=0;j<4;++j) //the 3 correspondes to the number of neighbors-1. the -1 is for indexing purposes
                    {
                        delta+=2*spin[s]*(spin[nb[j][s]]);
                    
                    }
                    if (drand() < (exp(-1.0*delta/starttemp)))
                    {
                        spin[s]=(-1)*spin[s];
                        energy+= ((double)delta);
                    }
                }
                if (i>=thermalize) //starts the averages after a set number of sweeps
                {
                    //sqtotal+=pow(energy,2.0);
                
                    for(int u=0;u<N;++u)
                    {
                        Mag+=(((double)spin[u]));
                    }
                }
            }
            M[k-1]=Mag/(((double)(sweep-thermalize)));
            sqM[k-1]=pow(Mag,2.0);
            M4[k-1]=pow(Mag,4.0);
            std::cout<<Mag<<"   "<<M[k-1]<<"   "<<sqM[k-1]<<"   "<<M4[k-1]<<std::endl; 
        }        
        for(int h=0; h<trials;++h)
        {
            aveM+=M[h]/trials;
            avesqM+=sqM[h]/trials;
            aveM4+=M4[h]/trials; 
        }

         output<<starttemp<<"  "<<avesqM<<"  "<<aveM4<<std::endl;
        
    }
}


