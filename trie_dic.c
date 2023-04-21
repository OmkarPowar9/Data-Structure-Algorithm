//Chapter 5:Introduction Hashing Trie Implementing dictionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct trie
{
	int isleaf;
	struct trie *child[26];
	char *value;
}TRIE;

TRIE *creatnode()
{
	TRIE *temp=malloc(sizeof(TRIE));
	temp->isleaf=0;
	for(int i=0;i<26;i++)
		temp->child[i]=NULL; 
	temp->value=NULL;
	return temp;
}
void insert(TRIE *root,char *key,char *syn)
{
	TRIE *cur=root;
	while(*key)
	{
		if(cur->child[*key-'a']==NULL)
			cur->child[*key-'a']=creatnode();
		cur=cur->child[*key-'a'];
		key++;
	}
	cur->isleaf=1;
	cur->value=malloc(sizeof(syn)+1);
	strcpy(cur->value,syn);
}
int search(TRIE *root,char *key,char *syn)
{
	TRIE *cur=root;
	while(*key)
	{
		if(cur->child[*key-'a']==NULL)
			return 0;
		cur=cur->child[*key-'a'];
		key++;		
	}
	if(cur->isleaf)
	{
		strcpy(syn,cur->value);
		return 1;
	}
	return 0;
}

int main()
{
	TRIE *root=creatnode();
	char syn[100];
	insert(root,"act","pretend");
	if(search(root,"act",syn))
		printf("act is present and meaning is: %s\n",syn);
	else
		printf("the word act is not present\n");
	if(search(root,"ac",syn))
		printf("ac is present and meaning is: %s\n",syn);
	else
		printf("the word ac is not present");
	
}