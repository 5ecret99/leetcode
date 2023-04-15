class Solution {
public:
    string convert(string s, int numRows) {
        auto columns = 2 * numRows - 2;
        if( columns < 2 || s.size() <= numRows){
            return s;
        }

        string solution{""};
        for(int row = 0; row < numRows; row++){
            auto index = row;
            while(index < s.size()){
                solution+= s[index];
                index+= columns;//next column
                if(row && row < numRows - 1){ // check for zigzag letter between
                    auto zigzag = index - (2 * row);
                    if(zigzag < s.size() &&  zigzag >= 0 ){
                        solution+= s[zigzag];   
                    }    
                }
            }
        }

        return solution;
    }
};
