class Solution {
public:
    bool checkOnesSegment(string s) {
        bool foundZero = false;

        if(s.size() == 1) return true;

        for(int i = 1; i < s.size(); ++i){
            
            if(s[i] == '0'){
                foundZero = true;
            }

            if(s[i] == '1' && foundZero == true){
                return false;
            }
        }

        return true;
    }
};