class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        long long l=0,r=0,n=nums.size();
        long long sum = 0,mini = INT_MAX;

        while(r < n){
            sum+=nums[r];
            if(sum >= k){
                while(sum >= k){
                    sum-=nums[l];
                    l++;
                }
                mini = min(mini,r- l+1);
            }
            r++;
        }
        if(mini== INT_MAX)return 0;
        return mini + 1;
    }
};