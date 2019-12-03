// **********************************************************
// Authors: Michaela Brydon and Emily Rachfal
// Modified from D.S. Malik
// 
// class binaryTree
// Includes definitions of member functions in this template class
// **********************************************************

#ifndef H_binaryTree
#define H_binaryTree

//*************************************************************
// Author: D.S. Malik
//
// class binaryTreeType
// This class specifies the basic operations to implement a
// binary tree.
//*************************************************************

#include <iostream>

using namespace std;

     //Definition of the node
template <class elemType>
struct binaryTreeNode
{
    elemType info;
    binaryTreeNode<elemType> *llink;
    binaryTreeNode<elemType> *rlink;
};

   //Definition of the class
template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator=
                 (const binaryTreeType<elemType>&); 
      //Overload the assignment operator.
    bool isEmpty() const;
      //Returns true if the binary tree is empty;
      //otherwise, returns false.
    void inorderTraversal() const;
      //Function to do an inorder traversal of the binary tree.
    void preorderTraversal() const;
      //Function to do a preorder traversal of the binary tree.
    void postorderTraversal() const;
      //Function to do a postorder traversal of the binary tree.
    int treeHeight() const;
      //Returns the height of the binary tree.
    int treeNodeCount() const;
      //Returns the number of nodes in the binary tree.
    int treeLeavesCount() const;
      //Returns the number of leaves in the binary tree.
    void destroyTree();
      //Deallocates the memory space occupied by the binary tree.
      //Postcondition: root = NULL;
    void treeSwapSubtrees();
      // swaps all left and right subtrees of binary tree
    int treeSingleParent() const;
      // Returns number of nodes in binary tree with only one child

    binaryTreeType(const binaryTreeType<elemType>& otherTree); 
      //copy constructor

    binaryTreeType();   
      //default constructor

    ~binaryTreeType();   
      //destructor

protected:
    binaryTreeNode<elemType>  *root;

private:
    void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,
                  binaryTreeNode<elemType>* otherTreeRoot);
      //Makes a copy of the binary tree to which 
      //otherTreeRoot points. The pointer copiedTreeRoot  
      //points to the root of the copied binary tree.

    void destroy(binaryTreeNode<elemType>* &p);
      //Function to destroy the binary tree to which p points. 
      //Postcondition: p = NULL

    void inorder(binaryTreeNode<elemType> *p) const;
      //Function to do an inorder traversal of the binary
      //tree to which p points.  
    void preorder(binaryTreeNode<elemType> *p) const;
      //Function to do a preorder traversal of the binary
      //tree to which p points.  
    void postorder(binaryTreeNode<elemType> *p) const;
      //Function to do a postorder traversal of the binary
      //tree to which p points.  

    int height(binaryTreeNode<elemType> *p) const;
      //Function to return the height of the binary tree
      //to which p points. 
    int max(int x, int y) const;
      //Returns the larger of x and y.
    int nodeCount(binaryTreeNode<elemType> *p) const;
      //Function to return the number of nodes in the binary 
      //tree to which p points 
    int leavesCount(binaryTreeNode<elemType> *p) const;
      //Function to return the number of leaves in the binary 
      //tree to which p points 
    void swapSubtrees(binaryTreeNode<elemType> *p) const;
      // Function to swaps all left and right subtrees of binary tree to which p points
    int singleParent(binaryTreeNode<elemType> *p) const;
      // Returns number of nodes in binary tree to which p points with only one child 
};

    //Definition of member functions

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = NULL;
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == NULL);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

template <class elemType>
void  binaryTreeType<elemType>::copyTree
                      (binaryTreeNode<elemType>* &copiedTreeRoot,
		               binaryTreeNode<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new binaryTreeNode<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
} //end copyTree

template <class elemType>
void binaryTreeType<elemType>::inorder(binaryTreeNode<elemType> *p) const
{
    if (p != NULL)
    {
        inorder(p->llink);
        cout << p->info << " ";
        inorder(p->rlink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::preorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		cout<<p->info<<" ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::postorder(binaryTreeNode<elemType> *p) const
{
    if (p != NULL)
    {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->info << " ";
    }		
}

     //Overload the assignment operator
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
           operator=(const binaryTreeType<elemType>& otherTree)
{  
    if (this != &otherTree) //avoid self-copy
    {
        if (root != NULL)  //if the binary tree is not empty, 
                           //destroy the binary tree
            destroy(root);

        if (otherTree.root == NULL) //otherTree is empty
            root = NULL;
        else
            copyTree(root, otherTree.root);
    }//end else

    return *this; 
}

template <class elemType>
void  binaryTreeType<elemType>::destroy(binaryTreeNode<elemType>* &p)
{
    if (p != NULL)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}

template <class elemType>
void  binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

// ADDED ***********************

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}

template <class elemType>
void binaryTreeType<elemType>::treeSwapSubtrees()
{
    swapSubtrees(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeSingleParent() const
{
    return singleParent(root);
}

// ********************************

	//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
              (const binaryTreeType<elemType>& otherTree)
{
    if (otherTree.root == NULL) //otherTree is empty
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}

template <class elemType>
int binaryTreeType<elemType>::height(binaryTreeNode<elemType> *p) const
{
    if (p == NULL)
        //return 0; //The height of the empty tree should not be 0
        return -1;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}

//Alternative implementation of the height function
/*
template <class elemType>
int binaryTreeType<elemType>::height(binaryTreeNode<elemType> *p) const
{
    if (p->llink == NULL && p->rlink==NULL)
        return 0;
    if (p->llink == NULL && p->rlink!=NULL)
       return 1+height(p->rlink);
     if (p->llink != NULL && p->rlink==NULL)
       return 1 + height(p->llink);
    else
        return 1 + max(height(p->llink), height(p->rlink));
}
*/

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

// ADDED *********************************************************************

template <class elemType>
int binaryTreeType<elemType>::nodeCount(binaryTreeNode<elemType> *p) const
{
    int result = 0;
    if (p != NULL)
    {
        result += nodeCount(p->llink) + nodeCount(p->rlink) + 1;
    }
    return result;
}

template <class elemType>
int binaryTreeType<elemType>::leavesCount(binaryTreeNode<elemType> *p) const
{
    int result = 0;
    if (p != NULL)
    {
        if (p->llink == NULL && p->rlink == NULL){
          result++;
        }
        else
          result += leavesCount(p->llink) + leavesCount(p->rlink);
    }
    return result;
}

template <class elemType>
void binaryTreeType<elemType>::swapSubtrees(binaryTreeNode<elemType> *p) const
{

  if (p != NULL){
    binaryTreeNode<elemType> *temp = p->llink;
    p->llink = p->rlink;
    p->rlink = temp;
    swapSubtrees(p->llink);
    swapSubtrees(p->rlink);
  } 
}

template <class elemType>
int binaryTreeType<elemType>::singleParent(binaryTreeNode<elemType> *p) const
{
    int numSingleParents = 0;
    if (p != NULL)
    {
        if ((p->llink == NULL && p->rlink != NULL) 
          || (p->rlink == NULL && p->llink != NULL)){
          numSingleParents ++;
        }
        numSingleParents += singleParent(p->llink) + singleParent(p->rlink);
    }
    return numSingleParents;
}

#endif
