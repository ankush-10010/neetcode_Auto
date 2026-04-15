/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 1){
            return 1;
        }
        if(intervals.size() == 0){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](const Interval& a,const Interval& b){
            return a.start < b.start;
        });
        int n = intervals.size();
        vector<int> start(n);
        vector<int> end(n);
        for(int i=0;i<n;i++){
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }
        // we have two vectors , start and end  , consisting of 
        //start and end values of the interval according to the original index
        sort(end.begin(),end.end());
        int startPointer = 0;
        int endPointer = 0;
        int activeRooms = 0;
        int maxRooms = 0;
        while(startPointer < intervals.size()){
            if(start[startPointer] < end[endPointer]){
                activeRooms++;
                maxRooms = max(maxRooms , activeRooms);
                startPointer++;
            }else{
                activeRooms--;
                endPointer++;
            }
        }
        return maxRooms;
    }
};
