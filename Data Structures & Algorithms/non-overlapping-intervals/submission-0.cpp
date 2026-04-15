class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // should i remove the one with longest lengths?
        //first we should sort the array
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int result = 0;
        int prevEnd = intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start >= prevEnd){
                prevEnd = end;
            }else{
                result ++;
                prevEnd = min(prevEnd,end);
            }
        }
        return result;
    }
};
