class Solution {
public:
int product(int n)
{
    int p=1;
    while(n>0)
    {
        int r=n%10;
        p=p*r;
        n=n/10;
    }
    return p;
}
    int smallestNumber(int n, int t) {

        while(true)
        {
            if(product(n)%t==0)
            {
                return n;
            }
            n++;
        }
    }
};