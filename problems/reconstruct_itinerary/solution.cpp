class Solution {
private:
    map<string, multiset<string>> targets;
    vector<string> route;
    void visit(string airport){
        while(!targets[airport].empty()){
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        
        route.push_back(airport);
    };

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& ticket : tickets)
            targets[ticket[0]].insert(ticket[1]);
        
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
};