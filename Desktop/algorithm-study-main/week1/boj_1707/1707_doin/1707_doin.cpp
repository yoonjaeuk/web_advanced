#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num;
vector<int> graph[20001];
bool visited[20001];
int red[20001];
queue<int> willVisit;
int step1=1;
int step2=0;
bool rd=true;
bool ans=true;

void bfs(int a){
    if(!visited[a])
    {willVisit.push(a);
    
    red[a]=rd+1;
    rd=!rd;
    visited[a]=true;}
     
    while(willVisit.size()!=0){
        int x=willVisit.front();
        willVisit.pop();
        step1--;
        
        for(int i=0;i<graph[x].size();i++){
           
            int y=graph[x].at(i);
            
            if(visited[y]){if(red[y]!=0&&red[y]-1!=rd){
               ans=false;return;}}
            else if(!visited[y]) {willVisit.push(y);visited[y]=true;red[y]=rd+1;step2++;}
            
            
        }
        if(step1==0){step1=step2;step2=0;rd=!rd;}
        
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>num;
    int n,k;
    for(int i=0;i<num;i++){
        cin >>n>>k;
        ans=true;
        for(int j=0;j<=20000;j++){
            graph[j].clear();
            visited[j]=false;
            red[j]=0;
        }
        step1=1;
        step2=0; 
        rd=true;
        while(willVisit.size()!=0){
            willVisit.pop();
        }
        
        for(int j=0;j<k;j++){
            int x,y;
            cin >>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

       
        for(int j=1;j<=n;j++){
            bfs(j);
            while(willVisit.size()!=0){
            willVisit.pop();
            }
            
            step1=1;step2=0;rd=1;

        }
        
        if(!ans)cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;
}

