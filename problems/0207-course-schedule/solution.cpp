class Solution {
private:
    map<int, vector<int>> _mp;
    unordered_set<int> _visited{};

    bool dfs(int course){
        if(_visited.find(course) != _visited.end()) return false;
        if(_mp[course].empty()) return true;

        _visited.insert(course);
        for(auto crs : _mp[course])
            if(!dfs(crs)) return false;
        
        _visited.erase(course);
        _mp[course].clear();
        return true;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto pre : prerequisites)
            _mp[pre[0]].push_back(pre[1]);
        
        for(int i = 0; i < numCourses; i++)
            if(!dfs(i)) return false;

        return true; 
    }
};
