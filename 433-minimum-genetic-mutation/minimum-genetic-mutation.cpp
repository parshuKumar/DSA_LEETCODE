class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
            unordered_set<string> bankSet(bank.begin(), bank.end());

            unordered_set<string> visited;

            queue<string> q;

            q.push(startGene);
            visited.insert(startGene);
            int level = 0;
            while(!q.empty()){
                int size = q.size();
                
                while(size--){
                    string cur = q.front();
                    q.pop();

                    if(cur == endGene) return level;

                    for(char c : "ACGT"){
                        for(int i = 0; i < cur.size(); ++i){
                            string neighbour = cur;
                            neighbour[i] = c;

                            if(visited.find(neighbour) == visited.end() && bankSet.find(neighbour) != bankSet.end()){
                                visited.insert(neighbour);
                                q.push(neighbour);
                            }
                        }
                    }
                }
                level++;
            }

            return -1;
    }
};