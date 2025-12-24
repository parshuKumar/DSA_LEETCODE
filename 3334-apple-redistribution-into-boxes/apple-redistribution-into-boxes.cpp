class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = accumulate(begin(apple), end(apple), 0);

        sort(capacity.begin(), capacity.end(), greater<int>());

        for(int i = 0; i < capacity.size(); ++i){
            total -= capacity[i];

            if(total <= 0) return i + 1;
        }

        return 0;
    }
};