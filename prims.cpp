#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int V = 9,N,k,l,w;
    cin>>N;
    map<int,vector<pair<int,int> > > adj;

    for(int i = 0;i < N;i++){
        cin>>k>>l>>w;
        adj[k].push_back(make_pair(l,w));
    }

    vector<int> key(V,INT_MAX);
    vector<int> parent(V,-1);
    vector<bool> visited(V,false);
    priority_queue<pair<int,int> , vector<pair<int,int> > ,greater<pair<int,int> > > pq;
    
    pq.push(make_pair(0,0));
    key[0] = 0;

    while(!pq.empty()){
        int n = pq.top().second;
        pq.pop();
        visited[n] = true;

        for(int i = 0;i < adj[n].size();i++){
            int t = adj[n][i].first;
            int weight = adj[n][i].second;
            
            if( !visited[t] && key[t]>weight){
                key[t] = weight;
                pq.push(make_pair(key[t],t));
                parent[t] = n;
            }
        }
    }

    for(int i = 0;i < V;i++){
        cout<<"\n"<<parent[i]<<"\t"<<i<<"\t"<<key[i];
    }

    return 0;
}