#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll search( vector<ll> A,ll k) {

    for(ll i=0;i<A.size();i++)
    {
        if(A[i]==k)
        {
            return i;

        }
    }

    return -1;  
}

int main() {
   
    vector<ll>arr;

    for(ll i=0;i<100000000;i++)
    {
        arr.push_back(i);
    }
    ll target ;
    cout<<"enter the target\n";
    cin>>target ;

 
    clock_t start, end;
    start=clock();

    ll result = search(arr,target);
        end=clock();


    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

        cout<<"time is "<<setprecision(5)<<(double(end-start)/double(CLOCKS_PER_SEC))<<" SECONDS\n";

    return 0;
}