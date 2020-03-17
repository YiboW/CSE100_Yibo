
#include "BSTInt.hpp"
using namespace std;
/* Function definitions for a int-based BST class */


/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt() {
  deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
  cout << "BSTInt ready to insert!\n";
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }

  BSTNodeInt* curr = root;
  
  while (1) {
    if (item < curr->data) {
      	if (curr->left)
            curr = curr->left;
    	else break;
    }
    else if (curr->data < item) {
      	if (curr->right)
            curr = curr->right;
        else break;
    }
    else {
      return false;
    }
  }

  // Ready to insert
  BSTNodeInt* newNode = new BSTNodeInt(item);
  if (item < curr->data) {
    curr->left = newNode;
    newNode->parent = curr;
  }
  else {
    curr->right = newNode;
    newNode->parent = curr;
  }

  ++isize;
  return true;

}


/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
  BSTNodeInt* curr = root;
  while (curr) {
    if (curr->data < item) {
      curr = curr->right;
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {
      return true;
    }
  }
  return false;
}

  
/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const 
{
  return isize;
}

  
/** Return the height of the BST.
    Height of tree with just root node is 0
    height of an empty tree is -1
 */
int BSTInt::height() const
{
  //if(!root) return -1;
  return height(root);
}

//helper method
int BSTInt::height(BSTNodeInt* n) const{
	if(!n)
	return -1;
	//if(!n->left && !n->right) return 0;	
	else{
		int le = height(n->left);
		int ri = height(n->right);
		if (le < ri)
			return ri + 1;
		else
			return le + 1;
	}
}




/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{
	if (!isize) return true;
  return false;
}




/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
  if (!n)
	return;
  else{
	if (n->left) deleteAll(n->left);
	if (n->right) deleteAll(n->right);
	delete n;
 
 }

}
