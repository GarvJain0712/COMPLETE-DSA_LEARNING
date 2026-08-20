class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map < int , unordered_set<int > > mp;

        for( auto & seats : reservedSeats)
        {
            mp[seats[0]].insert(seats[1]);
        }

        int ans = (n- mp.size())*2;
        // max 2 groups can be seated in a row 


        for(auto &[row,seats] : mp)
        {
            bool left=true;
            bool right=true;
            bool middle = true;

            for (int s=2;s<=5;s++)
            {
                if(seats.count(s)==1)
                {
                    left=false;
                    break;
                }
            }

            for (int s=4;s<=7;s++)
            {
                if(seats.count(s)==1)
                {
                    middle=false;
                    break;
                }
            }

            for (int s=6;s<=9;s++)
            {
                if(seats.count(s)==1)
                {
                    right=false;
                    break;
                }
            }

            if(left && right)
            {
                ans +=2;
            }
            else if (left || right || middle )
            {
                ans +=1;
            }
        }
        return ans ;
    }
};