#include <bits/stdc++.h>
using namespace std;

class graph{
		int V;
		vector<vector<int>> adj;
	public:
		graph(int V){
			this->V = V;
			adj.resize(V, vector<int> (V, 0));
		}
		void addEdge(int u, int v, int wt){
			adj[u][v] = wt;
			adj[v][u] = wt;
		}

		int minDist(vector<int>& dist, vector<bool>& visited){
            int min = INT_MAX, min_index;
            for (int v=0; v < V; ++v)
            if (!visited[v] && dist[v] <= min)
                min = dist[v], min_index = v;
            return min_index;
        }

		void dijkstra(int src){
            vector<int> dist(V, INT_MAX);
            vector<bool> visited(V, false);
            
            dist[src] = 0;
            
            // V-1 relaxations
            for (int i=0; i<V-1; ++i){		
                    int u = minDist(dist, visited);
                    visited[u] = true;
                    
                    for (int v=0; v < V; ++v)
                        if (!visited[v] && adj[u][v] && dist[u] != INT_MAX && (dist[u] + adj[u][v] < dist[v]))
                            dist[v] = dist[u] + adj[u][v];
            }
            cout << "Paths : \n\tVertex\t\tDist from Source\n";
            for (int i=0; i<V; ++i)
                cout << "\t" << i << "\t\t\t" << dist[i] << endl;
        }

};

int main(){
	//Here
	int V = 9;
	graph g(V);
	
	g.addEdge(0, 1, 5);			
    g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 2);			
    g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 9);			
    g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 1);			
    g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 12);		
    g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 11);		
    g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 1);			
    g.addEdge(7, 8, 7);

	int src = 0;
	g.dijkstra(src);
	
	return 0;
}
