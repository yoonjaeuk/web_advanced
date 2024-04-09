#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n,c;
    cin >>n>>c;
    int* arr = new int [n];
    int* dif = new int [n-1];
    cin >>arr[0];
    for(int i=1;i<n;i++){
        cin >>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        dif[i]=arr[i+1]-arr[i];
    }
    
    int min_c=arr[0];
    int max_c=arr[n-1];
    if(n==2)cout<<max_c-min_c;
    else{
        int a=1;
        int b=ceil((max_c-min_c)/(c-1));
        
        int d=(a+b)/2;
        bool plus=false;
        bool activate=false;
        while(1){
           // cout<<a<<" "<<b<<" "<<d<<"\n";
            bool okay=false;
            
            int cnt=0;
            int temp=0;
            
            for(int i=0;i<n-1;i++){
                temp+=dif[i];
                if(temp>=d){cnt++;temp=0;
                }
                
                if(cnt==c-1){okay=true;break;}

            }
            //if(d==4){cout<<okay;}
            if(okay){
                a=d;
                if(d==(d+b)/2) activate = true;
                if(activate){d++;plus=true;}
                
                d=(d+b)/2;
                ///out<<"run";
            }
            else{b=d;
                if(plus){d--;break;}
                if(d==(a+d)/2){d=(a+d)/2;break;}
                d=(a+d)/2;
            }
if(a==b)break;
        }
        
        cout<<d;
        
        
        
        
        
        
    }
    return 0;
}
