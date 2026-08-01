class Solution {
public:
    int count = 0;

    void expand(string &s, int left, int right)
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            count++;      // Every successful expansion is a palindrome

            left--;
            right++;
        }
    }

    int countSubstrings(string s) {

        for(int i = 0; i < s.size(); i++)
        {
            // Odd length palindromes
            expand(s, i, i);

            // Even length palindromes
            expand(s, i, i + 1);
        }

        return count;
    }
};