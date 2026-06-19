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
class Trie{ 
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
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
    bool search(string word){
        TrieNode* current = root;
        for(char ch:word){
            int index = ch - 'a';
            if(current->children[index] == nullptr){
                return false;
            }
            current = current->children[index];
        }
        return current->endofword;
    }
    bool startWith(char ch){
        TrieNode* current = root;
        int index = ch - 'a';
        if(current->children[index] == nullptr){
            return false;
        }
        current = current->children[index];
        return true;
    }
};
class Solution {
private:
    Trie* trie = new Trie();
    // can access like trie->insert("apple")
    void dfs(int i,int j,TrieNode* current,vector<vector<char>>& board,string currentWord,vector<string>& result,vector<vector<bool>>& visited){
        // base case ? 
        char ch = board[i][j];
        int index = ch - 'a';
        if(visited[i][j] == true || current->children[index] == nullptr){
            return;
        }

        current = current->children[index];
        currentWord += ch;

        if(current->endofword){
            result.push_back(currentWord);
            current->endofword = false;
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
            dfs(nx,ny,current,board,currentWord,result,visited);
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
                dfs(i,j,trie.root,board,"",result,visited);
            }
        }
        return result; 
    }
};
