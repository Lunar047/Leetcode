#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class Solution {
private:
    //for PBDS uncomment these lines
    typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        pbds A;
        for(int i= n-1;i>=0;i--){
            A.insert(nums[i]);
            ans[i] = A.order_of_key(nums[i]);;
        }
        return ans;
    }
};