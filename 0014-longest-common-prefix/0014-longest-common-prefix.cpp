// "if first character of string matches with second one and third one we keep incrementing i+1 then when character not matching we stop and return that part."

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";

        // Take every character of the first string
        for (int i = 0; i < strs[0].length(); i++) {

            char ch = strs[0][i];

            // Compare this character with every other string
            for (int j = 1; j < strs.size(); j++) {

                // Edge Case 1: Current string is shorter
                if (i >= strs[j].length())
                    return ans;

                // Edge Case 2: Character doesn't match
                if (strs[j][i] != ch)
                    return ans;
            }

            // Everyone matched → add character
            ans += ch;
        }

        return ans;
    }
};