class TrieNode{
public: 
    TrieNode* children[26];
    string* word;
    bool endofword;
    TrieNode(){
        endofword = false;
        word = nullptr;
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
    }
};
class Trie{ 
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string& word){
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
        current->word = new string(word);
    }

};
class Solution {
private:
    Trie* trie = new Trie();
    // can access like trie->insert("apple")
    void dfs(int i,int j,TrieNode* current,vector<vector<char>>& board,vector<string>& result,vector<vector<bool>>& visited){
        // base case ? 
        char ch = board[i][j];
        int index = ch - 'a';
        if(visited[i][j] == true || current->children[index] == nullptr){
            return;
        }

        current = current->children[index];
        // currentWord += ch;

        if(current->word != nullptr){
            result.push_back(*(current->word));
            current->word = nullptr;
        }
        visited[i][j] = true;
        // paths ?
        vector<pair<int,int>> paths;
        paths.push_back({i+1,j});
        paths.push_back({i,j+1});
        paths.push_back({i,j-1});
        paths.push_back({i-1,j});

        for(auto path: paths){
            int nx = path.first;
            int ny = path.second;
            
            if(nx <0 || ny<0 || nx >= board.size() || ny >= board[0].size()){
                continue;
            }
            dfs(nx,ny,current,board,result,visited);
            // do some operation

            //backtrack from it to explore other path
        }
        visited[i][j] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        int rows = board.size();
        int cols = board[0].size();
        vector<string> result;
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(string word : words){
            trie.insert(word);
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                dfs(i,j,trie.root,board,result,visited);
            }
        }
        return result; 
    }
};
