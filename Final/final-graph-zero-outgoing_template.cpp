// Find a vertex with 0 outgoing edges
//

#include <iostream>
#include <vector>

using namespace std;

void find_zero_outgoing(vector<vector<int>>& adj, int& hnode)
{

  for (int i = 0; i < adj.size(); i++) {
    int currentAdj = 0;
      for (auto eachVertex : adj.at(i)) {
          
          //cout << currentAdj << " ";
          if (currentAdj == 0) {
            currentAdj = eachVertex;
          }
      }
      if (currentAdj == 0) {
        hnode = i;
        return;
      }
      //cout << endl;
  }
  

  // X X 0 1 2 3 4
  // X X
  // 0   0 0 1 0 1
  // 1   1 0 1 0 0
  // 2   0 0 0 0 0
  // 3   1 0 0 0 1
  // 4   1 1 1 0 0

  
}


int main()
{
  vector<vector<int>> adj = {
           {0,0,1,0,1},
			     {1,0,1,0,0},
			     {0,0,0,0,0},
			     {1,0,0,0,1},
			     {1,1,1,0,0}
  };
  int hnode;
  find_zero_outgoing(adj, hnode);
  if (hnode >= 0)
    cout << "Found vertex: " << hnode << endl;
  else
    cout << "No such vertex found\n";

  return 0;
}
