class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize){
        if(hand.size() % groupSize) return false;
        map<int, int> hand_;
        for(const auto& card : hand)
            hand_[card]++;

        while(!hand_.empty()){
            auto curr{hand_.begin()->first};
            for(int i = 0; i < groupSize; ++i)
                if(!hand_.contains(curr + i)) return false;
                else if(!--hand_[curr + i]) hand_.erase(curr + i);
        }

        return true;
    }
};
