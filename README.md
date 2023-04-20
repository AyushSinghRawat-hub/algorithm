# Algorithm's
## Bellman-Ford Algorithm
A weighted network can have edges with negative weights, but the Bellman-Ford method, a dynamic programming technique, can still identify the shortest path between a source node and all other nodes in the graph. In order to find the best solution, the algorithm iteratively relaxes the graph's edges.
## BFS algorithm
 Breadth-First Search algorithm used to traverse or search a graph or tree data structure. It starts at the root node and explores all the neighbor nodes at the current depth before moving on to the next depth level. The algorithm uses a queue to store the nodes that need to be visited.
## Breadth-first search (BFS)
-A graph traversal technique known as breadth-first search (BFS) explores all of a graph's vertices in breadth-first order, or all of the vertices at the same level before going on to the vertices at the next level.<br>
<br>
-The BFS method begins at a certain source vertex and investigates every vertex that may be reached from it. Then it investigates the vertices at the next level, those that are two edges away from the source, or the next level of vertices. This step is carried out by the algorithm until each vertex has been reached.<br>
<br>
-The vertices that need to be investigated are kept in a queue by the BFS algorithm. The source vertex is first added to the queue. Then, while there are still items in the queue, a vertex is dequeued and its neighbours are explored. A neighbour is added to the queue if it hasn't been visited yet.<br>
<br>
-Since BFS is a complete and ideal method, it will always identify the shortest route in an unweighted network between the source vertex and every other vertex. However, BFS might not discover the shortest path in a weighted graph.
The temporal complexity of BFS is O(V+E), where V denotes the number of graph vertices and E is the number of graph edges. To store the queue and the visited vertices, O(V) more space is needed.<br>
<br>
