// Find a vertex with 0 outgoing edges
//

#include <iostream>
#include <vector>

using namespace std;

void find_zero_outgoing(vector<vector<int>>& adj, int& hnode)
{
  // for (auto eachRow : adj) {
  //     cout << eachRow.at(0);
  // }
  cout << "hello" << endl;



  
}


int main()
{
  vector<vector<int>> adj = {{0,0,1,0,1},
			     {1,0,1,0,0},
			     {0,0,0,0,0},
			     {1,0,0,0,1},
			     {1,1,1,0,0}};
  int hnode;
  find_zero_outgoing(adj, hnode);
  if (hnode >= 0)
    cout << "Found vertex: " << hnode << endl;
  else
    cout << "No such vertex found\n";

  return 0;
}
