class TrieNode{
public:
	bool state;
	TrieNode * next[26];
	
	TrieNode(){
		for(int i = 0; i < 26; i++){
			next[i] = NULL;
		} 
		
		state = false;
	}
};

class Trie {
	TrieNode * root;
public:
    /** Initialize your data structure here. */
    Trie() {
		root = new TrieNode();    
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *tmp = root;
        
        int len = word.size();
        for(int index = 0; index < len; index++){
        	if(tmp->next[word[index]-'a'] == NULL){
        		tmp->next[word[index]-'a'] = new TrieNode();
			}
			tmp = tmp->next[word[index]-'a'];
		}
		tmp->state = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *tmp = root;
        
		int len = word.size();
        
        for(int index = 0; index < len; index++){
        	if(tmp->next[word[index]-'a']!=NULL){
        		tmp = tmp->next[word[index]-'a'];
			} else {
				return false;
			}	
		}
		return tmp->state;
    }
    
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *tmp = root;
        for(int index = 0; index < prefix.size(); index++){
        	if(tmp->next[prefix[index]-'a']!=NULL){
				tmp=tmp->next[prefix[index]-'a']; 
			}  else {
				return false;
			}
		}
		
		return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
