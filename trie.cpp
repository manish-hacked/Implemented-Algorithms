#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

struct Trie{
	struct trie *childs[26];
	bool leaf;
};

struct Trie* getNode(){
	struct Trie* node  = (struct Trie*)malloc(sizeof(struct Trie));
	node->leaf=false;
	for(int i=0;i<26;i++)
	node->childs[i]=NULL;
	return node;
}

void Insert(struct Trie* root,const char *key){
	int level = strlen(key);
	struct Trie* temp = root;
	int i;
	for(i=0;i<level;i++){
		int p = key[i]-'a';
		if(!temp->childs[p]){
			temp->childs[p]=getNode();
		}
		temp = temp->childs[p];
	}
	temp->leaf = true;
}

bool search()

int main(){
	char keys[][32]={"hello","brother","manish","kumar","aab","tan"};
	char output[][32]={"not present in trie","present in trie"};
	struct Trie* root  = getNode();
	int i=0;
	for(i=0;i<ARRAY_SIZE(keys);i++)
	Insert(root,keys[i]);
}
