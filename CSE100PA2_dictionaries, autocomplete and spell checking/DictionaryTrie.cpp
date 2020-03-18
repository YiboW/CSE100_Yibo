#include "util.h"
#include "DictionaryTrie.h"

Node::Node(char data){
    this->data = data;
    this->ifEnd = 0;
    this->freq = 0;
    this->left = nullptr;
    this->middle = nullptr;
    this->right = nullptr;
    this->word = "";
    this->wordLen = 0;
}

void Node::insert(Node** temp, std::string word, unsigned int i, unsigned int freq){
    char ch = word.at(i);
    if(!(*temp))
        *temp = new Node(word.at(i));
    if(ch < (*temp)->data)
        insert(&((*temp)->left),word, i, freq);
    else if((*temp)->data < ch)
        insert(&((*temp)->right),word, i, freq);
    else {
        if(i < word.length() - 1)
            insert(&((*temp)->middle),word,i + 1, freq);
        else{
            (*temp)->ifEnd = 1;
            (*temp)->freq = freq;
            (*temp)->word = word;
            (*temp)->wordLen = word.length();
        }
    }
}

bool Node::find(Node* temp,std::string word, unsigned int i){
    char ch = word.at(i);
    if(!temp)
        return false;
    if(ch < temp->data)
        return find(temp->left, word, i);
    else if(temp->data < ch)
        return find(temp->right, word, i);
    else {
        if(i==word.length() - 1)
            return temp->ifEnd;
        return find(temp->middle, word, i+1);
    }
}

Node* Node::findPrefix(Node* temp,std::string word, unsigned int i){
    char ch = word.at(i);
    if(!temp)
        return nullptr;
    if(ch < temp->data)
        return find(temp->left, word, i);
    else if(temp->data < ch)
        return find(temp->right, word, i);
    else {
        if(i==word.length() - 1)
            return temp;
        return find(temp->middle, word, i+1);
    }
}
std::vector<pair<std::string,double>> predictCompletionsHelper(Node* p) {
    if(p->left) return predictCompletionsHelper(p->left);
    if(p->middle) return predictCompletionsHelper(p->middle);
    if(p->right) return predictCompletionsHelper(p->right);
    if(p->ifEnd) return
}

void Node::deleteAll(Node* temp){
    if(!temp)
        return;
    if(temp->left)
        deleteAll(temp->left);
    if(temp->middle)
        deleteAll(temp->middle);
    if(temp->right)
        deleteAll(temp->right);
    delete temp;
    return;
}


/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
    root = nullptr;
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
    if(word.empty()) return false;
    if(find(word)) {
        return false;
    }
    //check if word has special char
    for(unsigned int i = 0; i < word.length(); i++){
        char ch = word.at(i);
        //check if space char
        if(ch==32)
            continue;
        else if(ch>64 && ch<91)//check if upper case
            continue;
        else if(ch>96 && ch<123)//check if lower case
            continue;
        else
            return false;//return false because it has special char
    }
    
    root->insert(&root,word,0,freq);
    return true;
    
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
    if(word.empty())
        return false;
    if(!root)
        return false;
    return root->find(root,word,0);
}

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
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
    std::vector<std::string> words;
    Node* p = findPrefix(root, prefix, 0)
    if(prefix.empty()) {
        cout << "Invalid Input. Please retry with correct input" <<endl;
        return words;
    }
    if(!p){
        cout << "Invalid Input. Please retry with correct input" <<endl;
        return words;
    }
    
    //predictCompletionsHelper(p);
        
    
    
       
       
  return words;
}

/*
 * Return the most similar word of equal length to the query, based
 * on their Hamming distance. 
 * In case of ties, return the word with the highest frequency (you may
 * assume there will always be one should a tie happen.)
 * In case there isn't any word of equal length to the query in the
 * trie, return an empty string.
 */
std::string DictionaryTrie::checkSpelling(std::string query)
{
    Node* p = findPrefix(query, 0);
    std::string q = query;
    int queryLength = query.length();
    while(!p && queryLength == 0) {
        q.pop_back();
        p = findPrefix(q, 0);
        queryLength = q.length();
    }
    std::queue<Node*> unvisited;
    std::vector<std::string> word;
    std::vector<int> frequency;
    unvisited.push(temp);
    
    
    while(!unvisited.empty()){
        if(temp->left)
            unvisited.push(temp->left);
        if(temp->equal)
            unvisited.push(temp->equal);
        if(temp->right)
            unvisited.push(temp->right);
        if(unvisited.front()->ifEnd == 1 && (unvisited.front()->word).length() == query.length()){
            word.push_back(unvisited.front()->word);
            frequency.push_back(unvisited.front()->freq);
        }
        
        unvisited.pop();
        temp = unvisited.front();
    }
    
    int n = 0;
    std::string m;
    for(unsigned int i = 0; i<frequency.size();i++){
        for(unsigned int j = 0; j<frequency.size() - i - 1; j++){
            if(frequency.at(j) < frequency.at(j+1)){
                n = frequency.at(j);
                frequency.at(j) = frequency.at(j+1);
                frequency.at(j+1) = n;
                m = word.at(j);
                word.at(j) = word.at(j+1);
                word.at(j+1) = m;
            }
        }
    }
    
  return "";
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){
    root->deleteAll(root);
}
