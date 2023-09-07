class Solution {
public:
    double myPow(double x, long n) {
        if(n < 0){
            x = 1/x;
            n = labs(n);
        }

        double res{1};
        while(n)
        {
            if( n & 1) //check if its odd
                res*= x;
            
            x*=x;
            n>>=1; //dividing by 2
        }

        return res;

    }
};