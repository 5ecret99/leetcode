class Solution {
private:
    bool suficient_speed(vector<int>& piles, int h, int k){
        double hours{0};
        for(const auto& pile : piles){
            hours += ceil(pile/static_cast<double>(k));
            if(hours > h)
                return false; 
        }

        return true;
    }

    int bin_search(vector<int>& piles, int h, int begin, int end) {
        if (end < begin) return -1;
        int mid = begin + (end - begin)/2;
        if(suficient_speed(piles, h, mid)){
            auto res = bin_search(piles, h, begin, mid - 1);
            return res == -1 ? mid : res;
        }
        else{
            return bin_search(piles, h, mid + 1, end);
        }
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_pile = *max_element(piles.begin(), piles.end());
        return bin_search(piles, h, 0, max_pile);
    }
};