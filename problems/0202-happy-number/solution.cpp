class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        set.insert(n);
        auto happy = [](int num){
            int res{0};
            while(num){
                res+= (num%10) * (num%10);
                num/=10;
            }

            return res;
        };

        while(true){
            n = happy(n);
            if(n == 1)
                return true;
            else if(set.contains(n))
                return false;
            
            set.insert(n);
        }
    }
};
