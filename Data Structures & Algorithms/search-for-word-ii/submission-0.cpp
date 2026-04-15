class Node{
    public: 
        unordered_map<char,Node*> children;
        bool endofWord;     
        string word;
        Node(){
            endofWord = false;
        }
    };

class Trie{
    public:
        Node* root;
        Trie(){
            root = new Node();
        }
        void insert(string word){
            Node *temp = root;
            for(int i=0;i<word.size();i++){
                if(temp->children[word[i]] == 0){
                    temp->children[word[i]] = new Node();
                }
                temp = temp->children[word[i]];
            }
            temp->endofWord = true;
            temp->word = word;
        }
    };

class Solution {
public:
    vector<string> result;
    void dfs(int i,int j,Node* node,vector<vector<char>>& board){
        int row = board.size();
        int col = board[0].size();
        
        if(node->children.count(board[i][j])==0){
            return;
        }

        node = node->children[board[i][j]];

        if(node->endofWord){
            result.push_back(node->word);
            node->endofWord = false;
        }
        

        vector<pair<int,int>> paths;
        paths.push_back({i+1,j});
        paths.push_back({i,j+1});
        paths.push_back({i-1,j});
        paths.push_back({i,j-1});
        
        char temp = board[i][j];
        board[i][j] = '#';
        for(auto path: paths){
            int x = path.first;
            int y = path.second;
            // if(x<0 || y<0 || x>=row || y>=col || board[x][y]=='#'){
            //     return;
            // }
            // dfs(x,y,node,board);

            if(x>=0 && y>=0 && x<row && y<col && board[x][y]!='#'){
                dfs(x,y,node,board);
            }
        }
        board[i][j] = temp ; //backtrack
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // for a given i,j the possible paths are 
        // (i+1,j),(i-1,j),(i,j+1),(i,j-1) --> dfs ?
        // first implement a trie and then use dfs to search in the grid
        Trie trie;
        for(int i=0;i<words.size();i++){
            trie.insert(words[i]);
        }
        // ideally all the words should be inserted in the trie by now

        int rows = board.size();
        int cols = board[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                dfs(i,j,trie.root,board);
            }
        }
        return result;

    }
};
