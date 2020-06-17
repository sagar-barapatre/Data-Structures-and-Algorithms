#include<bits/stdc++.h>

using namespace std;


class Graph
{
	int V;
	list<int> *adjList;

	public:
	Graph(int v)
	{
		V = v;
		adjList = new list<int>[V];
	}

	void addEdge(int u, int v)
	{
		adjList[u].push_back(v);
	}

	bool isCyclic(int src)
	{
		vector<bool> visited(V+1, 0);
		vector<int> parent(V+1, -1); 


		queue<int> q;
		visited[src]=true;
		q.push(src);

		while(!q.empty())
		{
			int u = q.front();
			q.pop();

				for(auto node: adjList[u])
				{
					if(!visited[node])
					{
						visited[node] = true;
						q.push(node);
						parent[node] = u;
					}
					else if(parent[u]!=node)
					return true;
					
				}
		}
		return false;
	}

	bool isDisconnected(int src)
	{
		vector<bool> visited(V, false);

		for(int i=0 ; i<V ; i++)
		{
			if(!visited[i] && isCyclic(i))
			return true;
		}
		return false;
	}
};

int main()
{
	Graph g(4);

	g.addEdge(1,2);
	g.addEdge(1,0);
	g.addEdge(2,0);
	g.addEdge(0,3);
	g.addEdge(3,4);

	if(g.isDisconnected(3)) //We can take any node in the parameter
	cout<<"Yes\n";
	else
	cout<<"No\n";
	return 0;
}