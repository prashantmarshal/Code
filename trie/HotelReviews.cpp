// https://www.interviewbit.com/problems/hotel-reviews/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    unordered_map<char, TrieNode*>tmap;
    bool leaf;
    
    TrieNode(){
        leaf = false;
    }
};

class Trie {
public:
    TrieNode *root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.size();
        TrieNode *curr = root;
           
        // curr points to the node of the character that is inserted
        for(int i=0; i<len; ++i){
            if(!curr->tmap[word[i]-'a']){
                curr->tmap[word[i]-'a'] = new TrieNode();
            }
            curr = curr->tmap[word[i]-'a'];
        }

        curr->leaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.size();
        TrieNode *curr = root;
           
        for(int i=0; i<len; ++i){
            if(curr->tmap[word[i]-'a']){
                curr = curr->tmap[word[i]-'a'];
            }else{
                return false;
            }
        }                   

        return (curr->leaf);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.size();
        TrieNode *curr = root;
           
        for(int i=0; i<len; ++i){
            if(curr->tmap[prefix[i]-'a']){
                curr = curr->tmap[prefix[i]-'a'];
            }else{
                return false;
            }
        }                   

        return (curr != NULL);
    }
};

class sortedReviews
{   
public:
    int index;
    int prio;
    string review;
};


bool operator<(const sortedReviews& a, const sortedReviews& b) {
    sortedReviews temp1=a,temp2=b;
    if(a.prio != b.prio)
        return a.prio < b.prio;
    else{
        return a.index > b.index;
    }
}

vector<int> solve(string goodwords, vector<string> &reviews) {
    Trie *t = new Trie();
    
    // stringstream class check1 
    stringstream check1(goodwords); 
    string intermediate; 
    
    // Tokenizing w.r.t. space '_' 
    while(getline(check1, intermediate, '_')) 
        t->insert(intermediate);

    priority_queue<sortedReviews> pq;

    for (int i = 0; i < reviews.size(); i++)
    {
        string review = reviews[i];
        
        // stringstream class check1 
        stringstream check1(review); 
        int count = 0;

        string intermediate; 
        while(getline(check1, intermediate, '_')) 
            if(t->search(intermediate))
                count++;
                
        sortedReviews r;
        r.index = i;
        r.prio = count;
        r.review = review;
        pq.push(r);   
    }

    
    int size = pq.size();
    
    vector<int>v;
    
    for (int i = 0; i < size; ++i)
    {
        v.push_back(pq.top().index);
        pq.pop();
    }
    return v;
}