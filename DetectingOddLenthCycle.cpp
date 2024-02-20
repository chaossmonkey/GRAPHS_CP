// It is obvious that if a graph has an odd length cycle then it cannot be Bipartite.
//  In Bipartite graph there are two sets of vertices such that no vertex in a set is connected with any other vertex of the same set).
//   For a cycle of odd length, two vertices must of the same set be connected which contradicts Bipartite definition.



// If a graph is bipartite it doesn’t contains any odd length cycles, but, 
// if a graph is non-bipartite it surely contains at least one odd length cycle.



// Thus, we conclude that bipartite graphs do not contain odd length cycles.

// But is the converse also true? Do all non-bipartite graphs contain odd length cycles? YES. Here is the proof.

// In any bipartite graph, all the nodes at odd distances from the starting vertex belong to the same set (say set A)
//  And, all the nodes at even distances from the starting vertex also belong to the same set (say set B).

// If a graph is surely non-bipartite, there must be at least one edge connecting two nodes either both of set A, 
// or both of set B. Which means there must be at least one edge connecting either two vertices of odd distance from starting vertex, or two vertices of even distance from starting vertex.

// Let us say that one edge connects two vertices each having an even distance form starting vertex. Then, the length of the cycle including the starting vertex and the two vertices will be, Even + Even + 1 = odd. Thus we have an odd length cycle. A similar proof can be constructed using two vertices, each having an odd distance from starting vertex. Thus,

// Every non-bipartite graph contains at least one odd length cycle.

