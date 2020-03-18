#include "util.h"
#include "SuffixArray.h"

/**
 *  The class for a suffix array, represented as an int array
 *  storing the indices of the sorted suffixes.
 */
SuffixArray::SuffixArray(std::string word) : 
  word(word),
  suffixIdxs(new int[word.length()+1])
{
  buildSuffixArray(word);
}

/*
 * Helper method that constructs the suffix array derived from `word`
 * preferably using an efficient algorithm, such as the DC3 algorithm
 * (if you want the 5 points for efficiency, of course.)
 */
void SuffixArray::buildSuffixArray(std::string word){
  // TODO: Implement this method
  return;
}

/* 
 * Return true if `pattern` exists in the word encoded by the suffix array,
 * false otherwise 
 */
bool SuffixArray::find(std::string pattern) const
{
  // TODO: Implement this method
  return false;
}

/* Destructor */
SuffixArray::~SuffixArray(){
  delete [] this->suffixIdxs;
}
