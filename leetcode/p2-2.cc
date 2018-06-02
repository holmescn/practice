class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> reverseIndex;

        for (int i = 0; i < nums.size(); i ++) {
            auto found = reverseIndex.find(target - nums[i]);
            if (found != reverseIndex.end()) {
                return vector<int>({i, index->second});
            }

            reverseIndex[nums[i]] = i;
        }

        return vector<int>();
    }
};
