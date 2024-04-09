
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
int n,k,m;

set<pair<int,int>>edges_group;
int ans;
void bfs(int s,int e){
    queue<pair<int,int>> willVisit;
    bool visited[100001]={0};
    willVisit.push({s,1});
    visited[s]=true;
    while(willVisit.size()!=0){
        int current = willVisit.front().first;
        int cnt = willVisit.front().second;
        
        willVisit.pop();
        if(current==e){ans=cnt;cout<<cnt<<"\n";return;}
        else {
        for(int i=1;i<=n;i++){
            if(i>current&&edges_group.find({current,i})!=edges_group.end()){
                willVisit.push({i,cnt+1});
            }
            else if(current>i&&edges_group.find({i,current})!=edges_group.end()){
                 willVisit.push({i,cnt+1});
            }
        }
    }}
    cout<<-1<<"\n";
}
int main()
{
    cin >>n>>k>>m;
    set<int> edges;
    for(int i=0;i<m;i++){
        edges.clear();
        int x;
        for(int j=0;j<k;j++){
            cin >>x;
            edges.insert(x);
        }
         for(auto iter = edges.begin();iter!=edges.end();iter++){
             int a =*iter;
             for(auto iter2 = edges.begin();iter2!=edges.end();iter2++){
                 int b = *iter2;
                 if(a==b)continue;
                 else{
                    edges_group.insert({min(a,b),max(a,b)});
                 }
             }
         }
    }
    bfs(1,n);

    return 0;
}
