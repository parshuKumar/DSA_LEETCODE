class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        
        queue<int> q;
        set<int> visited;

        q.push(id);

        int curLevel = 0;  
        while(!q.empty()){
            int size = q.size();

            for(int i = 0;  i < size; ++i){
                int curId = q.front();
                visited.insert(curId);
                q.pop();
                for(int fr : friends[curId]){
                    if(visited.contains(fr)) continue;
                    q.push(fr);
                    visited.insert(fr);
                }
            }
            curLevel++;
            if(curLevel == level){
                break;
            }
        }
        map<string, int> mp;
        while(!q.empty()){
            int curId = q.front();
            q.pop();
            for(auto c : watchedVideos[curId]){
                mp[c]++;
            }
        }
        vector<pair<string, int>> help;
        for(auto a : mp){
            help.push_back({a.first, a.second});
        }

        sort(help.begin(), help.end(), [](pair<string, int> &a, pair<string , int> &b){
                if(a.second == b.second) return a.first < b.first;
                return a.second < b.second;
        });

        vector<string> ans;
        for(auto a : help){
            ans.push_back(a.first);
        }
        return ans;
    }
};