#include <iostream>
using namespace std;
int students[100001];
bool success[100001];//0 - not processed , 1 - success 
int n;
int cnt=0;
int cnt_fixed=0;
bool start=true;
 bool lock;
void reset(){
    for(int i=1;i<=n;i++){
        success[i]=0;
    }
    cnt=0;
    cnt_fixed;
}
void dfs(int i,int s){
   
    int a=0;
    if(i==s){
        if(start){start=false;}
        else{lock=true;
        // cout<<"cnt"<<" "<<cnt<<"\n";
        cnt_fixed=cnt;}
    }

    if(success[students[i]]==0){
        cnt++;
        // cout<<i<<"to"<<students[i]<<"\n";
        success[students[i]]=1;
        dfs(students[i],s);
        if(lock) return;
        if(!lock){
            // cout<<students[i]<<"돌리자\n";
            success[students[i]]=0;
            success[i]=2;
        }
        else success[i]=1;
    }
}
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >>num;
    for(int rnd =0;rnd<num;rnd++){
  
        reset();
        cin >>n;
        for(int i=1;i<=n;i++){
            int x;
            cin >>x;
            students[i]=x;
        }
        int ans=n;
        for(int i=1;i<=n;i++){
            if(success[i]==0){
                cnt=0;
                start =true;
                lock=false;
                cnt_fixed=0;
                dfs(i,i);
                //  cout<<i<<" cnt_fixed "<<cnt_fixed<<"\n";
                ans=ans-cnt_fixed;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
