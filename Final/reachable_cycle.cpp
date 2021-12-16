/*
  INSTRUCTIONS:

  A cycle is a closed path within a graph. Cycles have many practicle implications.
  Your task is to detect if a cycle is reachable from a given vertex in a directed graph. 
  More formally, given a directed graph in adjacency list form, determine if there are edges
  connecting some sequence of verticies (v1, v2) (v2, v3) ... (v(n-1), vn) (vn, v1) which is
  in the subgraph reachable from a starting vertex v_start. That is, starting on vertex v_start,
  you can travel to vertex with a cycle.
  
  Complete the reachable_cycle function below. Develop the MOST EFFICIENT algorithm to solve
  this problem.

  COMPILE WITH:
  g++ -std=c++17 reachable_cycle.cpp

  EXAMPLES:

  For instance, consider the following graph:
  
        ┌─────────────────────┐
        ▼                     │
  ┌─────7   ┌───────────┐     │
  ▼         ▼           │     │
  5 ◄────── 1──────┐    2     │
  ▲                │    ▲     6
  │                │ ┌──┘     │
  │                │ │        │
  └──────── 3      └►4◄───────┘
            ▲        │
            └────────┘
  
  reachable_cycle(1): Should return true since node 1 is part of a cycle (1 -> 4 -> 2 -> 1)
  reachable_cycle(6): Should return true since 6 -> 4 leads to a cycle (4 -> 2 -> 1 -> 4)
  reachable_cycle(3): Should returns false since there isn't a cycle reachable from node 3

  If the above graphs do not render correctly, see the gist (link in Canvas) for a PNG.

  REMINDERS:

  Similar to your programming assignment, the unordered_map "node_set" holds (label, Vertex)
  pairs where all vertices are labeled with integers.

  The following is for refernce only. You may or may not need the following data structures in
  your solution.
  
  Iterating though maps using range based loops:
  ---------------------------------------------

  for(const auto & label_vertex_pair : node_set) {
        int label = label_vertex_pair.first;      // Get label
        Vertex vertex = label_vertex_pair.second; // Get vertex
  }

  Hashing:
  -------

  You may need a structure to facilitate hashing. You can use unordered_map if needed:
  unordered_map<int, int> map; // Maps integer keys to integer values
  map.insert({4, 5});          // Insert 5 with the key 4
  cout << map[4] << endl;      // Lookup value which corresponds to key 4

  auto search = map.find({2, 5}); // Search a hash map for 2
  if(search != map.end()) {       // Test if a key value pair exists for 2
    cout << search->second << endl; // 5
  } else {
    cout << "Not found" << endl;
  }

  Stacks and Queues:
  ------------------
  You may wish to use a stack or queue to memorize an ordering.

  stack<int> stack;
  stack.push(4);
  stack.push(2);
  cout << stack.empty() << endl; // false
  cout << stack.top() << endl;   // 2
  stack.pop();
  cout << stack.top() << endl;   // 4
  stack.pop();
  cout << stack.empty() << endl; // true

  queue<int> queue;
  queue.push(4);
  queue.push(2);
  cout << queue.empty() << endl; // false
  cout << queue.front() << endl; // 4
  queue.pop();
  cout << queue.front() << endl; // 2
  queue.pop();
  cout << queue.empty() << endl; // true

*/

#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <unordered_map>
#include <istream>
using namespace std;

struct Vertex {
  int label;
  vector<int> adj_list;

  // You may use the following data flag in your program
  // It is not guaranteed to start at zero but you may call zero_data_flag to zero it
  // We ignore it's value for grading purposes
  int data;
};

class Graph {
  unordered_map<int, Vertex> node_set; 
  
  /* Sets the data flag to zero */
  void zero_data_flag() {
    for(auto & node_vertex_pair : node_set) {
      node_vertex_pair.second.data = 0;
    }
  }

  /* START_SOLUTION */

  /* You may add private helpers FUNCTIONS if necessary */
  /* Do NOT add private or global variables */

  
  public:

  bool reachable_cycle(int starting_label) {
    // Complete the following function

  zero_data_flag();

  queue<int> q;

  Vertex currentVertex = node_set.at(starting_label);

  unordered_map<int, bool> visitedVertices;
  for (auto each : node_set) {
      visitedVertices.insert({each.first, false});
  }

  // handles if there are no outward edges from given label
  if (node_set.at(starting_label).adj_list.size() == 0) {
    return false;
  }

  visitedVertices.at(starting_label) == true;
  

  int numVisited = 0;

  while(numVisited < node_set.size()) {
    
    // handles if there are no outward edges from current label
    if (node_set.at(currentVertex.label).adj_list.size() == 0) {
      return false;
    }

    for (auto eachVertex : currentVertex.adj_list) {
      if (visitedVertices.at(eachVertex) == true) {
        return true;
      } else {
        visitedVertices.at(eachVertex) = true;
      }
      
    }
    numVisited++;
    currentVertex = node_set.at(currentVertex.adj_list.at(0));

  }
  








    return false;
  }
  
  
  /* END_SOLUTION */ 

  // for testing
  public:
  friend Graph buildGraph(istream &input);
};