#include <iostream>
#include <algorithm>
#include <vector>

#define X first
#define Y second
using namespace std;

int n, m;
bool vis[1001];
vector<pair<int, int>> adj[1001];
void dfs(int a, int b, int c);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n-1; ++i){
        int s, e, d;   
        cin >> s >> e >> d;
        adj[s].push_back({e, d});
        adj[e].push_back({s, d});
    }

    for(int i=0; i<m; ++i){
        int s, e;
        cin >> s >> e;
        vis[s] = true;
        dfs(s, e, 0);
        vis[s] = false;
    }
}
void dfs(int s, int e, int dist){
    if(s == e){
        cout<<dist<<'\n';
        return;
    }
    for(auto nxt: adj[s]){
        // cout<< s << e<< '\n';
        if(vis[nxt.X]==true) continue;
        vis[nxt.X] = true;
        dfs(nxt.X , e, dist + nxt.Y);
        vis[nxt.X] = false; 
    }
}