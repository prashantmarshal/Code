#include <bits/stdc++.h>
using namespace std;

#define SIZE 26

class TrieNode {
    public:
    TrieNode *child[SIZE];
	bool leaf;
    
    TrieNode(){
        for(int i=0; i<SIZE; ++i){
		    this->child[i] = NULL;
        }
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
	    	if(!curr->child[word[i]-'a']){
			    curr->child[word[i]-'a'] = new TrieNode();
            }
            curr = curr->child[word[i]-'a'];
        }

        curr->leaf = true;
	}

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.size();
        TrieNode *curr = root;
       	
        for(int i=0; i<len; ++i){
            if(curr->child[word[i]-'a']){
                curr = curr->child[word[i]-'a'];
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
            if(curr->child[prefix[i]-'a']){
                curr = curr->child[prefix[i]-'a'];
            }else{
                return false;
            }
        }                   

        return (curr != NULL);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */