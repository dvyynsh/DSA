// class Solution {
// public:
//     bool isPalindrome(string s) {
//         for(int i=0; i<s.length(); i++){
//             if(isalnum(s[i])){
//                 //tolower(s[i]); doesn't modify so do
//                 s[i] = tolower(s[i]);
//                 // Now How we compare first to last charactor?
//                 // I think y need two pointers
//             }
//         }
//     }
// };


class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left <= right) {
            if (!isalnum(s[left])) {
                left++;
            }
            else if (!isalnum(s[right])) {
                right--;
            }
            else if (tolower(s[left]) == tolower(s[right])) {
                left++;
                right--;
            }

            else {
                return false;
            }
        }

        return true;
    }
};