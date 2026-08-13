class Solution {
public:
    struct Node{
        char preChar;
        int preLen;

        char sufChar;
        int sufLen;

        int maxLen;
        int size;
    };

    Node merge(Node left,Node right){
        Node parent;
        parent.preChar = left.preChar;
        parent.sufChar = right.sufChar;
        parent.maxLen = max(left.maxLen,right.maxLen);
        parent.size = left.size + right.size;

        bool isBridge = (left.sufChar == right.preChar);
        if(isBridge){
            parent.maxLen = max(parent.maxLen , left.sufLen + right.preLen);
        }
        if(isBridge && left.preLen == left.size){
            parent.preLen = left.size + right.preLen;
        }else{
            parent.preLen = left.preLen;
        }

        if(isBridge && right.sufLen == right.size){
            parent.sufLen = left.sufLen + right.size;
        }else{
            parent.sufLen = right.sufLen;
        }
        return parent;
    }

    void build(int treeIndex ,int left,int right,const string& s,vector<Node>& tree){
        if(left == right){
            tree[treeIndex].preChar = s[left];
            tree[treeIndex].sufChar = s[left];
            tree[treeIndex].preLen = 1;
            tree[treeIndex].sufLen = 1;
            tree[treeIndex].maxLen = 1;
            tree[treeIndex].size = 1;
            return;
        }

        int mid = left + (right - left)/2;
        int leftChild = 2*treeIndex;
        int rightChild = 2*treeIndex+1;
        build(leftChild,left,mid,s,tree);
        build(rightChild,mid+1,right,s,tree);

        tree[treeIndex] = merge(tree[leftChild],tree[rightChild]);
    }
    void update(int treeIndex,int left,int right,int targetIndex,char newChar,vector<Node>& tree){
        if(left == right){
            tree[treeIndex].preChar = newChar;
            tree[treeIndex].sufChar = newChar;
            return;
        }
        int mid = left + (right - left)/2;
        int leftChild = 2*treeIndex;
        int rightChild = 2*treeIndex+1;

        if(targetIndex <= mid){
            update(leftChild,left,mid,targetIndex,newChar,tree);
        }else{
            update(rightChild,mid+1,right,targetIndex,newChar,tree);
        }

        tree[treeIndex] = merge(tree[leftChild],tree[rightChild]);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        vector<Node> tree(4*n);
        build(1,0,n-1,s,tree);
        int k = queryCharacters.size();

        vector<int> result(k);
        for(int i=0;i<k;i++){
            int targetIndex = queryIndices[i];
            char newChar = queryCharacters[i];

            update(1,0,n-1,targetIndex,newChar,tree);
            result[i] = tree[1].maxLen;
        }

        return result;
    }
};