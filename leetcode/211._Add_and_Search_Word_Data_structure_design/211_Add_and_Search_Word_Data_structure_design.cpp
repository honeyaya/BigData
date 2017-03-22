class TrieNode{
public:
	bool state;
	TrieNode *next[26];
	TrieNode(){
		for(int i = 0; i < 26; i++){
			next[i] = NULL;
		}
		state = false;
	} 
};

class WordDictionary {
TrieNode *root;

public:
    /** Initialize your data structure here. */
    WordDictionary() {
       root = new TrieNode(); 
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
    	TrieNode *tmp = root;
        for(int i = 0; i < word.length(); i++){
        	if(tmp->next[word[i]-'a'] == NULL){
        		tmp->next[word[i]-'a'] = new TrieNode();
			}
			tmp=tmp->next[word[i]-'a']; 
		}
		tmp->state = true;
    }
    
      bool query(string &word, int depth,TrieNode* tmp){
    	if(!tmp) return false;
    	for(int i = depth; i < word.length(); i++){
    		if(word[i]=='.'){
    			for(int j = 0; j < 26; j++){
    				if(query(word,i+1,tmp->next[j])) return true;
 				}
 				return false;
			} 
			if(tmp->next[word[i]-'a']==NULL) return false;
			tmp=tmp->next[word[i]-'a'];
		}
		return tmp->state;
	}
	
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return query(word,0,root);
    }
    
  
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
