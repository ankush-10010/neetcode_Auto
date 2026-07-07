class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int> meeting_rooms(n,0);
        auto cmp1 = [](const pair<long long,int>& a, const pair<long long,int>& b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first > b.first;
        };
        auto cmp2 = [](int a, int b){
            return a > b;
        };

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,decltype(cmp1)> occupied_rooms(cmp1);
        priority_queue<int,vector<int>,decltype(cmp2)> available_rooms(cmp2);
        for(int i=0;i<n;i++){
            available_rooms.push(i);
        }
        for(int i=0;i<meetings.size();i++){
            long long start = meetings[i][0];

            while(!occupied_rooms.empty() && occupied_rooms.top().first <= start){
                int room = occupied_rooms.top().second;
                available_rooms.push(room);
                occupied_rooms.pop();
            }

            if(!available_rooms.empty()){
                int room = available_rooms.top();
                occupied_rooms.push({meetings[i][1],room});
                available_rooms.pop();
                meeting_rooms[room]++;
            }else{
                auto it = occupied_rooms.top();
                int room = it.second;
                long long min_end_time = it.first;

                long long duration = meetings[i][1] - meetings[i][0];
                long long new_end_time = duration + min_end_time;

                occupied_rooms.pop();
                occupied_rooms.push({new_end_time,room});
                meeting_rooms[room]++;
            }

        }

        int max_meetings = 0;
        int best_room = 0;

        for(int i=0;i<n;i++){
            if(meeting_rooms[i] > max_meetings){
                max_meetings = meeting_rooms[i];
                best_room = i;
            }
        }

        return best_room;
    }
};