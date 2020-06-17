#include<bits/stdc++.h>
using namespace std; 
  
// Graph class represents a undirected graph 
// using adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing adjacency lists 
    list<int> *adj; 
  
    // A function used by DFS 
    void DFS(int v); 
public: 
    Graph(int v);   // Constructor 
    //~Graph(); 
    void addEdge(int v, int w); 
    void connectedComponents(); 
}; 



Graph::Graph(int v) 
{ 
    V = v; 
    adj = new list<int>[V]; 
} 
  
// Graph::~Graph() 
// { 
//     delete[] adj; 
// } 
  
// method to add an undirected edge 
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 



void Graph::DFS(int v) 
{ 
    // Initially mark all verices as not visited 
    vector<bool> visited(V, false); 
  
    // Create a stack for DFS 
    stack<int> stack; 
  
    // Push the current source node. 
    stack.push(v); 
  
    while (!stack.empty()) 
    { 
        // Pop a vertex from stack and print it 
        v = stack.top(); 
        stack.pop(); 
  
        // Stack may contain same vertex twice. So 
        // we need to print the popped item only 
        // if it is not visited. 
        if (!visited[v]) 
        { 
            cout << v << " "; 
            visited[v] = true; 
        } 
  
        // Get all adjacent vertices of the popped vertex s 
        // If a adjacent has not been visited, then push it 
        // to the stack. 
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) 
            if (!visited[*i]) 
                stack.push(*i); 
    } 
} 

void Graph::connectedComponents() 
{ 
    // Mark all the vertices as not visited 
    vector<bool> visited(V); 
    for(int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v=0; v<V; v++) 
    { 
        if (visited[v] == false) 
        { 
            // print all reachable vertices 
            // from v 
            DFS(v); 
  
            cout << "\n"; 
        } 
    } 
    //delete[] visited; 
} 

  
// Drive program to test above 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(5); // 5 vertices numbered from 0 to 4 
    g.addEdge(1, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
  
    cout << "Following are connected components \n"; 
    g.connectedComponents(); 
  
    return 0; 
} 