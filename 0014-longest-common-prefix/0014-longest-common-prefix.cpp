// "if first character of string matches with second one and third one we keep incrementing i+1 then when character not matching we stop and return that part."

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";

        for (int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length())   // range se bahar agar like accessing arr[3] in "ab" string
                    return ans;             // stop
                if (strs[j][i] != ch)
                    return ans;             // stop
            }

            ans += ch;
        }

        return ans;
    }
};