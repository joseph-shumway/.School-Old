// code source: https://github.com/mvyas85/Binary-Tree/blob/master/src/BST/BinarySearchTree.java
// Binary Search Tree



// Node class
class BSTNode {

    // declare variables
    BSTNode left;
    BSTNode right;
    Word data;

    // Node default constructor
    public BSTNode() {
        left = null;
        right = null;
        data = new Word("", 0, 0);
    }

    // Node constructor from value
    public BSTNode(Word n) {
        left = null;
        right = null;
        data = new Word(n);
    }

    // getters and setters for left and right Nodes
    public void setLeft(BSTNode n) {left = n;}
    public void setRight(BSTNode n) {right = n;}
    public BSTNode getLeft() {return left;}
    public BSTNode getRight() {return right;}

    // getter and setter for data in Node
    public void setData(Word d) {data = d;}
    public Word getData() {return data;}
}

// Main Binary Search Tree class
public class BST {

    // declare root Node
    private BSTNode root;

    // BST default constructor
    public BST() {root = null;}

    // get root Node
    public BSTNode getRoot() {return root;}

    // check if BST is empty
    public boolean isEmpty() {return root == null;}

    // insert data into BST
    public void insert(Word data) {root = insert(root, data);}

    // recursive helper method for insert()
    private BSTNode insert(BSTNode node, Word data) {
        
        // if current node doesnt exist, insert here
        if (node == null) {
            node = new BSTNode(data);

        // else, recursively go down tree until an empty and appropriate node is found (left or right depending on > or <)
        } else {

            // compare to choose left or right
            if (data.compareTo(node.getData()) <= 0) {
                node.left = insert(node.left, data);
            } else {
                node.right = insert(node.right, data);
            }
        }
        return node;
    }

    // method for deleting data k from tree
    public void delete(Word k) {

        // preliminary check if BST is empty
        if (isEmpty()) {
        
        // check if k exists in BST first
        } else if (!search(k)) {
        
        // delete k using helper function
        } else {
            root = delete(root, k);
        }
    }

    // recursive helper method for delete()
    private BSTNode delete(BSTNode root, Word k) {
        
        BSTNode p;
        BSTNode p2;
        BSTNode n;

        // check if root data is what we're looking for
        if (root.getData() == k) {

            BSTNode lt;
            BSTNode rt;

            // setup left and right variables
            lt = root.getLeft();
            rt = root.getRight();

            // if left and right Nodes don't exist, return null
            if (lt == null && rt == null) {
                return null;

            // if right only exists, return right Node
            } else if (lt == null) {
                p = rt;
                return p;

            // if left only exists, return left Node
            } else if (rt == null) {
                p = lt;
                return p;
            
            // otherwise, set p2 to right Node temporarily
            } else {
                p2 = rt;
                p = rt;

                // keep going down on the left side till the end of the BST
                while (p.getLeft() != null) {
                    p = p.getLeft();
                } 
                p.setLeft(lt);
                return p2;
            }
        }

        // recursively go down BST to left or right depending on if our desired Node is greater or less than the current Node
        if (k.compareTo(root.getData()) < 0) {
            n = delete(root.getLeft(), k);

            // remove the node
            root.setLeft(n);
        }

        // recursively go down BST to left or right depending on if our desired Node is greater or less than the current Node
        else
        {
            n = delete(root.getRight(), k);
            root.setRight(n);             
        }
        return root;
    }

    // count how many Nodes are in the BST
    public int countNodes() {
        return countNodes(root);
    }

    // recursive helper method for countNodes()
    private int countNodes(BSTNode r) {

        // if root doesn't exist, return 0
        if (r == null) {
            return 0;

        // otherwise, sum up the number of nodes left and right to this one recursively
        } else {
            int l = 1;
            l += countNodes(r.getLeft());
            l += countNodes(r.getRight());
            return l;
        }
    }

    // search for a Node by its value
    public boolean search(Word val) {
        return search(root, val);
    }

    // recursive helper method for search()
    private boolean search(BSTNode r, Word val) {
        
        boolean found = false;

        // loop while our node exists and the found flag isnt set to true
        while ((r != null) && !found) {
            
            // set rval to our Node's value
            Word rval = r.getData();

            // check if our parameter value is greater or less than our Node value and go left or right appropriately
            if (val.compareTo(rval) < 0) {
                r = r.getLeft();
            } else if (val.compareTo(rval) > 0) {
                r = r.getRight();

            // if we got this far, rval and val are equal, so we found our Node. Time to return.
            } else {
                found = true;
                break;
            }

            // recursively search using the left or right node chosen earlier
            found = search(r, val);
        }
        return found;
    }
    
    // traverse the BST in inorder
    public void inorder() {
        inorder(root);
    }

    // recursive helper method for inorder()
    private void inorder(BSTNode r) {
        
        // if the Node exists, continue
        if (r != null) {

            // recursively get left Node, print its value, then recursively get the right Node
            inorder(r.getLeft());
            System.out.print(r.getData() +" ");
            inorder(r.getRight());
        }
    }

    // traverse the BST in preorder
    public void preorder() {
        preorder(root);
    }

    // recursive helper method for preorder()
    private void preorder(BSTNode r) {
        
        // if the Node exists, continue
        if (r != null) {

            // print the Node's value, then recursively get the left and right Nodes
            System.out.print(r.getData() +" ");
            preorder(r.getLeft());             
            preorder(r.getRight());
        }
    }

    // traverse the BST in postorder
    public void postorder() {
        postorder(root);
    }

    // recursive helper method for postorder
    private void postorder(BSTNode r) {

        // if the Node exists, continue
        if (r != null) {

            // recursively get the left and right Nodes, then print the Node's value after
            postorder(r.getLeft());             
            postorder(r.getRight());
            System.out.print(r.getData() +" ");
        }
    }     
}
