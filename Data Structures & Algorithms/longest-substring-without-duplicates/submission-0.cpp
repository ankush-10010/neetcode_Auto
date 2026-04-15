class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //we will create two pointers , for everypointer we will iterate and see whats the longest possible substring for it
        //this approach is leading to n^2 TC
    
        // answer would be right-left+1 , no duplicates from left index to right index in the string
        // one way to think is , build an unordered map , which will contain
        // all the elements of the string
        //then iterate using left and right pointer find the largest substring which have 1,0 freq for all elts present
        
        unordered_map<char,int> charMap;
        int left = 0;
        int maxLength = 0;
        for(int right = 0; right < s.size() ; right++){
            char currentChar = s[right];
            if(charMap.find(currentChar) != charMap.end() && charMap[currentChar] >= left){
                left = charMap[currentChar] + 1;
            }
            charMap[currentChar] = right;

            maxLength = max(maxLength , right - left + 1);
        }
        return maxLength;
    }
};
