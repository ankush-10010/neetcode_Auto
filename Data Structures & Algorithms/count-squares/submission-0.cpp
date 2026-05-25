class CountSquares {
private:
    int pointCounts[1001][1001] = {0};
    vector<pair<int, int>> points;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        
        pointCounts[x][y]++;
        points.push_back({x, y});
    }
    
    int count(vector<int> point) {
        int qx = point[0];
        int qy = point[1];
        int totalSquares = 0;
        
        for (auto& p : points) {
            int x = p.first;
            int y = p.second;

            if (abs(qx - x) == abs(qy - y) && qx != x) {
                totalSquares += pointCounts[qx][y] * pointCounts[x][qy];
            }
        }
        return totalSquares;
    }
};
