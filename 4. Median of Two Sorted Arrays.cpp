class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums3;
        for(int i=0;i<nums1.size();i++){
            nums3.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            nums3.push_back(nums2[i]);
        }
        sort(nums3.begin(), nums3.end());
        if(nums3.size()%2!=0){
           float res= nums3.size()/2;
           return(nums3[res]);
        }
        else{
            int indx=nums3.size()/2;
            float res1=nums3[indx], res2=nums3[indx-1];
            float res=(res1+res2)/2.000;
            return(res);
        }
        
    }
};