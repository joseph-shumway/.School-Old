#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <ctype.h>


using namespace std;
using std::string;
using std::cout;
using std::endl;

//edits to this are likely not needed
template <class T>
struct Vertex {
  T label; // unique int for a vertex
  vector<T> adj_list;
  int indegree; // Part 2: number of nodes pointing in
  int top_num; // Part 2: topological sorting number
  Vertex(T l) : label(l) {top_num = 0;} //Part 1
  // You may include default constructor optionally.
};

// optional, but probably helpful
// template <class T>
// ostream& operator<<(ostream &o, Vertex<T> v){};

// std::priority_queue may take takes three template parameters: <Type, ContainerType, Functor>
// syntax for custom compare functor follows
// Refer the instructions PDF last section for more information

// template<class T>
// class VertexCompare
// {
// public:
//   bool operator()(Vertex<T> v1, Vertex<T> v2){
//     //todo - implement here
//     return false;
//   }
// };

template <class T>
class Graph {
private:
  //c++ stl hash table
  std::unordered_map<T, Vertex<T> > node_set;

  //Use other data fields if needed
public:
  Graph() {};  //No modification needed to default constructor. Can be used optionally if needed.
  ~Graph() {}; //No modification needed to destructor. Can be used optionally if needed.

  // build a graph - refer the instructions PDF for more information.
  void buildGraph(istream &input){
    string line = "";
    stringstream ss;
    
    
    while (std::getline(input, line)) {
      T current_num;
      T current_value;

      // pass line to our stringstream so we can give each part to our temp_num
      ss.clear();
      ss.str(line);
      // if (!isdigit(ss.str().at(0))) {
      //   throw std::invalid_argument("The input file does not contain numbers");
      // }
      
        
      // grab first number for our node
      ss >> current_num;


      if (node_set.find(current_num) == node_set.end()) {
        Vertex<T>* temp_Vertex = new Vertex<T>(current_num);
        
        
        while (ss >> current_value)
        {
          // add adjacency nodes and print
          temp_Vertex->adj_list.push_back(current_value);
          //cout << "AL [" << temp_Vertex->label << "] " << current_value << endl;
        }

        // add our vertex to the unordered_map
        node_set.emplace(make_pair(current_num, *temp_Vertex));
      } 
    }

    //displayGraph(cout);
  }

  // display the graph into o - refer the instructions PDF for more information.
  void displayGraph(ostream& o){
    for (auto const &each_pair : node_set) {

      // output label "1 "
      o << each_pair.first << ":";

      // output the adjacent vertices
      for (auto each_element : each_pair.second.adj_list) {
          o << each_element << " ";
      }
      o << endl;
    }
  }

  //return the vertex at label, else throw any exception  - refer the instructions PDF for more information.
  Vertex<T> at(T label){
    if (node_set.find(label) == node_set.end()) {
      throw std::invalid_argument("Invalid label");
    } else {
      return node_set.find(label)->second;
    }
    
  }

  //return the graph size (number of verticies)
  int size(void){
    return node_set.size();
  }

  // topological sort
  // return true if successful, false on failure (cycle)
  bool topological_sort(void){
    return false;
  } // Part 2

  // find indegree
  void compute_indegree(void){
    
    // reset indegree values
    for (auto &each_pair : node_set) {
      each_pair.second.indegree = 0;
    }

    // set indegree values
    for (auto &each_pair : node_set) {
      for (auto each_adj_element : each_pair.second.adj_list) {
          node_set.find(each_adj_element)->second.indegree++;
      }
    }

    for (auto &each_pair : node_set) {
      cout << each_pair.second.label << ":   " << each_pair.second.indegree << endl;
    }
  } // Part 2

  // print topological sort into o
  //  if addNewline is true insert newline into stream
  void print_top_sort(ostream& o, bool addNewline=true) { 
    queue<std::pair<T, Vertex<T> > > q;
    int counter = 0;
    

    // q.extend([v in graph if v.indegree == 0])

    // while not q.isEmpty():
    //     v = q.pop()
    //     v.top_num = counter
    //     counter += 1

    //     for adj_v in v.adj_list:
    //         adj_v.indegree -= 1
    //         if adj_v.indegree == 0:
    //             q.push(adj_v)

    // if counter != graph.size():
    //     raise CycleDetectedException()
    
    if(addNewline){o << '\n';};
  }; // Part 2
};

#endif
