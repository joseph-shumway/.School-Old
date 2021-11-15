#include "BSTree.h"

#include <iostream>
#include <queue>

using namespace std;

///////////////////////////////////
// Already Implemented Functions //
///////////////////////////////////

// These functions are already implemented for you. Scroll below to
// see the functions that you have to implement 

// constructors
BSTree::BSTree(): size(0), root(nullptr), height(0) {}

// input / output operators
ostream& operator << (ostream & out, BSTree & tree) {
    tree.print_level_by_level(out);
    return out;
}

ostream& operator << (ostream & out, Node & node) {
    return out << node.value << "[" << node.search_time << "]";
}

istream& operator >> (istream & in , BSTree & tree) {
    /*
      take input from the in stream, and build your tree
      input will look like
      4 
      2 
      6 
      1 
      3 
      5 
      7
    */
    int next;
    while ( in >> next) {
        tree.insert(next);
    }
    return in;
}

// Example recursive function
// If you try to use it without care, you will get a memory leak.
void BSTree::copy_helper(Node * & newNode, const Node * sourceNode) {
    //Don't copy if the node is nullptr
    if (sourceNode == nullptr)
        return;

    //Change the new node to a copy of sourceNode
    newNode = new Node(sourceNode -> value);
    //Copy over the search cost
    newNode -> search_time = sourceNode -> search_time;

    //Copy left subtree
    if (sourceNode -> left != nullptr)
        copy_helper(newNode -> left, sourceNode -> left);
    //Copy right subtree
    if (sourceNode -> right != nullptr)
        copy_helper(newNode -> right, sourceNode -> right);
}

// recursive function
int BSTree::get_total_search_time(Node * node) {
    if (node != nullptr) {
        return node -> search_time + get_total_search_time(node -> left) + get_total_search_time(node -> right);
    }
    return 0;
}

// implemented
float BSTree::get_average_search_time() {
    int total_search_time = get_total_search_time(root);
    if (total_search_time == 0)
        return -1;

    return ((float) total_search_time) / size;
}

///////////////////////////////////
//     Functions to Implement    //
///////////////////////////////////

// These are the functions you should implement
// Feel free to call the functions above or create new helper functions

// copy constructor
BSTree::BSTree(const BSTree & other) {
    root = nullptr;
    size = 0;
    
    if (other.size != 0) {
        //cout << "copying to this tree" << endl;
        copy_helper(this -> root, other.root);
        size = other.size;   
    }

}

// move constructor
BSTree::BSTree(BSTree && other) {

    root = other.root;
    size = other.size;

    other.root = nullptr;
    other.size = 0;
    
}

//copy assignment
BSTree & BSTree::operator = (const BSTree & other) {
    if (this != &other) {
        cut_helper(root);
        root = NULL;
        copy_helper(this->root, other.root);
        size = other.size;
    }
    return *this;
}

// move assignment
BSTree & BSTree::operator = (BSTree && other) {
    if (this != &other) {
        cut_helper(root);
        root = nullptr;
        root = other.root;
        size = other.size;
        other.root = nullptr;
        other.size = 0;
    }
    
    return *this;
}

// destructor
BSTree::~BSTree() {
    // Make sure to call delete on every node of the tree
    // You can use a recursive helper function to do this
    cut_helper(root);
}

void BSTree::cut_helper(Node* node) {
    if (node != nullptr) {
        cut_helper(node->left);
        cut_helper(node->right);
        delete node;
    }
}

Node * BSTree::insert(int obj) {
    /* insert a node into the tree
    first find where the node should go
    then modify pointers to connect your new node */
    Node * node = new Node(obj);

    if (root == nullptr) {
        //cout << "Initial Insert: " << obj << endl << endl;
        node->search_time = 1;
        root = node;
        size++;
        return root;
    }

    size++;
    node->search_time++;

    return insert_helper(root, obj, node);
}

Node * BSTree::insert_helper(Node * t_cursor, int obj, Node * node_to_insert) {
    //cout << "Current Node: " << t_cursor->value << endl;
    // traverse tree to right if obj > current node, inserting node if necessary
    // cout << "Current node: " << t_cursor->value << endl;
    // cout << "Current obj : " << obj << endl;
    
    
    if (obj > t_cursor -> value) {

        // insert node to right if right node doesnt currently exist
        if (t_cursor -> right == nullptr) {
            t_cursor -> right = node_to_insert;
            node_to_insert->search_time++;
            if (node_to_insert->search_time > height) {
                height = node_to_insert->search_time;
            }
            // cout << "--o Insert to right: " << t_cursor->value << " -> " << obj << endl << endl;
            return node_to_insert;

            // else, traverse onward
        } else {
            // cout << "--> Moving right!   Value=" << t_cursor -> value << "    Right=" << t_cursor -> right -> value << endl;
            t_cursor = t_cursor -> right;
            node_to_insert->search_time++;
            if (node_to_insert->search_time > height) {
                height = node_to_insert->search_time;
            }
            // cout << endl;
            insert_helper(t_cursor, obj, node_to_insert);
            
            return node_to_insert;
        }

    }

    // traverse tree to left if obj < current node, inserting node if necessary
    if (obj < t_cursor -> value) {

        // insert node to right if right node doesnt currently exist
        if (t_cursor -> left == nullptr) {
            t_cursor -> left = node_to_insert;
            node_to_insert->search_time++;
            if (node_to_insert->search_time > height) {
                height = node_to_insert->search_time;
            }
            // cout << "o-- Insert to left: " << obj << " <- " << t_cursor->value << endl << endl;
            return node_to_insert;
            // else, traverse onward
        } else {
            // cout << "Going left!   Value=" << t_cursor -> value << "    Left=" << t_cursor ->left -> value << endl;
            t_cursor = t_cursor -> left;
            node_to_insert->search_time++;
            if (node_to_insert->search_time > height) {
                height = node_to_insert->search_time;
            }
            // cout << endl;
            insert_helper(t_cursor, obj, node_to_insert);
            return node_to_insert;
        }
    }

    return node_to_insert;
}

