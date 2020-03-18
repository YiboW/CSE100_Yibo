/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado, Carlos Mattoso
 */

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H

#include <vector>
#include <string>

/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */

class Node
{
private:
    char data;
    unsigned int freq;
    //true if it is last character of one of string
    unsigned ifEnd: 1;
    class Node *left, *middle, *right;
    std::string word;
    int wordLen;
public:
    Node(char data);
    void insert(Node** temp, std::string word, unsigned int i, unsigned int freq);
    bool find(Node* temp, std::string word, unsigned int i);
    Node* findPrefix(Node* temp,std::string word, unsigned int i);
    void deleteAll(Node* temp);
    friend class DictionaryTrie;
};


class DictionaryTrie
{
public:

  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  /* Return the most similar word of equal length to the query, based
   * on their Hamming distance. 
   * In case of ties, return the word with the highest frequency (you may
   * assume there will always be one should a tie happen.)
   * In case there isn't any word of equal length to the query in the
   * trie, return an empty string.
   */
  std::string
  checkSpelling(std::string query);

  /* Destructor */
  ~DictionaryTrie();

private:
  // Add your own data members and methods here
    Node* root;
    
};

#endif // DICTIONARY_TRIE_H
