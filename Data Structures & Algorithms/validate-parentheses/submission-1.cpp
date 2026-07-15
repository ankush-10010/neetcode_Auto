#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // Map every closing bracket to its corresponding opening bracket
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        for (char c : s) {
            // If the character is a closing bracket (it exists as a key in our map)
            if (closeToOpen.count(c)) {
                // Stack must not be empty AND top of stack must be the matching open bracket
                if (!st.empty() && st.top() == closeToOpen[c]) {
                    st.pop();
                } else {
                    return false;
                }
            } 
            // If it's an opening bracket
            else {
                st.push(c);
            }
        }
        
        // If the stack is empty, all brackets were closed successfully
        return st.empty();
    }
};