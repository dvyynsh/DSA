class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0; i<s.length(); i++){
            char ch=s[i];
            ans+=('z' - ch + 1)*(i+1);   // if ch='a' -----> (122-97+1) = 26 
        }
        return ans;
    }
};