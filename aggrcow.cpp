//problem - https://www.spoj.com/problems/AGGRCOW/

/*
 Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
 
 His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
 Input
 
 t – the number of test cases, then t test cases follows.
 * Line 1: Two space-separated integers: N and C
 * Lines 2..N+1: Line i+1 contains an integer stall location, xi
 Output
 
 For each test case output one integer: the largest minimum distance.
 Example
 
 Input:
 
 1
 5 3
 1
 2
 8
 4
 9
 Output:
 
 3
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>


bool Fc(std::vector<long long> pos, long long x, long long N, long long cowsAmount)
{
    long lastpos = pos[0];
    long placedCows = 1;
    
    for(int i=0;i<N;i++)
    {
        if (pos[i]-lastpos>=x)
        {
            lastpos=pos[i];
            placedCows++;
            if (placedCows==cowsAmount)
            {
                return 1;
            };
        };
    };
    
    return 0;
};

int main()
{
    int cases, N, n2;
    long long c, buffer;
    long long start, end, mid;
    std::cin>> cases;
    std::vector<long long> stalls;
    std::string line;
    
    while(cases--)
    {
        
        scanf("%d%lld",&N,&c);
        
        n2=N;
        
        while(n2--)
        {
            std::cin>>buffer;
            stalls.push_back(buffer);
        }
        std::sort (stalls.begin(),stalls.end());
        
        start=0, end=stalls[N-1]-stalls[0]+1;
        
        while(end-start>1)
        {
            mid=floor((start+end)/2);
            (Fc(stalls, mid, N, c)?start:end)=mid;
        }
        std::cout<<start;
        stalls.clear();
        
    };
};

