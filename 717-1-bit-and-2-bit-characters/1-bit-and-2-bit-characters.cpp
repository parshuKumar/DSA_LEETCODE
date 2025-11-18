class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();

        int i = 0;
        int cnt = 1;
        while(i < n){
            if((i != n - 1) && (((to_string(bits[i]) + to_string(bits[i + 1])) == "10") || 
            ((to_string(bits[i]) + to_string(bits[i + 1])) == "11"))){
                cnt = 2;
                i += 2;
            }else{
                i++;
                cnt = 1;
            }
        }

       return cnt == 1 ? true : false; 
    }
};