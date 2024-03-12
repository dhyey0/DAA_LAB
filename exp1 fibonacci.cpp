#include<bits/stdc++.h>
using namespace std;
long long fib(int a)
{
    if( a==1 )
    {
        long long k=0;
        return k;
    } 
    else if(a==2)
    {
        long long k=1;
        return k;
    }
    else
    {
        return(fib(a-1)+fib(a-2));
    }

}
int main()
{
    clock_t start,end;
    start=clock();
    long long k=fib(29);
    end=clock();
    cout<<"45th fibonacci umber is "<<k<<"\n";
    cout<<"time is "<<setprecision(5)<<double(end-start)/double(CLOCKS_PER_SEC)<<" SECONDS\n";
    return 0;
}