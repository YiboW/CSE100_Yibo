#include "util.h"
#include "DictionaryBST.h"


/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){
}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
    std::pair<std::set<std::string>::iterator,bool> tf;
    tf = setBST.insert(word);
    
  return tf.second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
    std::set<std::string>::iterator it = setBST.find(word);
    if (it != setBST.end()) return true;
    else return false;
    
  return false;
}

/* Destructor */
DictionaryBST::~DictionaryBST(){
}
