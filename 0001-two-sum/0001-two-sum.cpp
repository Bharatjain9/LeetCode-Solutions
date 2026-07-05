class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Nested For Loop
        // vector<int> ans;
        // for(int i = 0; i < nums.size()-1; i++){
        //     for(int j = i+1; j < nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //             break;
        //         }
        //     }
        // }
        //  return ans;

        //MAP
        // unordered_map<int, int> mpp;
        // vector<int> ans;

        // for (int i = 0; i < nums.size(); i++) {
        //     mpp[nums[i]] = i;
        // }
        // for (int i = 0; i < nums.size(); i++) {
        //     int diff = target - nums[i];

        //     if (mpp.find(diff) != mpp.end() && mpp[diff] != i) {
        //             return {mpp[diff],i};
        //     }
        // }

        // return ans;

        vector<pair<int,int>>ans;
    
        for(int i = 0; i < nums.size(); i++){
            ans.push_back({nums[i],i});
        }
        sort(ans.begin(),ans.end());

        int l = 0, r = nums.size()-1;

        while(l<=r){
            if(ans[l].first + ans[r].first == target){
                return {ans[l].second,ans[r].second};
            }
            else if(ans[l].first+ans[r].first<target) l++;

            else r--;
        }

        return {};

    }
};