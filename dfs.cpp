#include<bits/stdc++.h>
using namespace std;

void dfs(int V, vector<int>*edges){
	bool visited[V];
	memset(visited, false, sizeof visited);
	visited[0]= true;
	stack<int> stk;
	stk.push(0);
	while(!stk.empty()){
		int curr= stk.top();
		stk.pop();
		
		cout<<curr+1<<" ";
		for(int j=0; j<edges[curr].size(); j++){
			if(!visited[edges[curr][j]]){
				stk.push(edges[curr][j]);
				visited[edges[curr][j]]= true;
			}
		}
	}
	cout<<endl;
}
int main(){
	int V, E;
	cin>>V>>E;
	vector<int>* edges= new vector<int>[V];
	
	for(int i=0; i<E; i++){
		int x, y;
		cin>>x>>y;
		edges[x-1].push_back(y-1);
		edges[y-1].push_back(x-1);
	}
	dfs(V, edges);
}