Node * BSTree::search(int obj) {
    /* recursively search down the tree to find the node that contains obj
    if you don't find anything return nullptr */

    return search_helper(root, obj);
}

Node* BSTree::search_helper(Node* node, int obj) {
    if (node != nullptr) {
        search_helper(node->left, obj);
        search_helper(node->right, obj);
        if (node->value == obj) {
            return node;
            //cout << "Found:" << node->value << endl;
        }
    }
    //cout << "Not Found::::" << endl;

    return nullptr;
}

void BSTree::update_search_times() {
    /* do a BFS or DFS of your tree and update the search times of all nodes at once
      The root has a search time of 1, and each child is 1 more than its parent */
      search_time_helper(root, 1);
}

void BSTree::search_time_helper(Node* node, int currentLevel) {
    if (node != nullptr) {
        search_time_helper(node->left, currentLevel + 1);
        search_time_helper(node->right, currentLevel + 1);
        node->search_time = currentLevel;
        //cout << "Node:" << node->value << "     Cost:" << node->search_time << endl;
    }
}

void BSTree::inorder(ostream & out) {
    /* print your nodes in infix order
    If our tree looks like this:

       4
     2   6
    1 3 5 7

    It should output:
    1[3] 2[2] 3[3] 4[1] 5[3] 6[2] 7[3]
    You can use the << operator to print the nodes in the format shown */
}

void BSTree::print_level_by_level(ostream & out) {
    /* Print the tree using a BFS so that each level contains the values for a level of the tree.
    Use X to mark empty positions. 
    
      if our tree looks like this:

       4
     2   6
    1   5 7
           9

    it should output:

    4[1]
    2[2] 6[2]
    1[3] X 5[3] 7[3]
    X X X X X X X 9[4]

    it might be helpful to do this part with the std::queue data structure.
    Hint: the Nth level contains 2^(N-1) nodes (with a value or with an X). Watch out
    for nodes like the left child of 6 above, and print the descendents of an empty
    node as also empty
    You can use the << operator to print nodes in the format shown */

    //queue<string>* list = new queue<string>;
    
    // queue<Node*> list;
    // bool leftX = false;
    // bool rightX = false;

    // list.push(root);

    // // Node* x = new Node(1111);
    // // x->left = nullptr;
    // // x->right = nullptr;

    // if (root == nullptr) {
    //     return;
    // }
    
    // // do until queue is empty
    // while (!list.empty())
    // {
    //     int num_nodes = list.size();

    //     // do until the number of current nodes is not zero
    //     while (num_nodes > 0)
    //     {   
            
    //         // while (list.front()->value == -1111)
    //         // {
    //         //     out << "X ";
    //         //     list.pop();
    //         // }
            
    //         // pull node from queue
    //         Node* node = list.front();
    //         if (leftX)
    //         {
    //             out << "X ";
    //             leftX = false;
    //         }

    //         if (rightX)
    //         {
    //             out << "X ";
    //             rightX = false;
    //         }


            
    //         out << node->value << " ";
    //         list.pop();

    //         // if left node exists, enqueue
    //         if (node->left != nullptr) {
    //             list.push(node->left);
    //         } else {
    //             // assign empty node
    //             // out << "X ";
    //             leftX = true;
    //         }

    //         // if right node exists, enqueue
    //         if (node->right != nullptr) {
    //             list.push(node->right);
    //         } else {
    //             // assign empty node
    //             // out << "X ";
    //             rightX = true;
    //         }
    //         num_nodes--;
    //     }

    //     out << endl;
        

    // }

    for (int i = 1; i <= height; i++)
    {
        print_helper(root, out, i);
        out << endl;
    }
    // cout << endl;
    
    
}

void BSTree::print_helper(Node* node, ostream& out, int level) {
    if (node != nullptr) {
        if (level == 1) {
            out << to_string(node->value) << "[" << node->search_time << "]" << " ";
        }
        
        else if (level > 1) {
            //cout << to_string(node->value) << endl;
            print_helper(node->left, out, level - 1);
            print_helper(node->right, out, level - 1);
        }
        return;
        
    }
    out << "X ";
    
}