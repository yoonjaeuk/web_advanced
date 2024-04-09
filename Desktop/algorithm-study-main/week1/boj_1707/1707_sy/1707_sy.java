/*
 * 이분 그래프란?
 * 모든 꼭짓점은 2가지 색(빨강, 파랑)으로 칠해지는데, 모든 변의 빨강, 파랑 꼭짓점이 포함되도록 해야한다.
 * 
 * 1<= V <= 20,000 인접행렬일 경우, 200000 * 200000 총 4억 크기의 2차원 배열이 필요하므로 x
 * 간선그래프로 풀이
 * 
 * 색을 저장할 수 있는 1차원 배열 필요
 * 각 정점은 1차원 배열의 인덱스가 됨
 * 0으로 값을 초기화하여 0일 경우, 아직 방문하지 않았다는 것을 체크할 수도 있음
 * 
 * 1. 값을 확인하여 0일 경우 방문하지 않았다는 것을 체크
 * 1-2. 방문한 곳이라면 인접한 정점들이 모두 다른 색을 가지고 있는지 확인(?)
 * 2. 이전 정점과 반대 값으로 값을 변경 1이라면 -1, -1이라면 1 -> 이전 정점의 값 저장이 필요?
 * 3. 값을 변경한 후,자신이 인접한 정점이 자신과 반대되는 값을 가지고 있는지 체크. 
 * 3-2. 이 때, 0이라면 큐에 자신의 값과 함께 삽입하고, 반대되는 값이 아닌 동일한 값을 가지고 있다면 이분 그래프가 아니므로 더 이상 확인 필요 x
 * */

import java.io.*;
import java.util.*;
public class Main {
	
	static int T;// 테스트케이스  
	static int V; // 정점 개수
	static int E; // 간선 개수 
	
	static ArrayList<Integer>[] list; // 간선리스트 
	static int[] colors; // 정점 색상 저장 배열 
	static Queue<Integer> q;
	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = null;
	static boolean isBipartite = true;
	public static void main(String[] args) throws Exception{
		T = Integer.parseInt(reader.readLine());
		for(int tc=1; tc<=T; ++tc) {
			st = new StringTokenizer(reader.readLine(), " ");
			V = Integer.parseInt(st.nextToken());
			E = Integer.parseInt(st.nextToken());
			
			isBipartite = true;
			list = new ArrayList[V+1];
			colors = new int[V+1]; // 1부터 시작하는 정점번호를 Index로 사용 
			
			for(int i=0; i<V+1; ++i) {
				list[i] = new ArrayList<Integer>();
			}
			
			for(int e=0; e<E; ++e) {
				st = new StringTokenizer(reader.readLine(), " ");
				int start = Integer.parseInt(st.nextToken());
				int end = Integer.parseInt(st.nextToken());
				list[start].add(end);
				list[end].add(start);
			}
			
			for(int i=0; i<V+1; ++i) {
				if(colors[i]==0) {
					bfs(i, 1); // 정점, 컬러 1
				}
				if(!isBipartite) break;
					
			}
			
			System.out.println(isBipartite ? "YES" : "NO");
			
			
		}// end for T
	}//end main

	private static void bfs(int v, int color) {
		q = new LinkedList<>();
		q.offer(v);
		colors[v] = color;
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int nextV:list[cur]) {
				if(colors[nextV]==0) {
					q.offer(nextV);
					colors[nextV] = colors[cur] * -1;
				}else if(colors[cur]+colors[nextV]!=0) {
					isBipartite = false;
					return;
				}
			}
		}
		
	}// end bfs

}