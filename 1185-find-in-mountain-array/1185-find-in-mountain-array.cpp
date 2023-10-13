/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int top(MountainArray &mountainArr,int &n){
        int s =0, e= n-1,m=s+(e-s)/2;
        while(s<=e){
            if(!m)return 1;
            else if(m==n-1)return m-1;
            int temp = mountainArr.get(m);
            if((m==n-1||temp>mountainArr.get(m+1)) && (!m ||temp >mountainArr.get(m-1))){
                return m;
            }
            else if(temp>mountainArr.get(m-1)){
                s = m+1;
            }
            else{
                e = m-1;
            }
            m = s+(e-s)/2;
        }
        return -1;
    }
    int binarySearch(int s,int e,int target, MountainArray &mountainArr){
        int m = s+(e-s)/2;
        while(s<=e){
            int temp = mountainArr.get(m);
            if(temp==target){
                return m;
            }
            else if(temp>target) e = m-1;
            else s = m+1;
            m = s+(e-s)/2;
        }
        return -1;
    }
    int left(int s,int e,int target,MountainArray &mountainArr){
        int m = s+(e-s)/2;
        while(s<=e){
            int temp = mountainArr.get(m);
            if(temp==target){
                return m;
            }
            else if(temp>target) s = m+1;
            else e = m-1;
            m = s+(e-s)/2;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        // cout<<n;
        int t = top(mountainArr,n);
        // cout<<t<<" ";
        int ans = binarySearch(0,t,target,mountainArr);
        if(ans!=-1)return ans;
        else ans = left(t,n-1,target,mountainArr);
        return ans;
    }
};