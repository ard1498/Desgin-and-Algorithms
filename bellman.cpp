#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
    int f,t,cost;

    edge(int f1,int t1,int cost1){
        f = f1;
        t = t1;
        cost = cost1;
    }
};

int main(){
    int V,E,u,v,c;
    cout<<"\nenter the no of vertices:";
    cin>>V;
    cout<<"\nenter the no of edges:";
    cin>>E;
    vector<edge> edges;
    cout<<"\nenter the edges (from to cost):";
    for(int i = 0;i < E;i++){
        cin>>u>>v>>c;
        edges.push_back(edge(u,v,c));
    }

    unordered_map<int,long long> mp;
    mp[1] = 0;
    for(int i = 2;i < V+1;i++){
        mp[i] = INT_MAX;
    }

    for(int i = 0;i < V-1;i++){
        // first loop for relaxation times..........
        for(int j = 0;j < E;j++){
            //for relaxing edges
            if(mp[edges[j].t] > (mp[edges[j].f]+edges[j].cost)){
                mp[edges[j].t] = (mp[edges[j].f]+edges[j].cost);
            }
        }
    }

    bool flag = false;
    for(int i = 0;i < 1;i++){
        for(int j = 0;j < E;j++){
            if(mp[edges[j].t] > (mp[edges[j].f]+edges[j].cost)){
                flag = true;
            }
        }
    }

    if(flag){
        cout<<"\nnegative cycle so not possible.";
        return 0;
    }

    cout<<endl;
    for(int i = 0;i < V+1;i++){
        cout<<i<<":"<<mp[i]<<endl;
    }
    return 0;
}