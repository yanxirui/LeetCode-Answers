class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> num;
        num.push_back(1);
        for(int i=1; i<nums.size(); i++){
            num.push_back(num[i-1]*nums[i-1]);
        }
        int p = 1;
        for(int i=nums.size()-2; i>=0; i--){
            p *= nums[i+1];
            num[i] *= p;
        }
        return num;
    }
};
