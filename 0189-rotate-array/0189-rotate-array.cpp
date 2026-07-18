    class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            stack<int> st;

            vector<int >arr;
            int n = nums.size();
            k %= n;

            for(int i=nums.size()-1;i>=n-k;i--)
            {
                st.push(nums.back());
                nums.pop_back();
            }

            for(int i=0;i<k;i++)
            {
                arr.push_back(st.top());
                st.pop();
            }

            for(int i=0;i<nums.size();i++)
            {
                arr.push_back(nums[i]);
            }
            nums.clear();
            for(int i=0;i<arr.size();i++)
            {
                nums.push_back(arr[i]);
            }
        }
    };