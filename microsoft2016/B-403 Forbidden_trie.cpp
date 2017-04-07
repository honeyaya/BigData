#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define ll long long
const int branchnum = 2;

struct TrieNode{
	int index;
	bool hashstate;
	bool state;
	TrieNode * next[branchnum];
	
	TrieNode(){
		next[0] = NULL;
		next[1] = NULL;
		index = -1;
		hashstate = false;
		state = false;
	}
};


TrieNode* root;
int zeroMask = -1;

void insert(ll ip,int index, int mask, bool state){
	TrieNode* tmp = root;
	ll pst = (ll)1 << 31;
	int tag;
	for(int i = 0; i < mask; i++){
		tag = (ip & pst)>0;
		if(tmp->next[tag]==NULL)
			tmp->next[tag] = new TrieNode();
		tmp=tmp->next[tag];
		pst>>=1; 
	}
	if(tmp->index == -1){
		tmp->index = index;
		tmp->state = state;
	}
	tmp->hashstate = true;
}

bool search(ll ip){
	TrieNode* tmp = root;
	ll pst = (ll) 1 << 31;
	int ind = -1;
	bool st = true;
	
	for(int i = 0; i < 32; i++){
		int tag = (ip & pst)>0;
		if(tmp->next[tag] == NULL)
			break;
		if(tmp->next[tag]->hashstate){
			if(ind == -1 || tmp->next[tag]->index < ind){
				ind = tmp->next[tag]->index;
				st = tmp->next[tag]->state;
			}
		}
		
		tmp = tmp->next[tag];
		pst>>=1;
	} 
	
	if(ind == -1){
		if(zeroMask!=0){
			return true;
		} else 
			return false;
	}
	
	return st;
}

int main(){
	int n,m;
	int a,b,c,d,mask;
	
	while(cin >> n >> m){
		root = new TrieNode();
		char cmd[30];
		for(int i = 1; i <= n; i++){
			scanf("%s",cmd);
			scanf("%d.%d.%d.%d",&a,&b,&c,&d);
			ll ip = (a<<24)+(b<<16)+(c<<8)+d;
			char t;
			scanf("%c",&t);
			mask = 32;
			if(t == '/'){
				scanf("%d",&mask);
			}
			int state=(strcmp(cmd,"allow")==0);
			if(mask == 0){
				if(zeroMask == -1) {
					if(state == 1) {
						zeroMask = 1;
					} else zeroMask = 0;
				}
			}
			
		//	cout << "ip=" <<ip << " mask= "<<mask << " zeroMask= "<< zeroMask << endl;
			insert(ip,i,mask,state);
			
		}
		
		while(m--){
			scanf("%d.%d.%d.%d",&a,&b,&c,&d);
			ll matchip = (a<<24)+(b<<16)+(c<<8)+d;
			if( search(matchip)) cout << "YES" <<endl;
			else cout << "NO" <<endl; 
		}
	}
	return 0;
}
