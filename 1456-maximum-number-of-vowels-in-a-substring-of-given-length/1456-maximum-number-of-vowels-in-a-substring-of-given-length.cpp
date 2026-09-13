class Solution {
public:
    int maxVowels(string s, int k) {

        int count = 0;

        // Step 1: Count vowels in the first window
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {
                count++;
            }
        }

        // Step 2: Store first answer
        int maxAns = count;

        // Step 3: Slide the window
        for (int i = k; i < s.size(); i++) {

            // Remove outgoing vowel
            if (s[i - k] == 'a' || s[i - k] == 'e' ||
                s[i - k] == 'i' || s[i - k] == 'o' ||
                s[i - k] == 'u') {
                count--;
            }

            // Add incoming vowel
            if (s[i] == 'a' || s[i] == 'e' ||
                s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                count++;
            }

            maxAns = max(maxAns, count);
        }

        return maxAns;
    }
};