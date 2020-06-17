#include<bits/stdc++.h>
using namespace std;

class Edge {
    protected : 
    int src;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int v , int *parent)
{
    if(parent[v] ==v) {
        return v;
    }

    return findParent(parent[v] , parent);
}
    

void kruskals(Edge *input , int n , int e)
{
    //sort the input array based on their weights
    sort(input , input+e, compare);

    Edge *output = new Edge[n-1];
    int *parent  = new int[n];

    for(int i=0 ; i<n ; i++)
        parent[i]=i;

    int count = 0 ;
    int i=0;
    
    while(count != n-1)
    {
        Edge currentEdge = input[i];

        int sourceParent = findParent(currentEdge.src , parent);
        int destinationParent = findParent(currentEdge.dest , parent);

        if(sourceParent != destinationParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destinationParent;
        }
        i++;
    }

    for(int i=0 ; i<n-1 ; i++)
    {
        if(output[i].src < output[i].dest) {
            cout<< output[i].src << " "<<output[i].dest<<" "
            <<output[i].weight<<endl;
        }
        else
        {
            cout<< output[i].dest << " "<<output[i].src<<" "
            <<output[i].weight<<endl;
        }
        
    }
}

int main()
{
    
    int n,e;
    cin>>n>>e;
    Edge *input = new Edge[e];

    for(int i=0 ; i<e ; i++)
    {
        int s,d,w;
        cin >> s >> d >> w;
        input[i].src = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input , n , e);
    return 0;
}