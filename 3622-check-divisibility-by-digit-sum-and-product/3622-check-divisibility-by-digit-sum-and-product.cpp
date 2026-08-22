class Solution {
public:
    int digitsum(int n)
    {
        int sum =0;
        while(n>0)
        {
            int r=n%10;
            sum+=r;
            n=n/10;
        }
        return sum;
    }
    int digitprod(int n)
    {
        int prod=1;
        while(n>0)
        {
            int r=n%10;
            prod=prod*r;
            n=n/10;
        }
        return prod;
    }
    bool checkDivisibility(int n) {
        int total=digitsum(n)+digitprod(n);
        if(n%total==0)
        {
            return true ;
        }
        else
        {
            return false;
        }
    }
};