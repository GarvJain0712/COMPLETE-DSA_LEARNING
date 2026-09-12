class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();

        if(n % groupSize!=0)
        {
            return false;
        }

        map<int ,int > mp;

        for (auto it : hand)
        {
            mp[it]++;
        }

        while(!mp.empty())
        {
            int start=mp.begin()->first;

            for(int i=0;i<groupSize;i++)
            {
                int next=start+i;

                if(mp[next]==0)
                {
                    return false;
                }
                mp[next]--;
                if(mp[next]==0)
                {
                    mp.erase(next);
                }
            }
        }

       return true ; 
    }
};