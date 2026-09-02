class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool even = true;
        bool odd = true;
        for(int i=0;i<nums1.size();i++){
            nums1[i] = nums1[i]%2;
        }

        vector<int> nums2(nums1.size());
        if(even){
            // for each i , nums1[i] --> 0 
            // bool cantEven = false;
            for(int i=0;i<nums1.size();i++){
                bool cantEven = false;
                if(nums1[i] == 0){
                    continue;
                }
                for(int j=0;j<nums1.size();j++){
                    if(j == i) continue;
                    if((nums1[j] - nums1[i]) == 0){
                        cantEven = true;
                    }
                }
                if(!cantEven){
                    even = false;
                }
            }
        }
        if(odd){
        // for each i , nums1[i] --> 0 
        // bool cantEven = false;
            for(int i=0;i<nums1.size();i++){
                bool cantOdd = false;
                if(nums1[i] == 1){
                    continue;
                }
                for(int j=0;j<nums1.size();j++){
                    if(j == i) continue;
                    if((nums1[j] - nums1[i]) == 1){
                        cantOdd = true;
                    }
                }
                if(!cantOdd){
                    odd = false;
                }
            }
        }

        return (even || odd);
    }
};