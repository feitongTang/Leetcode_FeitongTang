/*
    link: https://leetcode.com/problems/two-sum/
*/

/*
    comment:
    a simple solution is to use O(n^2) brute force
    I use hsh table to record the val and the idx
    then sort the vector and use two pointers methods
    when there are duplicate numbers:
    1. duplicate numbers add to target
    then they must be the answer since there's exactly one answer
    2. duplicate numbers don't add to target
    don't care since they won't appear in the final answer
    again this is guaranteed by exactly one answer

    however, i think there are still some problems:
    1. although the time complexity is lower that O(n^2), it uses more space
    2. the method that deals with duplicate numbers is problem-specific and cannot be used in other general problems
*/

/*
    status:
    Runtime: 41.49%
    Memory Usage: 11.81%
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        unordered_map<int, int> val_idx;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (val_idx.find(nums[i]) == val_idx.end()) {
                val_idx[nums[i]] = i;
            }
            else {
                if (nums[i] * 2 == target) {
                    result.push_back(val_idx[nums[i]]);
                result.push_back(i);
                return result;
                }
            }
        }
        
        sort(nums.begin(), nums.end());
        
        int low = 0, high = nums.size() - 1;
        
        while (low <= high) {
            if (nums[low] + nums[high] > target) {
                high--;
            } else if (nums[low] + nums[high] < target) {
                low++;
            } else {
                break;
            }
        }
        
        result.push_back(val_idx[nums[low]]);
        result.push_back(val_idx[nums[high]]);
        
        return result;
    }
    
    /*
        another solution from online by wfxr (https://leetcode.com/problems/two-sum/discuss/13/Accepted-C%2B%2B-O(n)-Solution)
        hash table is fast in find
        no need to use two pointers at all!
    */

    vector<int> twoSum_online(vector<int>& nums, int target) {
        unordered_map<int, int> imap;
        
        for (int i = 0;; ++i) {
            auto it = imap.find(target - nums[i]);
            
            if (it != imap.end()) 
                return vector<int> {i, it->second};
                
            imap[nums[i]] = i;
        }
    }
};