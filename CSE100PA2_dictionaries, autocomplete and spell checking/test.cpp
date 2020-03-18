/**
 *  CSE 100 PA2 C++ Auto-Complete
 *  Authors: Gina Ratto, Shruti Pandey, Carlos Mattoso
 *  Description: Testing file to see if our
 *                dictionaries work correctly
 */

#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<cassert>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#include "SuffixArray.h"
#define LETTERS 26
using namespace std;


int main(int argc, char** argv)
{

    //Initialize words
    vector<std::string> words;
    vector<string>::iterator wit;
    vector<string>::iterator wen;
    //initialize nonwords
    set<string> nope;
    set<string>::iterator nit;
    set<string>::iterator nen;

    //Initialize data structures
    DictionaryBST d_bst;
    DictionaryHashtable d_ht;
    DictionaryTrie dt;
    int t_bst, t_ht, tt;

    words.push_back("harry");
    words.push_back("sriram");
    words.push_back("cse");
    words.push_back("crucio");
    words.push_back("autocomplete");

    /**************************************************************************************
     **************************************************************************************
     **       _               _                _       _
     **      | |             | |              (_)     | |
     **   ___| |__   ___  ___| | ___ __   ___  _ _ __ | |_
     **  / __| '_ \ / _ \/ __| |/ / '_ \ / _ \| | '_ \| __|
     ** | (__| | | |  __/ (__|   <| |_) | (_) | | | | | |_
     **  \___|_| |_|\___|\___|_|\_\ .__/ \___/|_|_| |_|\__|
     **                           | |
     **                           |_|
     **************************************************************************************
     *************************************************************************************/
    cout << endl << "Testing CHECKPOINT methods (find & insert)..." << endl;
    cout <<         "=============================================" << endl;

    cout << "Inserting into Dictionaries..." << endl;

    wit = words.begin();
    wen = words.end();
    for(; wit != wen; ++wit)
    {
        cout << "Inserting: \"" << *wit << "\"... ";
        t_bst = d_bst.insert(*wit);
        t_ht = d_ht.insert(*wit);
        tt = dt.insert(*wit, 1);
        //cout << t_bst << " " << t_ht << " "<< tt << "... ";
        if(!t_bst)
        {
            cout << "FAILED for DictionaryBST... ";
        }
        if(!t_ht)
        {
            cout << "FAILED for DictionaryHashset... ";
        }
        if(!tt)
        {
            cout << "FAILED for DictionaryTrie... ";
        }
        if(t_bst && t_ht && tt)
        {
            cout << "PASSED! :D ";
        }
        cout << endl;
    }

    cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

    wit = words.begin();
    wen = words.end();
    for(; wit != wen; ++wit)
    {
        cout << "Inserting: \"" << *wit << "\"... ";
        t_bst = d_bst.insert(*wit);
        t_ht = d_ht.insert(*wit);
        tt = dt.insert(*wit, 5);
        if(t_bst)
        {
            cout << "FAILED for DictionaryBST... ";
        }
        if(t_ht)
        {
            cout << "FAILED for DictionaryHashset... ";
        }
        if(tt)
        {
            cout << "FAILED for DictionaryTrie... ";
        }
        if(!t_bst && !t_ht && !tt)
        {
            cout << "PASSED! :D ";
        }
        cout << endl;
    }

    cout << endl;

    // Start testing find function

    for (auto item : words) {
        cout << "Testing find for " << item << " ";
        bool d_bstfound = d_bst.find(item);
        bool d_htfound = d_ht.find(item);
        bool dtfound = dt.find(item);

        if(!d_bstfound)
        {
            cout << "FAILED for DictionaryBST... ";
        }
        if(!d_htfound)
        {
            cout << "FAILED for DictionaryHashset... ";
        }
        if(!dtfound)
        {
            cout << "FAILED for DictionaryTrie... ";
        }
        if(dtfound && d_htfound && d_bstfound)
        {
            cout << "PASSED! :D ";
        }
        cout << endl;
    }

    cout << "Testing find for item that does not exist" << " ";
    bool d_bstfound = d_bst.find("abra");
    bool d_htfound = d_ht.find("abra");
    bool dtfound = dt.find("abra");

    if(d_bstfound)
    {
        cout << "FAILED for DictionaryBST... ";
    }
    if(d_htfound)
    {
        cout << "FAILED for DictionaryHashset... ";
    }
    if(dtfound)
    {
        cout << "FAILED for DictionaryTrie... ";
    }
    if(!dtfound && !d_htfound && !d_bstfound)
    {
        cout << "PASSED! :D ";
    }
    cout << endl;


    // Test for inputs with spaces vs no spaces
    cout << "Testing find for input with spaces" << " ";
    d_bst.insert("the spaces between us");
    d_ht.insert("the spaces between us");
    dt.insert("the spaces between us", 3);
    bool d_bstfound1 = d_bst.find("thespacesbetweenus");
    bool d_htfound1 = d_ht.find("thespacesbetweenus");
    bool dtfound1 = dt.find("thespacesbetweenus");
    bool d_bstfound2 = d_bst.find("the spaces between us");
    bool d_htfound2 = d_ht.find("the spaces between us");
    bool dtfound2 = dt.find("the spaces between us");

    if(d_bstfound1)
    {
        cout << "FAILED for DictionaryBST... ";
    }
    if(d_htfound1)
    {
        cout << "FAILED for DictionaryHashset... ";
    }
    if(dtfound1)
    {
        cout << "FAILED for DictionaryTrie... ";
    }
    if(!d_bstfound2)
    {
        cout << "FAILED for DictionaryBST... ";
    }
    if(!d_htfound2)
    {
        cout << "FAILED for DictionaryHashset... ";
    }
    if(!dtfound2)
    {
        cout << "FAILED for DictionaryTrie... ";
    }
    if(dtfound2 && d_htfound2 && d_bstfound2)
    {
        cout << "PASSED! :D ";
    }
    cout << endl;


    // test trie with special characters

    cout << "Testing insert and find for special characters" << " ";
    bool dtfound3 = dt.find(":cse");
    bool dtinsert = dt.insert(":cse", 3);

    if(dtfound3 || dtinsert)
    {
        cout << "FAILED for DictionaryTrie... ";
    }
    if(!dtfound3 && !dtinsert)
    {
        cout << "PASSED! :D ";
    }
    cout << endl;

    // Test edge cases
    dt.insert("cat", 5);
    if (dt.find("ca") || dt.find("car") || dt.find("cats")) {
        cout << "Failed for Dictionary Trie" << endl;
    }
    if (dt.insert("", 10) || dt.find("")) {
        cout << "Should not insert/find an empty string" << endl;
    }

    // check frequencies
    dt.insert("harry", 7);
    dt.insert("harry", 2);

    /**************************************************************************************
     **************************************************************************************
     **    __ _             _               _               _         _
     **   / _(_)           | |             | |             (_)       (_)
     **  | |_ _ _ __   __ _| |    ___ _   _| |__  _ __ ___  _ ___ ___ _  ___  _ __
     **  |  _| | '_ \ / _` | |   / __| | | | '_ \| '_ ` _ \| / __/ __| |/ _ \| '_ \
     **  | | | | | | | (_| | |   \__ \ |_| | |_) | | | | | | \__ \__ \ | (_) | | | |
     **  |_| |_|_| |_|\__,_|_|   |___/\__,_|_.__/|_| |_| |_|_|___/___/_|\___/|_| |_|
     **
     **************************************************************************************
     **************************************************************************************/

    /*************************************************************************************
     *
     * [AUTOCOMPLETE]
     *
     *************************************************************************************/
    cout << endl << "Testing AUTOCOMPLETE..." << endl;
    cout <<         "=======================" << endl;

    DictionaryTrie trie;
    trie.insert("step up", 100);
    trie.insert("steward", 500);
    trie.insert("steer", 100);
    trie.insert("stealth",100);
    trie.insert("st", 600);
    trie.insert("potato", 50000);
    trie.insert("ste", 400);
    trie.insert("step", 510);
    trie.insert("stern", 3000);

    // check that resulting vector holds expected elements
    vector<std::string> completions = trie.predictCompletions("ste", 4);
    cout << "vector contains ";
    for (auto item : completions) {
        cout << item << " ";
    }
    cout << endl;
    cout << "want to see: stern, step, steward, ste" << endl;

    // check for asking for more words than exist in tree
    completions = trie.predictCompletions("ste", 200);
    cout << "vector contains ";
    for (auto item : completions) {
        cout << item << " ";
    }
    cout << endl;
    cout << "want to see: stern step steward ste steer stealth step up" << endl;


    /*************************************************************************************
     *
     * [SPELL CHECKER]
     *
     *************************************************************************************/
    cout << endl << "Testing SPELL CHECKER..." << endl;
    cout <<         "========================" << endl;

    DictionaryTrie scTrie;
    scTrie.insert("stop"    , 9001);
    scTrie.insert("star"    , 250);
    scTrie.insert("atom"    , 100);
    scTrie.insert("able"    , 500);
    scTrie.insert("upon"    , 420);
    scTrie.insert("step"    , 510);
    scTrie.insert("step up" , 500);
    scTrie.insert("steward" , 200);
    scTrie.insert("steer"   , 100);
    scTrie.insert("stone"   , 130);
    scTrie.insert("steering", 300);
    scTrie.insert("stealth" , 100);

    std::string sc;

    // [Spell checker] check that returns empty string when using empty string
    sc = scTrie.checkSpelling("");
    if (sc != "") {
        cout << "[Spell checker] Test FAILED: Didn't return empty string for empty string." << endl;
    }

    // [Spell checker] check that returns empty string when passing string not in trie
    sc = scTrie.checkSpelling("this string is not in the trie");
    if (sc != "") {
        cout << "[Spell checker] Test FAILED: Didn't return empty string for non-existent string." << endl;
    }

    // [Spell checker] check that it returns 'stop' when querying 'stoo'
    sc = scTrie.checkSpelling("stoo");
    if (sc != "stop") {
        cout << "[Spell checker] Test FAILED: Didn't return 'stop' for query 'stoo'." << endl;
    }

    // [Spell checker] check that it returns 'stone' when querying 'stpmw'
    sc = scTrie.checkSpelling("stzzz");
    if (sc != "stone") {
        cout << "[Spell checker] Test FAILED: Didn't return 'stone' for 'stzzz' query." << endl;
    }

    /*************************************************************************************
     *
     * [EXTRA CREDIT] This part is entirely up to you! Write your tests here if you do it.
     *
     *************************************************************************************/

    return 0;
}
