class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int > arr1;
        vector<int > arr2;
        int n=nums.size();
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i=2;i<n;i++)
       {
           int x=arr1.back();
           int y=arr2.back();
           if(x>y)
           {
                arr1.push_back(nums[i]);
           }
           else
           {
                arr2.push_back(nums[i]);
           }
            
       }
       vector<int > result=arr1;

       result.insert(result.end(), arr2.begin(), arr2.end());

       return result;
    }
};