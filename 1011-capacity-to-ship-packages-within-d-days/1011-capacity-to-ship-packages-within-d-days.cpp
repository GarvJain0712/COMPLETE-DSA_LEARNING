class Solution {
public:
    bool check(int k , int d, vector<int > weights)
    {
        int days=1;
        int capacity=0;
        for(int w : weights)
        {
            if(w+capacity>k)
            {
                days++;
                capacity=0;
            }
            capacity+=w;
        }
        return days<=d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = * max_element(weights.begin(), weights.end());
        int high=0;

        for(int i=0;i<weights.size();i++)
        {
            high+=weights[i];
        }

        while(low < high)
        {
            int mid = low + ( high-low)/2;

            if(check(mid, days, weights))
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};