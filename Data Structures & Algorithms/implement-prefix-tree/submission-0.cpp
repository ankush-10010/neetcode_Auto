class Node{
public:
    unordered_map<char , Node*> children;
    bool endofWord;
    Node(){
        endofWord=false;
    }

};
class PrefixTree {
    Node *root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *temp= root;
        for(int i=0 ; i<word.size() ; i++){
            if(temp->children.count(word[i])==0){
                temp->children[word[i]]= new Node();
            }
            temp=temp->children[word[i]];
        }
        temp->endofWord=true;
    }
    
    bool search(string word) {
        Node *temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->children.count(word[i])==0){
                return false;
            }
            temp=temp->children[word[i]];
        }
        if(temp->endofWord==true){
            return true;
        }else{
            return false;
        }

    }
    
    bool startsWith(string prefix) {
        Node *temp=root;
        for(int i=0;i<prefix.size();i++){
            if(temp->children.count(prefix[i])==0){
                return false;
            }
            temp=temp->children[prefix[i]];
        }
        return true;
    }
};
