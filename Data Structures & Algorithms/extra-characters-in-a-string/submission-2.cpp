class TrieNode{
public:
    TrieNode* children[26];
    bool endofword;
    TrieNode(){
        endofword = false;
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
    }
};
class Solution {
public:
    TrieNode* root = new TrieNode();
    void insert(TrieNode* root,string word){
        TrieNode* current = root;
        for(char ch: word){
            int index = ch - 'a';
            if(current->children[index] == nullptr){
                TrieNode* newNode = new TrieNode();
                current->children[index] = newNode;
            }
            current = current->children[index];
        }
        current->endofword = true;
    }   
    
    int minExtraChar(string s, vector<string>& dictionary) {

        int n = s.size();
        vector<int> dp(n+1,0);
        for(const string& s: dictionary){
            insert(root,s);
        }
        
        for(int i=0;i<s.size();i++){
            dp[i+1] = max(dp[i+1],dp[i]);
            TrieNode* current = root;
            for(int j=i;j<n;j++){
                int index = s[j] - 'a';
                if(current->children[index] == nullptr){
                    break;
                }
                current = current->children[index];
                if(current->endofword == true){
                    int wordLength = j-i+1;
                    dp[j+1] = max(dp[j+1],dp[i] + wordLength);
                }
            }
        }
        return n - dp[n];
    }
};