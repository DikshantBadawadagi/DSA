class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};
