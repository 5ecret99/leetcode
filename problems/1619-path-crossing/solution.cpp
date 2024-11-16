class Solution 
{
public:
    bool isPathCrossing(string& path) 
    {
        pair<int, int> curr{0, 0};
        set<pair<int, int>> visited{curr};
        for(auto p : path)
        {
            switch(p)
            {
                case 'N':        
                    ++curr.second;
                    break;
                case 'S':        
                    --curr.second;
                    break;
                case 'E':        
                    ++curr.first;
                    break;
                case 'W':
                    --curr.first;
                    break;
            }

            if(visited.contains(curr))
                return true;
            
            visited.insert(curr);
        }

        return false;       
    }
};
