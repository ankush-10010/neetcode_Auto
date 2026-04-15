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
    bool canAttendMeetings(vector<Interval>& intervals) {
        // basically we will have to find if there is any overlapping or not
        if(intervals.size() == 0){
            return true;
        }
        sort(intervals.begin(),intervals.end(),[](const Interval& a,const Interval& b){
            return a.start < b.start;
        });
        int prevEnd = intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            int end = intervals[i].end;
            if(intervals[i].start < prevEnd){
                return false;
            }else{
                prevEnd = end;
            }
        }
        return true;
    }
};
