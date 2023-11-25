class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int hits{0x000};
        for(auto& triplet : triplets){
            if(triplet[0] > target[0] || triplet[1] > target[1] 
                || triplet[2] > target[2]) continue;
            
            for(int i = 0; i < 3; ++i)
                if(triplet[i] == target[i])
                    hits|= 0x1 << i * 4;
            
            if(hits == 0x111)
                return true;
        }
        
        return false;
    }
};
