#include "BSTree.h"
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{

    
    BSTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(9);
    tree.insert(7);
    tree.insert(10);
    tree.insert(11);

    BSTree tree2 = BSTree(tree);

    //cout << tree << endl;

    //cout << tree2 << endl;
    

    tree.print_level_by_level(cout);


    return 0;
}