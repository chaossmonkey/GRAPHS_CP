#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>      // For priority queues and breadth-first search
#include <stack>      // For stacks and depth-first search
#include <set>        // For sets (sorted containers with unique elements)
#include <map>        // For maps (key-value pairs)
#include <unordered_set>   // For unordered sets (hash-based)
#include <unordered_map>   // For unordered maps (hash-based)
#include <string>     // For string manipulation
#include <cmath>      // For mathematical functions (e.g., sqrt, pow)
#include <iomanip>    // For output formatting (e.g., setw, setprecision)
#include <bitset>     // For bit manipulation
#include <functional> // For function objects and lambdas
#include <numeric>    // For accumulate and other numeric operations
#include <deque>         // Double-ended queue
#include <list>          // Doubly linked list
#include <forward_list>  // Singly linked list

using namespace std;


class Graph
{
   int V;
   vector<vector<int>> adj;
public:
   Graph(int v)
   {
    this->V = v;
    adj.resize(V);
   }
   
   void addEdge(int v1,int v2)
   {
    adj[v1].push_back(v2);
    adj[v2].push_back(v1); ///comment this if  its unidrectional graphs
   }


  void printAdjacencyList()
  {

    for(int i=0;i<V;i++)
    {
        cout << "Adjacency list of vertex " << i << ":\n";
            for (const auto& neighbor : adj[i]) {
                cout << "-> " << neighbor << endl;
            }
    }
  }

  void dfs(int src)
  {
    bool*visited =new bool[V]{0};
    dfsHelper(src,visited);

  }

    void bfs(int source)
    {

    	bool*visited=new bool[V]{0};
    	queue<int> qu;
    	qu.push(source);
    	visited[source]=1;

    	while(!qu.empty())
    	{
    		int front=qu.front();
    		cout<<front<<endl;
    		qu.pop();

    		for(auto nbr:adj[front])
    		{
    			if(visited[nbr]==0)
    			{
    				qu.push(nbr);
    				visited[nbr]=1;
    			}
    		}

    	}
  
    }
  
  void dfsHelper(int src,bool* visited)
  {
    visited[src]=true;

    cout<<src<<endl;

    for(auto& it :adj[src])
    {
        if(visited[it]==false)
        {
            dfsHelper(it,visited);
        }
    }


  }
};

int main()
{

      Graph g(6);
    g.addEdge(4, 1);
    g.addEdge(1, 5);
    g.addEdge(4, 3);
    g.addEdge(2, 3);


    g.dfs(1);
    return 0;
}
