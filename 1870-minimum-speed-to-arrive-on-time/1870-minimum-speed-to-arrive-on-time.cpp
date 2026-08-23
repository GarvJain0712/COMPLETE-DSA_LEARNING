class Solution {
public:
int check(int k , double h , vector<int >& d)
{
    double hr=0;
    for(int i=0;i<d.size()-1;i++)
    {
        hr +=(d[i]+k-1)/k;
    }
    hr += (double)d.back() / k;
    return hr<=h;
}
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low =1;
        int high=1e7;
      if(!check(high, hour, dist))
            return -1;
        while(low <high)
        {
            int mid = low + (high-low )/2;

            if(check(mid , hour , dist ))
            {
                high =mid ;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
};