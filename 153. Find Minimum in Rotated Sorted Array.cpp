class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid=0,res=INT_MAX;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[l]<=nums[mid]){
                res=min(res,nums[l]);
                l=mid+1;
            }
            else{
                res=min(res,nums[mid]);
                r=mid-1;
            }
        }
        return res;
    }
};