class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> graph;

        for(int i=0;i<equations.size();i++){
            string first_element = equations[i][0];
            string second_element = equations[i][1];

            double value = values[i];

            graph[first_element].push_back({second_element,value});
            graph[second_element].push_back({first_element,1.0/value});
        }

        //graph has been populated

        vector<double> results;
        for(int i=0;i<queries.size();i++){
            string start = queries[i][0];
            string end = queries[i][1];

            if(graph.find(start) == graph.end() || graph.find(end) == graph.end()){
                //basically if they dont exist in the graph
                results.push_back(-1.0);
                continue;
            }

            queue<pair<string,double>> q;
            unordered_set<string> visited;

            q.push({start,1.0});
            visited.insert(start);
            bool found = false;

            while(!q.empty()){
                string currElement = q.front().first;
                double currProduct = q.front().second;
                q.pop();

                if(currElement == end){
                    results.push_back(currProduct);
                    found = true; 
                    break;
                }

                for(const auto& neighbor:graph[currElement]){
                    string neighbor_string = neighbor.first;
                    double weight = neighbor.second;

                    if(!visited.count(neighbor_string)){
                        q.push({neighbor_string,currProduct*weight});
                        visited.insert(neighbor_string);
                    }
                }
            }
            if(!found){
                results.push_back(-1.0);
            }
        }
        return results;
    }
};