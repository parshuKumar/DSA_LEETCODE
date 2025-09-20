class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();
        string ver1 = "", ver2 = "";
        vector<int> v1, v2;
        
        for(int i = 0; i < version1.size(); ++i){
           if(version1[i] == '.'){
                v1.push_back(stoi(ver1));
                ver1 = "";
                continue;
           }
           ver1 += version1[i];
           if(i == n-1){
            v1.push_back(stoi(ver1));
           }
        }
        for(int i = 0; i < version2.size(); ++i){
           if(version2[i] == '.'){
                v2.push_back(stoi(ver2));
                ver2 = "";
                continue;
           }
           ver2 += version2[i];
           if(i == m-1){
            v2.push_back(stoi(ver2));
           }
        }
        while(v1.size() > v2.size()){
            v2.push_back(0);
        }
        while(v2.size() > v1.size()){
            v1.push_back(0);
        }
        int i = 0, j = 0;
        while(i < v1.size() && j < v2.size()){
            // cout << v1[i] << " " <<v2[j] <<endl;
            if (v1[i] > v2[j]) return 1;
            else if(v1[i] < v2[j]) return -1;
            i++; j++;
        }
        return 0;
    }
};