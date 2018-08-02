//problem - https://www.spoj.com/problems/COINS/

#include <iostream>


unsigned long long int exchange(unsigned long long int val) //solved by recurrency
{
    if(((val/2)+(val/3)+(val/4))<=val)
    {
        return val;
    }
    else
    {
        val=exchange(val/2)+exchange(val/3)+exchange(val/4);
        return val;
    };
};


int main()
{
    unsigned long long int coinValue;
    while(std::cin>>coinValue){
        std::cout<<exchange(coinValue)<<std::endl;
    };
    
    return 0;
}
