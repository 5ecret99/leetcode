class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int curr_gas{0};
        int total_gas{0};
        int start_pos{0};
        for(int i = 0; i < gas.size(); ++i){
            total_gas+= gas[i] - cost[i];
            curr_gas+= gas[i] - cost[i];

            if(curr_gas < 0){
                curr_gas = 0;
                start_pos = i + 1;
            }
        }
        
        return total_gas < 0 ? -1 : start_pos;
    }
};