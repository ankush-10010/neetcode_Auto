class Node{
public:
    bool endofWord;
    unordered_map<char,Node*> children;
    Node(){
        endofWord=false;
    }
};
class WordDictionary {
    Node *root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->children.count(word[i])==0){
                temp->children[word[i]]= new Node();
            }
            temp=temp->children[word[i]];
        }
        temp->endofWord=true;
    }
    
    bool search(string word) {
        return SearchHelper(word,0,root);
    }
    bool SearchHelper(string &word,int index,Node* node){
        // Node *temp=Node;
        if(index==word.size()){
            return node->endofWord;
        }
        if(word[index]!='.'){
            if(node->children.count(word[index])==0){
                return false;
            }
            SearchHelper(word , index+1, node->children[word[index]]);
        }
        for(auto &p:node->children){
            if(SearchHelper(word,index+1,p.second)){
                return true;
            }
        }
        return false;

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */