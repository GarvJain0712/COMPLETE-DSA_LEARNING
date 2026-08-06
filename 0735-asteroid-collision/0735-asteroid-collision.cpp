class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int > st;

        for(int asteroid : asteroids)
        {
            bool destroyed =  false;
            while(!st.empty() && st.top()>0 && asteroid <0)
            {
                // collision occur

                if(st.top()<abs(asteroid))
                {
                    st.pop();
                }
                else if ( st.top()==abs(asteroid))
                {
                    st.pop();
                    destroyed=true;
                    break;
                }
                else 
                {
                    destroyed=true;
                    break;
                }
            }

            if(!destroyed)
            {
                st.push(asteroid);
            }
        }

        vector<int > ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();

        }

    reverse(ans.begin(), ans.end());
return ans ;
        
    }
};