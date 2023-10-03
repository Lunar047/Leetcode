class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> umap;
        umap.insert({'I',1});
        umap.insert({'V',5});
        umap.insert({'X',10});
        umap.insert({'L',50});
        umap.insert({'C',100});
        umap.insert({'D',500});
        umap.insert({'M',1000});
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(i<s.size()-1 && umap[s[i+1]]>umap[s[i]]){
                ans += (umap[s[i+1]] - umap[s[i]]);
                i++;
            }
            else ans += umap[s[i]];
        }
        return ans;
    }
};