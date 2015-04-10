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
#include "parentstruct.h"
long seedgen()
{
    long int seconds;
    return ((time(&seconds)*181)*((getpid() - 83)*359))%104729;
}

MTRand_open drand(seedgen());

int totalfit(int*S,int size) //returns the sum of all the loads from the given array
{
    int total=0;
    for(int i=0; i<size;++i)
    {
        total+=S[i];
    }
    return total;
}
double fitness(int total, int*I,int*load,int size)
{
    int S0=0;
    int S1=0;
    int S2=0;
    for(int i=0; i<size; ++i)
    {
        if (I[i]==0)
        {
            S0+=load[i];
        }
        if (I[i]==1)
        {
            S1+=load[i];
        }
        if (I[i]==2)
        {
            S2+=load[i];
        }
    }
   return double(total-(1.0/3.0)*(abs(S0-S1)+abs(S0-S2)+abs(S1-S2))); 
}
parents select(int * * gen, int*load, int size, int pop,int total) //the size the number of loads array
{
    double minfit=fitness(total, gen[1], load, size);
    double fit[pop];
    double totalfit=0;
    double roll = 0;
    double accumulator;
    parents parent;
    for(int i=0;i<pop;++i)
    {
        fit[i]=fitness(total, gen[i], load, size);
        if (fit[i]<minfit)
        {
            minfit=fit[i];
        }
        totalfit+=fit[i];
    }
    totalfit -= minfit*pop;
    roll=totalfit*drand();
    if(totalfit <= 0) {
        totalfit = 0;
        roll = 0;
    }
    accumulator=0;
    int i;
    for(i=0; accumulator <= roll;++i)
    {
        accumulator += fit[i]-minfit;
    }
    parent.p1=i-1;
    roll=(totalfit-fit[parent.p1]+minfit)*drand();
    accumulator=0;
    i=0;
    for(i=0;accumulator <= roll; ++i)
    {
        if( i != parent.p1)
        {
            accumulator+=fit[i]-minfit;
        }
    }
    parent.p2=i-1;
    if(parent.p2 < 0) parent.p2 = 0;
    return parent;
}

int * breed(double muterate, int size, int*parent1, int*parent2,int cut)
{
    int * child = new int[size];
    for(int i=0; i<size;++i)
    {
        if(drand()<muterate)
        {
            child[i]=int(drand()*3);
        }
        else if(i<cut)
        {
            child[i] = parent1[i];
        }
        else 
        {
            child[i]=parent2[i];
        }
    }
    return child;
}

int main(void)
{
    int N=25; // number of loads
    int loads[N];
    int sumS;
    int pop=10; //population size
    int generations=500; // number of genertations
    int * origen[pop]; for(int i=0; i<pop; ++i) origen[i] = new int[N];
    int nextgen[pop][N];
    int * child1 = NULL;
    int * child2 = NULL;
    int bestchild[N];
    double bestfit=0;
    double mutation=.05;
    std::ifstream file("loads.txt");
    if(file.is_open())
    {
        for(int i=0; i<N; ++i)
        {
            file>> loads[i];
            //std::cout << loads[i] << std::endl;
        }
    }
    file.close();
    sumS=totalfit(loads,N);
   
    for (int j=0; j<pop; ++j)
    {
        for (int i=0;i<N;++i)
        {
            origen[j][i]=int(drand()*3);
            //std::cout<<origen[j][i]<<"  ";;
        }
        //std::cout<<std::endl;
    }
    for(int v=0; v<generations;++v)
    {
        for(int j=0;j<pop/2;++j)
        {
            int cut = int(double(drand())*double(N));
            //std::cout << cut << std::endl;
            parents parent=select(origen,loads,N,pop,sumS);
            if(child1 != NULL) delete child1;
            if(child2 != NULL) delete child2;
            child1=breed(mutation,N,origen[parent.p1],origen[parent.p2],cut);
            child2=breed(mutation,N,origen[parent.p2],origen[parent.p1],cut);
            if (fitness(sumS,child1,loads,N)>bestfit)
            {
                for(int h=0;h<N;++h)
                {
                    bestchild[h]=child1[h];
                }
                bestfit=fitness(sumS,child1,loads,N);
            }
            if (fitness(sumS,child2,loads,N)>bestfit)
            {
                for(int h=0;h<N;++h)
                {
                    bestchild[h]=child2[h];
                }
                 bestfit=fitness(sumS,child2,loads,N);
            }
            for(int h=0;h<N;++h)
            {
                nextgen[2*j][h]=child1[h];
                nextgen[2*j+1][h]=child2[h];
            }

        }
        for(int i=0; i<pop; ++i) {
            for(int j=0; j<N; ++j) {
                origen[i][j] = nextgen[i][j];
            }
        }
      //  std::cout << v << " " << bestfit << std::endl;
    }
        int s0=0, s1=0, s2=0;
        for (int i=0; i<N;++i)
        {    
            if (bestchild[i]==0)
            {
                s0+=loads[i];
            }
            if (bestchild[i]==1)
            {
                s1+=loads[i];
            }
            if (bestchild[i]==2)
            {
                s2+=loads[i];
            }
        }
        std::cout << 0 << " " << "s0" <<" "<<s0<<std::endl;
        std::cout << 1 << " " << "s1" <<" "<<s1<<std::endl;
        std::cout << 2 << " " << "s2" <<" "<<s2<<std::endl;
}


