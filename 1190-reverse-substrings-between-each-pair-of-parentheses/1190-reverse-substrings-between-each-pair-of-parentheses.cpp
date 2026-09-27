// Stack comes in mind
// iterate evry word

class Solution {
public:
    string reverseParentheses(string s) {

        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {

                string temp = "";

                // Pop until '('
                while (st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                // Remove '('
                st.pop();

                // Push the reversed substring back
                for (int j = 0; j < temp.length(); j++) {
                    st.push(temp[j]);
                }

            }
            else {
                st.push(s[i]);
            }
        }

        string ans = "";

        // Pop all characters
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Reverse final answer
        reverse(ans.begin(), ans.end());

        return ans;
    }
};