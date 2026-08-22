class Solution {

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> inMST(n,false);

        int totalCost = 0;
        int edgesUsed = 0;

        pq.push({0,0}); // node 0 , cost of 0

        while(!pq.empty()){
            auto [cost , currNode] = pq.top();
            pq.pop();

            if(inMST[currNode]) continue;
            inMST[currNode] = true;
            totalCost += cost;
            edgesUsed++;

            for(int nextNode = 0;nextNode<n;nextNode++){
                if(!inMST[nextNode]){
                    int dist = abs(points[currNode][0] - points[nextNode][0])+
                                abs(points[currNode][1] - points[nextNode][1]);
                    pq.push({dist,nextNode});
                }
            }
        }
        return totalCost;
    }
};


// --> krusal Algo
// class DSU {
// private:
//     vector<int> parent;
//     vector<int> rank;

// public:
//     DSU(int n) {
//         parent.resize(n);
//         iota(parent.begin(), parent.end(), 0);
//         rank.assign(n, 0);
//     }

//     int find(int node) {
//         if (parent[node] == node)
//             return node;
//         return parent[node] = find(parent[node]);
//     }

//     bool unite(int x, int y) {
//         int leaderX = find(x);
//         int leaderY = find(y);

//         if (leaderX == leaderY)
//             return false;

//         if (leaderX != leaderY) {
//             if (rank[leaderX] < rank[leaderY]) {
//                 parent[leaderX] = leaderY;
//             } else if (rank[leaderX] > rank[leaderY]) {
//                 parent[leaderY] = leaderX;
//             } else {
//                 parent[leaderY] = leaderX;
//                 rank[leaderX]++;
//             }
//         }
//         return true;
//     }
// };

// struct Edge {
//     int u;
//     int v;
//     int weight;

//     // bool operator<(const Edge& other) const { return weight < other.weight; }
// };
// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         if (n <= 1)
//             return 0;
        
//         vector<Edge> edges;

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int dist = abs(points[i][0] - points[j][0]) +
//                            abs(points[i][1] - points[j][1]);
//                 edges.push_back({i,j,dist});
//             }
//         }

//         auto cmp = [](const Edge& a,const Edge& b){
//             return a.weight < b.weight;
//         };
//         sort(edges.begin(),edges.end(),cmp);
//         // for(const auto& edge:edges){
//         //     cout << edge.weight << "\t";
//         // }
//         // cout << endl;
//         DSU dsu(n);
//         int totalCost = 0;
//         int edgesCount = 0;

//         for(const auto& edge:edges){
//             if(dsu.unite(edge.u,edge.v)){
//                 totalCost += edge.weight;
//                 edgesCount++;

//                 if(edgesCount == n-1) break;
//             }
//         }

//         return totalCost;
//     }
// };