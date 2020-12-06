/*


We initialize distances to all vertices as minus infinite and distance to source as 0,
then we find a topological sorting of the graph.
 Topological Sorting of a graph represents a linear ordering of the graph
Once we have topological order (or linear representation),
 we one by one process all vertices in topological order.
 For every vertex being processed,
 we update distances of its adjacent using distance of current vertex.


Following is complete algorithm for finding longest distances.
1) Initialize dist[] = {NINF, NINF, ….} and dist[s] = 0 where s is the source vertex. Here NINF means negative infinite.
2) Create a toplogical order of all vertices.
3) Do following for every vertex u in topological order.
………..Do following for every adjacent vertex v of u
………………if (dist[v] < dist[u] + weight(u, v))
………………………dist[v] = dist[u] + weight(u, v)
*/