class Solution {
public:
bool check(int st , int end, string s)
{
        while(st<end)
        {
            if(s[st]!=s[end])
            {
                return false;
            }
            st++;
            end--;
        }

        return true ;
}
    bool validPalindrome(string s) {
        int left =0;
        int right =s.length()-1;

        while(left<right)
        {
            if(s[left]==s[right])
            {
                left++;
                right--;
            }
            else
            {
                return check(left+1,right,s) || check(left,right-1,s);
            }
        }
        return true;
    }
};