class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0 ;
        int right=numbers.size()-1;
        while(left<right){
            if((numbers[left]+numbers[right])==target){
                break;
            }
            if((numbers[left]+numbers[right])>target){
                right--;
            }
            if((numbers[left]+numbers[right])<target){
                left++;
            }
        }
        vector<int> output;
        output.push_back(left+1);
        output.push_back(right+1); 
        return output; 
    }
};
