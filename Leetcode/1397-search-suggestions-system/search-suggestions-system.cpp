class Solution {
    struct TrieNode{
        TrieNode* children[26];
        vector<string> suggestions;
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
        }
        ~TrieNode(){
            for(int i=0;i<26;i++){
                if(children[i]) delete children[i];
            }
        }
    };
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        TrieNode* root = new TrieNode();
        for(const string& word: products){
            TrieNode* curr = root;
            for(char c:word){
                int index = c - 'a';
                if(curr->children[index] == nullptr){
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
                if(curr->suggestions.size() < 3){
                    curr->suggestions.push_back(word);
                }
            }
        }

        vector<vector<string>> result(searchWord.size());
        TrieNode* curr = root;
        for(int i=0;i<searchWord.size();i++){
            int index = searchWord[i] - 'a';
            if(curr != nullptr && curr->children[index] != nullptr){
                curr = curr->children[index];
                result[i] = curr->suggestions;
            }else{
                curr = nullptr;   
            }
        }
        delete root;
        return result;
    }
};