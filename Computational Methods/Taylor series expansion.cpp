#include <iostream>
#include <math.h>
using namespace std;

int factorial(int n)
{
    if(n==1)
    {
        return n;
    }
    else
    {
        n=n*factorial(n-1);
    }
}

int main() 
{
    float x;
    cout<<"Enter the value of x approaching 0:-";
    cin>>x;
    int limit;
    cout<<"Enter number of terms upto which expansion has to be performed:-";
    cin>>limit;
    float value=0.0;
    int i=0;
    while(i<limit)
    {
        if(i%2==0)
        {
            value += pow(x,2*i+1)/factorial(2*i+1);
        }
        else
        {
            value -= pow(x,2*i+1)/factorial(2*i+1);
        }
        i++;
    }
    cout<<"Taylor series expansion for x equals "<<x<<" gives sin(x) as "<<value<<"\n";
    
    return 0;
}