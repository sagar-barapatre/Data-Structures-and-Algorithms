#include<bits/stdc++.h>

using namespace std;

//Adj List Implementation for Integer Nodes
class Graph{
	int V;	

	 //Array of Linked Lists of size V, V LL's are there
     list<int> *adjList;
public:
     Graph(int v){
     	V = v;
     	adjList = new list<int>[V];
     }
     void addEdge(int u,int v,bool bidir = true) {
     	adjList[u].push_back(v);
     	if(bidir)
     		adjList[v].push_back(u);
     	
     }
     void printAdjList(){
     	for(int i=0;i<V;i++){
     		cout<<i<<"->";
     		for(int node:adjList[i]){
     			cout<<node<<",";
     		}
     		cout<<endl;
     	}
     }

     void bfs(int src,int dest)
     {
     	//Traverse all the nodes of the graph
     	queue<int> q;
     	vector<bool> visited(V+1,0);
     	vector<int> dist(V+1, 0);
     	vector<int> parent(V+1, -1);

     	// for(int i=0;i<V;i++){
     	// 	parent[i] = -1;
     	// }

     	q.push(src);
     	visited[src] = true;



     	while(!q.empty()){
     		int node = q.front();
     		cout<<node<<" ";
     		q.pop();

     		for(int neighbour:adjList[node]){
     			
     			if(!visited[neighbour]){
     				q.push(neighbour);
     				visited[neighbour] = true;
     				dist[neighbour] = dist[node]  + 1;
     				parent[neighbour] = node;
     			}
     		}
     	}
     	cout<<endl;
     	//Print the distances of every node from source
     	// for(int i=0;i<V;i++){
     	// 	//cout<<i<<"node having dist "<<dist[i]<<endl;
     	// }

     	cout<<"Shortest dist is "<<dist[dest]<<endl;
     	cout<<"Shortest path is ";

     	int temp = dest;
     	while(temp!=-1){
     		cout<<temp<<"<--";
     		temp = parent[temp];
     	}
     }
};

int main(){
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(3,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(3,4);
	g.printAdjList();
	g.bfs(0,5);
	return 0;
}