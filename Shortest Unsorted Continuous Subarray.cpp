class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==0) return 0;
        int left = -1, right = -1, symbol = -1;
        int min = INT_MAX, max = INT_MIN;
        for(int i=1; i<nums.size(); i++){
            if (nums[i] < nums[i-1]){
                if(nums[i] <= min) {min = nums[i];}
                if(nums[i-1] >= max) {max = nums[i-1]; symbol = i - 1;}
            }
        }
        if(max < min) return 0;
        for(int i=0; i<nums.size(); i++){
            if (nums[i] > min && left == -1) {
                left = i;
            }
            if (nums[i] >= max && i > symbol && right == -1) right = i-1;
        }
        if(left != -1 && right == -1) right = nums.size() - 1;
        return right > left ? right - left + 1:0;
    }
};
