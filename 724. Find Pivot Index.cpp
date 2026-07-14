class Solution {
public:
int prefixsumapproach(vector<int>&nums){
    
    //create two array with same size as of nums array and with elements 0 
    vector<int>lsum(nums.size(), 0);
    vector<int>rsum(nums.size(), 0);

    //find left sum and put into an array
    for(int i=1; i<nums.size();i++){
        lsum[i]=lsum[i-1]+nums[i-1];
    }

    //find right sum and put into second array
    for(int i=nums.size()-2;i>=0;i--){
        rsum[i]=rsum[i+1]+nums[i+1];
    }

    //Check if leftsum array element is equal to rightsum array element then return the index else return -1
    for(int i=0;i<nums.size();i++){
        if(lsum[i]==rsum[i]) return i;
    }
    return -1;
}
    int pivotIndex(vector<int>& nums) {
       return prefixsumapproach(nums);
    }
};