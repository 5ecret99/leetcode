class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        using tuple = pair<int, float>;
        priority_queue<tuple, vector<tuple>, greater<tuple>> pos_time;
        for(int i = 0; i < position.size(); ++i){
            pos_time.push({position[i], float(target - position[i]) / speed[i]});
        } 

        stack<float> fleets;
        while(!pos_time.empty()){
            while(!fleets.empty() && pos_time.top().second >= fleets.top())
                fleets.pop();
            
            fleets.push(pos_time.top().second);
            pos_time.pop();
        }

        return fleets.size();
    }
};