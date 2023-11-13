class Solution {
public:
    bool isvowel(char v) {
    return (0x208222>>(v&0x1f))&1;
    }
    string sortVowels(string s) {
        string vowel;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i]))
            {
             vowel.push_back(s[i]);
             s[i]= '#';
            } 
        }
        sort(vowel.begin(),vowel.end());
        int j =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#')s[i]=vowel[j++];
        }
        return s;
    }
};