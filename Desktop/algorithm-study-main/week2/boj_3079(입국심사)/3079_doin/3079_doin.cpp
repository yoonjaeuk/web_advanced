/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
using namespace std;
long long each_times[100001];
int main()
{   long long ans;
    int n,m;
    cin >>n>>m;
    
    for(int i=0;i<n;i++){
        cin >>each_times[i];
    }
    
    long long s = 1;
    long long e = 1000000000000000000;
    long long mid = (s + e)/2;
    
    while(1){
        // cout<<s<<" "<<mid<<" "<<e<<"\n";
        if(e-s<=1){
            if(e==s){
                ans = e; break;
            }
            else {
                int count =0;
                bool mustDown;
                for(int i=0;i<n;i++){
                int each_time =  each_times[i];
                count = count + s/each_time;
                if(count>=m){
                mustDown=true;
                break;
            }
            if(mustDown){
                ans = s;
                break;
            }
            else {
                ans = e;
                break;
            }
        }
                break;
            }
        }
        
        long long count=0;
        bool mustDown=false;
        for(int i=0;i<n;i++){
            int each_time =  each_times[i];
            count = count + mid/each_time;
            if(count>=m){
                mustDown=true;
                break;
            }
        }
        if(mustDown){
            e = mid;
            mid = (s+e)/2;
        }
        else {
            s = mid;
            mid = (s+e)/2;
        }
        
    }
    cout<<ans;
    return 0;
}
