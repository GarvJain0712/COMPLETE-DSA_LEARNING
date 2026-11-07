class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count =0;
        int n =arr1.size();
        int m =arr2.size();

        for(int i=0;i<n;i++)
        {
            int present=-1;
            int ele1=arr1[i];
            for(int j=0;j<m;j++)
            {
                int diff=abs(ele1-arr2[j]);
                if(diff<=d)
                {
                   present=1;
                }
            }
            if(present==-1)
            {
                count++;
            }
        }
        return count;
    }
};