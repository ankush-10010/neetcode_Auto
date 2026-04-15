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
        root=new Node();
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
    bool search(string word){
        return searchHelper(word , 0 , root);
    }
    bool searchHelper(const string &word,int idx,Node *node) {
        Node *temp=root;
        if (idx == word.size()) {
            return node->endofWord;
        }
        if(word[idx]!='.'){
            if(node->children.count(word[idx])==0){
                return false;
            }
            return searchHelper(word,idx+1,node->children[word[idx]]);
        }
        for (auto &p : node->children) {
            if (searchHelper(word, idx + 1, p.second)) {
                return true;
            }
        }
        return false;
    }
        
};
