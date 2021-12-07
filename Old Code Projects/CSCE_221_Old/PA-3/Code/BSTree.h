#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <queue>
#include <string>

struct Node
{
  int value;
  Node* left;
  Node* right;
  int search_time; //see the problem description

  // Node constructor
  Node(int val = 0, Node* l = nullptr, Node* r = nullptr)
    : value(val), left(l), right(r), search_time(0) {}
};

struct BSTree
{
public:
  BSTree();
  BSTree(const BSTree& other);
  // move constructor
  BSTree(BSTree&& other);
  // copy assignment
  BSTree& operator=(const BSTree& other);
  // move assignment
  BSTree& operator=(BSTree&& other);
  ~BSTree();
  void cut_helper(Node* node );

  inline const Node* get_root() const { return root; }
  inline const int get_size() const { return size; }
  Node* insert(int obj);
  Node* search(int obj);
  void update_search_times();
  float get_average_search_time();
  void inorder(std::ostream& out);
  void print_level_by_level(std::ostream& out);
  Node* insert_helper(Node* t_root, int obj, Node* node_to_insert);
  void search_time_helper(Node* node, int currentLevel);
  Node* search_helper(Node* node, int obj);
  void print_helper(Node* node, std::ostream& out, int level);

private:
  int size;
  Node* root;
  int height;

  int get_total_search_time(Node* node);
  // you can add recursive helper functions to help you
  // this is one is implemented for you:
  void copy_helper(Node*& newNode, const Node* sourceNode);
};

// print a node
std::ostream& operator<<(std::ostream& out, Node& node);

// print a BSTree
std::ostream& operator<<(std::ostream& out, BSTree& tree);

// read in a tree from a file
std::istream& operator>>(std::istream& in, BSTree& tree);


#endif
