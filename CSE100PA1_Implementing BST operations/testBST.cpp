#include "BSTInt.hpp"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2016
 * Author: Christine Alvarado and YOU
 * TODO: Add more tests
 */


/*bool checkInsert(BSTNode* a){
        if (a->left !=NULL && a->left->data  > a->data)
                return false;
        else if (a->right != NULL && a->right->data < a->data)
                return false;
        checkInsert(a->left);
        checkInsert(a->right);

        return true;

}
*/

int main() {

    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);

    /* Create an instance of BST holding int */
    BSTInt b;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : v) {
        bool pr = b.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }

    /* test duplicate */
    bool pr = b.insert(100);
    if( pr ) {
        cout << "Duplicate insert of " <<100
                << endl;
        return -1;
    }
	

    /* Test size. */
    cout << "Size is: " << b.size() << endl;
    if(b.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : v) {
        if(!b.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }
    
    if(b.find(70)){
        cout << "Incorrect return value when finding " << 70 << endl;
        return -1;
    }

	//test height
	if(b.height()!=2){
		cout<<"Incorrect Height!"<<endl;
		return -1;
	}
    
    /* Test empty */
    if(b.empty()) {
        cout <<"Incorrect return value for non-empty tree." << endl;
        return -1;
    }
    
    BSTInt e;
    if (!e.empty()) {
        cout << "Incorrect return value for empty tree." << endl;
        return -1;
    }
    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */

    
    // Test the template version of the BST  with ints 
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }


    /* test duplicate */
    auto p2 = btemp.insert(100);
	if(*(p2.first) != 100){
        cout << "Duplicate insert of " <<100 <<"handled incorrectly"
 
               << endl;
	return -1;
	}    

	if(p2.second ) {
        cout << "Duplicate insert of " <<100 <<"handled incorrectly"
                << endl;
        return -1;
    }

        int h1 = btemp.height();
        if (h1 != 2){
                cout<<"Wrong height"<<endl;
                return -1;
        }




    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }



    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
    for(; vit != ven; ++vit) {
        if(! (it != en) ) {
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }

    cout << "success!" << endl;

    

    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.




    cout<< "Test double version vector"<<endl;

    vector<double> d;
    d.push_back(3.1);
    d.push_back(4.2);
    d.push_back(1.2);
    d.push_back(100.3);
    d.push_back(-33.5);

    BST<double> btemp2;
    for (double item : d) {
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p3 = btemp2.insert(item);
        if (*(p3.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p3.first) << endl;
            return -1;
        }
        if (!p3.second) {
            cout << "Wrong boolean returned.  Expected true but got "
                 << p3.second << endl;
            return -1;
        }
        cout << "success!" << endl;

    }
	vector<int> t;
	t.push_back(10);
	t.push_back(4);
	t.push_back(15);
	t.push_back(2);
	t.push_back(6);
	t.push_back(12);
	t.push_back(18);
	t.push_back(1);
	t.push_back(3);
	t.push_back(5);
	t.push_back(10);
	t.push_back(11);
	t.push_back(13);
	t.push_back(19);
	
	BST<int> btemp3;
	for(int item:t){
		btemp3.insert(item);
	}
	
	auto testit = btemp3.begin();
	for (int i= 0; i<13; i++){
		cout<<*testit<<endl;
		++testit;

	}

    auto p4 = btemp2.insert(100.3);
        if(*(p4.first) != 100.3){
        cout << "Duplicate insert of " <<100.3 <<"handled incorrectly"

               << endl;
        return -1;
        }

        if(p4.second ) {
        cout << "Duplicate insert of " <<100.3 <<"handled incorrectly"
                << endl;
        return -1;
    }

	int h2 = btemp2.height();
	if (h2 != 2){
		cout<<"Wrong height"<<endl;
		return -1;
	}

    for (double item: d) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<double> foundIt = btemp2.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt)
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }

    sort(d.begin(),d.end());

    cout << "traversal using iterator..." << endl;
    auto dit = d.begin();
    auto den = d.end();

    auto end2 = btemp2.end();
   
    auto it2 = btemp2.begin();
    for(; dit != den; ++dit) {
        if(! (it2 != end2) ) {
            cout << *it2 << "," << *dit
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it2 << endl;
        if(*it2 != *dit) {
            cout << *it2 << "," << *dit
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it2;
    }

    cout << "success!" << endl;


cout << "All tests passed!" << endl;
    return 0;
}
