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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */