class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = equations.size();
        map<string, map<string, double>> mp;

        for (int i = 0; i < n; ++i) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];

            
                mp[dividend][divisor] = values[i];
            
            
                mp[divisor][dividend] = 1.0 / values[i];
            
        }

        int qsize = queries.size();
        vector<double> res(qsize);
        for (int i = 0; i < qsize; ++i) {
            string dividend = queries[i][0];
            string divisor = queries[i][1];
            if (!mp.contains(dividend) || !mp.contains(divisor)) {
                res[i] = -1.0;
            } else if (dividend == divisor) {
                res[i] = 1.0;
            } else {
                set<string> visited;
                res[i] = dfs(dividend, divisor, 1, visited, mp);
            }
        }

        return res;
    }

    double dfs(string src, string des, double prod, set<string> &visited,  map<string, map<string, double>> &mp){
            double ret = -1;
            visited.insert(src);
            
            if(mp[src].contains(des)){
                ret = mp[src][des] * prod;
            }
            else{
                for(auto &p : mp[src]){
                    string neighbour = p.first;
                    if(!visited.contains(neighbour)){
                        ret = dfs(neighbour, des, prod * mp[src][neighbour], visited,mp);
                        if(ret != -1.0){
                            break;
                        }
                    }
                }
            }
            // visited.erase(des);
            return ret;
    }
};