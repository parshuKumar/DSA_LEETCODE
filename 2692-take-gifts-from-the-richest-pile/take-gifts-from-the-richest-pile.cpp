class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for(int a : gifts){
            pq.push(a);
        }

        while(k--){
            int cur = pq.top();
            int sqroot = sqrt(cur);
            pq.pop();
            pq.push(sqroot);
        }

        long long sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};