class Solution{
    vector<int> parent;
public:
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void union1(int x,int y){
        int l1 = find(x);
        int l2 = find(y);
        if(l1 != l2){
            parent[l1] = l2;
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int maxSize = 0;
        for(int num : nums){
            maxSize = max(maxSize,num);
        }
        int threshold = 1;
        parent.resize(maxSize+1);
        for(int i=0;i<maxSize+1;i++) parent[i] = i;
        for(int num : nums){
            for(int f=1;f*f<=num;f++){
                if(num % f == 0){
                    int div1 = f;
                    int div2 = num/f;
                    if(div1 > 1){
                        union1(div1,num);
                    }
                    if(div2 > 1){
                        union1(div2,num);
                    }
                }
            }
        }

        unordered_map<int,int> teamSizes;
        int maxCount = 0;
        for(int num : nums){
            int leader = find(num);
            teamSizes[leader]++;
            maxCount = max(maxCount , teamSizes[leader]);
        }

        return maxCount;
    }
};

// class Solution {
// public:
//     int gcd(int a,int b){
//         if(a==0) return b;
//         if(a>b){
//             return gcd(a%b,b);
//         }else{
//             return gcd(b%a,a);
//         }
//     }
//     int dfs(int currNode,int identity,vector<vector<int>>& adj,vector<int>& component,vector<bool>& isNum){
//         component[currNode] = identity;
//         int count = isNum[currNode] ? 1:0;
//         for(int neigh : adj[currNode]){
//             if(component[neigh] == 0){
//                 component[neigh] = identity;
//                 count += dfs(neigh,identity,adj,component,isNum);
//             }
//         }
//         // identity++;
//         return count;
//     }
//     int largestComponentSize(vector<int>& nums) {
//         int maxSize = 0;
//         for(int num : nums){
//             maxSize = max(maxSize,num);
//         }
//         int threshold = 1;
//         vector<vector<int>> adj(maxSize+1);
//         vector<bool> isNum(maxSize+1,false);
//         for(int i=0;i<nums.size();i++){
//             int num = nums[i];
//             isNum[num] = true;

//             int temp = num;
//             // for(int f=2;f*f<=temp;f++){
//             //     if(temp%f == 0){
//             //         adj[num].push_back(f);
//             //         adj[f].push_back(num);
//             //         while(temp % f == 0){
//             //             temp = temp/f;
//             //         }
//             //     }     
//             // }
//             // if(temp > 1){
//             //     adj[num].push_back(temp);
//             //     adj[temp].push_back(num);
//             // }
//             for(int f=1;f*f<=num;f++){
//                 if(num%f == 0){
//                     int div1 = f;
//                     int div2 = num/f;

//                     if(div1 > threshold){
//                         adj[num].push_back(div1);
//                         adj[div1].push_back(num);
//                     }
//                     if(div2 > threshold){
//                         adj[num].push_back(div2);
//                         adj[div2].push_back(num);
//                     }
//                 }
//             }
//         }
        
//         vector<int> component(maxSize+1,0);
//         int maxCount = 0;
//         int identity = 1;
//         for(int i=0;i<nums.size();i++){
//             if(component[nums[i]] == 0){
//                 int countNode = dfs(nums[i],identity,adj,component,isNum);
//                 maxCount = max(maxCount , countNode);
//                 identity++;
//             }
            
//         }
//         return maxCount;

//     }
// };