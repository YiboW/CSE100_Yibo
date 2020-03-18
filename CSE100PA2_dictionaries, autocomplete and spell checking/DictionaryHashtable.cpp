#include "util.h"
#include "DictionaryHashtable.h"


/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){
}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
    std::pair<std::unordered_set<std::string>::iterator,bool> tf;
    tf = setHash.insert(word);
    
  return tf.second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
    std::unordered_set<std::string>::iterator it = setHash.find(word);
    if (it != setHash.end()) return true;
    else return false;
    
  return false;
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){
}
