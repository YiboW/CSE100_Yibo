/**
 *  CSE 100 PA3 C++ Extra Credit
 *  Author: Carlos Mattoso
 */

#ifndef SUFFIX_ARRAY_H
#define SUFFIX_ARRAY_H

#include <string>

/**
 *  The class for a suffix array, represented as an int array
 *  storing the indices of the sorted suffixes.
 * 
 *  Recommended reading/supplemental material:
 *  [1] Introduction to Suffix Arrays and the DC3 algorithm:
 *         http://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/04/Slides04.pdf 
 *  [2] Original paper for the DC3 algorithm: 
 *         https://www.cs.helsinki.fi/u/tpkarkka/publications/jacm05-revised.pdf 
 *  [3] UCSD Coursera Course “Algorithms on Strings” Lecture on Suffix Tries:
 *         https://www.coursera.org/learn/algorithms-on-strings/lecture/V1AYj/herding-text-into-suffix-trie 
 */
class SuffixArray
{
private:
  // actual word encoded by the suffix array
  std::string word;

public:

  /* Create a new suffix array from `word`. */
  SuffixArray(std::string word);

  /* 
   * Return true if `pattern` exists in the word encoded by the suffix array,
   * false otherwise 
   */
  bool find(std::string pattern) const;

  /* Destructor */
  ~SuffixArray();

  /** 
   * @VisibleForTesting
   *
   * The suffix array MUST be represented as an an int array of the indices
   * of the sorted suffixes from `word`.
   */
  int * const suffixIdxs;

private:
  /**
   * Helper method that constructs the suffix array derived from `word`
   * preferably using the DC3 algorithm [1][2] (if you want the 4 points 
   * for efficiency)
   */
  void buildSuffixArray(std::string word);
};

#endif // SUFFIX_ARRAY_H
