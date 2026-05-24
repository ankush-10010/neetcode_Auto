class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> emailToName;
        
        for (const auto& account : accounts) {
            string name = account[0];
            string firstEmail = account[1]; 
            for (int i = 1; i < account.size(); i++) {
                string currentEmail = account[i];
                emailToName[currentEmail] = name;
                
                // Draw an undirected edge between the first email and the current email
                // (Connecting an email to itself is harmless here, but we connect the rest)
                graph[firstEmail].push_back(currentEmail);
                graph[currentEmail].push_back(firstEmail);
            }
        }
        unordered_set<string> visited;
        vector<vector<string>> mergedAccounts;

        for (const auto& pair : emailToName) {
            string email = pair.first;
            string name = pair.second;
            
            if (!visited.count(email)) {
                vector<string> component;
                queue<string> q;
                
                q.push(email);
                visited.insert(email);
                
                while (!q.empty()) {
                    string curr = q.front();
                    q.pop();
                    
                    component.push_back(curr); // Add the email to our current cluster
                    
                    // Visit all connected emails
                    for (const string& neighbor : graph[curr]) {
                        if (!visited.count(neighbor)) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
                
                // Problem requirements: Emails must be sorted alphabetically
                sort(component.begin(), component.end());
                
                // Insert the person's name at the very front of the sorted emails
                component.insert(component.begin(), name);
                
                // Add this fully merged account to our final answer
                mergedAccounts.push_back(component);
            }
        }
        
        return mergedAccounts;
    }
};