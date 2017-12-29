/*Print all valid words that are possible using Characters of Array*/

#include <iostream>
using namespace std;

#define SIZE 26
struct TrieNode
{
	TrieNode *child[SIZE];
	bool leaf;
};

TrieNode* getNode(){
	TrieNode *node = new TrieNode();

	for(int i=0; i<SIZE; ++i)
		node->child[i] = NULL;

	node->leaf = false;
	return node;
}

void insert(TrieNode *root, char *word){
	TrieNode *iter = root;
	int len = strlen(word);
	
	for(int i=0; i<len; ++i){
		if(!iter->child[word[i]-'a'])
			iter->child[word[i]-'a'] = getNode();
		iter = iter->child[word[i]-'a'];
	}
	iter->leaf = true;
}

bool search(TrieNode *root, char *word){
	int len = strlen(word);
	TrieNode *iter = root;
	int i;
	for(i=0; i<len; ++i){
		if(iter->child[word[i]-'a'] == NULL)
			return false;
		else
			iter = iter->child[word[i]-'a'];
	}

	return (iter && iter->leaf);
}

int main(int argc, char const *argv[])
{
	char word[][8] = {"a", "answer"};
	TrieNode *root = getNode();
	for (int i = 0; i < 2; ++i)
		insert(root, word[i]);
	
}