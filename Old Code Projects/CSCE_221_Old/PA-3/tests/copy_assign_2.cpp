#include "test_functions.h"
#include "/mnt/c/.School/CSCE_221/PA-3/tests/utils/RefBSTree.h"
#include <cstdlib>
#include <ctime>
#include <set>

std::set<int> set;
BSTree tree1;
RefBSTree ttree1;

srand(time(NULL));

for (int i = 0; i < 10; i++) {
  int num = rand() % 10000;
  if (set.count(num) == 0) {
    set.insert(num);
    tree1.insert(num);
    ttree1.insert(num);
  }
}


BSTree tree2;
for (int i = 0; i < 20; i++) {
    tree2.insert(i*i);
}
tree2 = tree1;

ASSERT_TRUE(verify_equality(tree1, tree2) &&
  verify_equality(tree2, ttree1));
ASSERT_NE(tree2.get_root(), tree1.get_root());
ASSERT_NE(tree2.get_root(), ttree1.get_root());