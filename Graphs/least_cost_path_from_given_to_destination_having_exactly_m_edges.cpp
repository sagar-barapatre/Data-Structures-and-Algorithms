#include<bits/stdc++.h>

using namespace std;

//Adj List Implementation for Integer Nodes
struct Edge
{
     int src;
     int dest;
     int weight;
}
class Graph {
public:
     int V;

     //Array of Linked Lists of size V, V LL's are there
     list<int> *adjList;

     Graph(int v) {
          V = v;
          adjList = new list<int>[V];
     }
     void addEdge(int u, int v, bool bidir = true) {
          adjList[u].push_back(v);
          if (bidir)
               adjList[v].push_back(u);

     }
};

struct Node
{
     int vertex;
     int depth;
     int node;
};

int BFS(Graph &g, int src, int dest, int m)
{
     queue<Node> q;
     q.push({src, 0, 0});

     int mincost = INT_MAX;

     while (!q.empty())
     {
          Node temp = q.front();
          q.pop();

          int v = temp.vertex;
          int d = temp.depth;
          int cost = temp.weight;

          if (v == src && depth == m)
               mincost = min(mincost, cost);

          if (depth > m)
               break;
          for (auto edge : g.adjList[v])
          {
               q.push(edge.dest, depth + 1, cost + edge.weight);
          }

     }
     return mincost;
}