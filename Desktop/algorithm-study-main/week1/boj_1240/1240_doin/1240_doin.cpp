/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;// n: node번호, m : 구해야하는 순서쌍의 개수
vector<pair<int,int>> edges[1001];
int answer_dist=0;

void bfs(int s,int e){
    queue<vector<int>> willVisit; //
    bool visited[1001]={0,};
    visited[s]=true;
    for(int i=0;i<edges[s].size();i++){
        int next =edges[s].at(i).first;
        int dist = edges[s].at(i).second;
        int step =1;
        // cout<<next<<"까지"<<dist<<"\n";
        vector<int> a;
        if(visited[next])continue;
        visited[next]=true;
        a.push_back(next);
        a.push_back(dist);
        visited[next]=true;
        willVisit.push(a);
    }
    while(willVisit.size()!=0){
        vector<int> current = willVisit.front();
        willVisit.pop();
        int current_node = current.at(0);
        int total_d = current.at(1);
        if(current_node==e){answer_dist=total_d;return;}
        for(int i=0;i<edges[current_node].size();i++){
            int next_node = edges[current_node].at(i).first;
            int next_dist = edges[current_node].at(i).second;
    
            if(!visited[next_node]){visited[next_node]=true;
            vector<int> next;
            next.push_back(next_node);
            next.push_back(next_dist+total_d);
            willVisit.push(next);}
        }
    }
        
        
        
        
    

}
int main()
{
    cin >> n >>m; 
    for(int i=0;i<n-1;i++){
        int x,y,d;
        cin >>x>>y>>d;
        edges[x].push_back({y,d});
        edges[y].push_back({x,d});
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >>x>>y;

        bfs(x,y);
        cout<<answer_dist<<"\n";
    }
    return 0;
}
