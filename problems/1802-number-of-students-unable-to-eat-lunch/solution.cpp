class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        array<int, 2> st_count{{0, 0}};
        for(auto s : students)
            st_count[s]++;
        
        for(auto s : sandwiches)
            if(st_count[s])
                --st_count[s];
            else
                return st_count[1 - s];
        
        return 0;
    }
};
