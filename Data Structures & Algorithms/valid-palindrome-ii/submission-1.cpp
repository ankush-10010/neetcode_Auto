class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left <= right){
            if(s[left] != s[right]){
                break;
            }
            left++;
            right--;
        }
        int temp_left = left;
        int temp_right = right;
        temp_right--;
        bool a = true;
        while(temp_left <= temp_right){
            if(s[temp_left] != s[temp_right]){
                a = false;
            }
            temp_left++;
            temp_right--;
        }
        temp_left = left;
        temp_right = right;
        temp_left++;
        bool b = true;
        while(temp_left <= temp_right){
            if(s[temp_left] != s[temp_right]){
                b = false;
            }
            temp_left++;
            temp_right--;
        }
        return a || b;
    }
};