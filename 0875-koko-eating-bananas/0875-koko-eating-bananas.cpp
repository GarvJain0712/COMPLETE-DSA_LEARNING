class Solution {
public:
bool check(int k , int h , vector<int > piles)
{
    long long hr=0;

    for(int pile : piles )
    {
        hr+=(pile+k-1)/k;
    }

    return hr<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high = * max_element(piles.begin(), piles.end());

        while(low <high)
        {
            int mid = low + (high -low )/2;

            if(check(mid,h , piles))
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