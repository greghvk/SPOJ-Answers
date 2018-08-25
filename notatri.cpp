//problem - https://www.spoj.com/problems/NOTATRI/

/*
 You have N (3 ≤ N ≤ 2,000) wooden sticks, which are labeled from 1 to N. The i-th stick has a length of Li (1 ≤ Li ≤ 1,000,000). Your friend has challenged you to a simple game: you will pick three sticks at random, and if your friend can form a triangle with them (degenerate triangles included), he wins; otherwise, you win. You are not sure if your friend is trying to trick you, so you would like to determine your chances of winning by computing the number of ways you could choose three sticks (regardless of order) such that it is impossible to form a triangle with them.
 
 Input
 
 The input file consists of multiple test cases. Each test case starts with the single integer N, followed by a line with the integers L1, ..., LN. The input is terminated with N = 0, which should not be processed.
 
 Output
 
 For each test case, output a single line containing the number of triples.
 
 Input:
 3
 4 2 10
 3
 1 2 3
 4
 5 2 9 6
 0
 
 Output:
 1
 0
 2
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

//fc returns 1 if you can't form triangle (degenerate included) from three sticks, where thirdStick is always the longest
bool fc(long firstStick, long secondStick, long thirdStick){
    if(firstStick+secondStick<thirdStick){
        return 1;
    }else return 0;
};


int main(){
    
    long n, start, end, mid = 0;
    long buffer;
    std::vector<long> sticks;
    std::cin>>n;
    
    while(n)
    {
        long long searchedCases = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%ld", &buffer);
            sticks.push_back(buffer);
        };
        std::sort(sticks.begin(), sticks.end());
        
        for (int i=1; i<n-1; i++)
        {
            for (int j=0; j<i; j++)
            {
                
                
                start=i+1, end=n-1;
                mid = floor((start+end)/2);
                
                //using binary search to find leftmost third stick that you can't form triangle with - all the following ones will be right too
                
                while (end-start>1)
                {
                    ((fc(sticks[i], sticks[j], sticks[mid])?end:start)=mid);
                    mid = floor((start+end)/2);
                };
                
                if(end-1!=i && fc(sticks[i], sticks[j], sticks[end-1]))
                {
                    searchedCases+=n-end+1;
                    
                }else if(fc(sticks[i], sticks[j], sticks[end]))
                {
                    searchedCases+=n-end;
                    
                };
                
                
                
            }
        }
        std::cout<<searchedCases<<std::endl;
        sticks.clear();
        std::cin>>n;
    }
    
    return 0;
};
