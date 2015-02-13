#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cmath>
int main(void)
{
    int t = 1000;  // change this to alter # of iterations
    std::cout<<std::endl;
    double * * grid0 = new double *[101]; // This crap is for declaring the array so it cxan be swapped at the end if a normal array is set the pointers cause a seg fault at line 22
    double * * grid1 = new double *[101];
    for(int i=0; i<101; ++i) grid0[i] = new double[101];
    for(int i=0; i<101; ++i) grid1[i] = new double[101];
    for(int i=0; i<101; ++i) for(int j=0; j<101; ++j) grid0[i][j] = 0;
    bool constants[101][101];
    for(int i=0; i<101; ++i) for(int j=0; j<101; ++j) constants[i][j] = false; //sets conditions for constant voltages
    for(int j=20;j<=80;++j)  // set voltages and makes them constant (initial conditions
    {
        constants[25][j] = true;
        grid0[25][j]=.2; 
        constants[75][j] = true;
        grid0[75][j]=-.2;

    } 

           
    double * * grid = grid0;
    double * * next_grid = grid1;
    for(int n=0;n<t;++n) //iterative loop for method
    {
        for(int i=0; i<101;++i)
        {
            for(int j=0; j<101;++j)
            {
            if(!constants[i][j])
            {   
                int up = i-1;  
                int left = j-1;
                int down = i+1;
                int right = j+1;
                double k = 0; 
            if(up>=0)
                k+=grid[up][j];
            if(down<=100)
                k+=grid[down][j];
            if(left>=0)
                k+=grid[i][left];
            if(right<=100)
                k+=grid[i][right];
            k=.25*k;
            next_grid[i][j]=k;
            }
            else
                next_grid[i][j]=grid[i][j];

            }    

        }
        double * * temp = grid;
        grid = next_grid;
        next_grid = temp;
    }
    for(int i=0;i<101;++i)
    {
        for(int j=0; j<101;++j)
        std::cout<<i<<" "<<j<<" "<<next_grid[i][j]<<std::endl;
    }

}


