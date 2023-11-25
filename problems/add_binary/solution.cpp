class Solution {
public:
    string addBinary(string a, string b) {
        int remainder{0};
        auto ita = a.rbegin();
        auto itb = b.rbegin();
        string res;
        while(ita < a.rend() || itb < b.rend() || remainder){
            if(ita < a.rend()){ 
                remainder+= *ita - '0';
                ++ita;
            }
            if(itb < b.rend()){ 
                remainder+= *itb - '0';
                ++itb;
            }

            res+= remainder % 2 + '0';
            remainder/= 2;
        }

        return string{res.rbegin(), res.rend()};
    }
};