class Solution {
public:
    int myAtoi(string s) {
        auto it = s.begin();
        while(*it == ' '){
            it++;
        }

        int sign = 1;
        if( *it == '-' || *it == '+'){
            sign = (*it == '-') ? -1 : 1;
            cout << "sign " << sign << endl;
            it++;
        }

        long res = 0;
        while (*it >= '0' && *it <= '9'){
            res = - '0' + *it + res * 10;
            if(sign * res >= INT_MAX){
                return INT_MAX;
            }
            else if(sign * res <= INT_MIN){
                return INT_MIN;
            }

            it++;
        }

        return sign * static_cast<int>(res);
    }
};
