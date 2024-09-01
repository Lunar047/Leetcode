class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int a =  coordinate1[0] - 'a', b = coordinate1[1] - '1';
        int c = coordinate2[0] - 'a', d =  coordinate2[1]  - '1';
        // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        bool f1 = ((a&1 & b&1) || (!(a&1) & !(b&1)))?1:0;
        bool f2 = ((c&1 & d&1) || (!(c&1) & !(d&1)))?1:0;
        // cout<<f1<<" "<<f2;
        return f1==f2;
    }
};