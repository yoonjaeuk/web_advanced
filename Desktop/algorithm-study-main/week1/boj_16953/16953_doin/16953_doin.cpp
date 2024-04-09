#include <iostream>
#include <queue>
using namespace std;
long long ans=-1;
void bfs(long long s,long long e, long long cnt){
    queue<pair<int,int>> willVisit;
    willVisit.push({s,cnt});
    while(willVisit.size()!=0){
        long long now = willVisit.front().first;
        long long step = willVisit.front().second;
        willVisit.pop();
        // cout<<now<<" "<<step<<" "<<e<<"\n";
        if(now==e){
            ans = step;
            return;
        }
        if(2*now<=e)
        willVisit.push({2*now,step+1});
        if(now*10+1<=e)
        willVisit.push({now*10+1,step+1});
    }
    return;
}
int main()
{
    long long n,m;
    cin >>n>>m;
    bfs(n,m,1);
    cout<<ans;

    return 0;
}
