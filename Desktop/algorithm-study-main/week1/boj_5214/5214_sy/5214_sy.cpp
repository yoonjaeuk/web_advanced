#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, M;
int ans = 2147000000;
vector<int> hyper[1005], nV[100005];
bool hyper_vis[1005], n_vis[100005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> M;

    if(N == 1){
        cout << 1;
        return 0;
    }
    for(int i=1; i<=M; ++i){
        for(int j=0; j<K; ++j){
            int t;
            cin >> t;
            hyper[i].push_back(t);
            nV[t].push_back(i);
        }
    }

    queue<pair<int, int>> q;

    n_vis[1] = true;
    for(int i=0; i<nV[1].size(); ++i){
        int hy = nV[1][i];
        hyper_vis[hy] = true;
        for(int nx : hyper[hy]){
            if(n_vis[nx] == true) continue;
            // cout << nx << endl;
            n_vis[nx] = true;
            q.push({nx, 1});
        }
    }

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int cN = cur.first;
        int cnt = cur.second;
        if(cN == N){
            ans = cnt + 1;
            break;
        }
        for(auto nH : nV[cN]){
            if(hyper_vis[nH]) continue;
            hyper_vis[nH] = true;
            for(auto nx : hyper[nH]){
                if(n_vis[nx] == true) continue;
                n_vis[nx] = true;
                q.push({nx, cnt+1});
            }
        }
    }

    ans = ans == 2147000000 ? -1 : ans;
    cout<<ans;

}