/*****************
백준 1939번 문제 오답
******************/
#include <iostream>
#include <map>
using namespace std;

int n,m; // n개 node, m개 edge
int s,e; // s - 중량 제한 구하는 경로의 시작 node, e - 중량 제한 구하는 경로의 끝 node;
map<int,int> limit[10001]; // - limit[node1] = {node2 : limit1, node3 : limit2} node1은 node2와 limit1의 중량제한이 있고, node3과는 limit2의 중량제한이 있다.
int max_limit[10001]; // max_limit[index] = 3일 때, 현재 까지 알 수 있는 정보 중에서는, s 노드로 부터. index 노드까지 경로의 중량 제한의 최댓값은 3이다
bool fix[10001]; // fix[index] = true일 때, max_limit[index] 값은 앞으로도 바뀌지 않는다. fix[index] = false일 때, max_limit[index] 값은 바뀔 수 있다.
int main()
{   // 입력 및 초기화
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, d;
        cin >> x >> y >> d;
        if(d > limit[x][y]){
            limit[x][y]=d;
            limit[y][x]=d;
        }
    }  
    cin >> s >> e;

    // s 노드 값 관련하여 변수 초기화
    max_limit[s] = 0;
    fix[s] = true;
    int temp = s; // temp는 현재 노드의 위치

    while(1){
         // fix 되지 않은 max_limit 중에 최댓값을 갖는 노드를 확정하기(최댓값을 갖는 인덱스의 fix값을 true로 바꾸기) 위한 변수, 
         // 왜 max_limit 중에 최댓값를 갖는 인덱스는 fix할 수 있는지는 './README.md'에서 설명
        int max_d = 0; 
        int temp_i; 
        for(auto iter = limit[temp].begin() ; iter != limit[temp].end() ; iter++){ // temp 노드와 연결된 노드 순회
            int candidate = iter->first; // 
            if(fix[candidate]) continue; // 이미 최대 중량제한이 확정된 노드는 확인하지 않는다.
            if(max_limit[temp] == 0) max_limit[candidate] = iter->second; // 한 번도 방문하지 않은 노드의 최대 중량제한은 temp와 candidate 사이 경로의 중량제한과 같음.
            else {
                int new_route_limit = min(max_limit[temp] , iter->second);
                max_limit[candidate] = max(max_limit[candidate] , new_route_limit);
            } // 현재까지의 최대 중량제한을 갖고 있는 노드(이미 방문했던 노드)는, 새로운 경로의 중량제한과 비교하여 큰 것으로 확정한다.
        }
        
        // max_limit[index] 값 중 확정 가능한 최대 중량제한 확정하기.
        for(int i = 1 ; i <= n ; i++){
            if(fix[i]) continue; // 이미 최대 중량제한을 확정한 노드는 확인하지 않는다.
            if(max_limit[i] > max_d ){ // 확정 안된 노드들 중 최대 중량제한 값의 최댓값을 갖는 노드를 찾는다.
                max_d = max_limit[i];
                temp_i = i;
                }
            }
            fix[temp_i] = true; // 해당 노드 확정
            // 확정하는 노드가 목표 노드인 e 노드일 경우 프로그램을 종료한다.
            if(temp_i == e){ 
                cout << max_limit[e];
                return 0;
            }
            temp = temp_i; // 최대 중량 노드를 확정한 노드를 현재 노드로 설정하고 위 과정을 반복한다.
        }
    return 0;
}

