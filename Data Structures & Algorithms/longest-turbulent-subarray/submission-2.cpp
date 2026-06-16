class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        // a subarray arr[i] ,.. , arr[j] --> 
        int inc = 1;
        int dec = 1;
        int maxLen = INT_MIN;
        if(arr.size() == 1){
            return 1;
        }
        for(int i=1;i<arr.size();i++){
            if(arr[i] < arr[i-1]){
                // it went down 
                dec=inc+1;
                inc = 1;
            }else if(arr[i] > arr[i-1]){
                inc=dec+1;
                dec = 1;
            }else if (arr[i] == arr[i-1]){
                inc = 1;
                dec = 1;
            }
            maxLen = max(maxLen,max(inc,dec));
        }
        return maxLen;
    }
};