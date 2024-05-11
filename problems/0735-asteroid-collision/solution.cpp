class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;
        for(auto a : asteroids)
        {
            if(a >= 0 || st.empty())
            {
                st.push(a);
                continue;
            }

            while(!st.empty() && st.top() > 0 &&  st.top() < -a) 
                st.pop();
            
            if(!st.empty() && st.top() == -a)
                st.pop();
            else if(st.empty() || st.top() < 0)
                st.push(a);

        }


        vector<int> res(st.size());
        int i = st.size() - 1;
        while(!st.empty() && i > -1)
        {
            res[i--] = st.top();
            st.pop();
        }

        return res; 
    }
};
