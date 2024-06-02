// https://leetcode.com/problems/minimum-size-subarray-sum/

// Given an array of positive numbers and a positive number ‘target,’ find the length of the smallest
// contiguous subarray whose sum is greater than or equal to ‘target’.
// Return 0 if no such subarray exists.

#include <bits/stdc++.h>

using namespace std;

double minSubArrayLen(vector<int>& nums, int target) {
    int n = nums.size();
    if(n == 1) {
        if(nums[0] >= target)   return 1;
        else                    return 0;
    }
        
    int windowStart = 0;
    int windowEnd = 0;
    int currSum = 0;
    int res = INT_MAX;

    while(windowEnd < n) {
        currSum += nums[windowEnd];
        while(currSum >= target) {
            res = min(res, windowEnd-windowStart+1);
            currSum -= nums[windowStart];
            windowStart++;
        }
            windowEnd++;
    }
    if(res == INT_MAX) return 0;
    return res;
}

int main() {
    vector<int> v{2,3,1,2,4,3};
    int target = 7;
    //Expected output: 2

    // vector<int> v{1,4,4};
    // int target = 4;
    //Expected output: 1

    // vector<int> v{1,1,1,1,1,1,1,1,1,1};
    // int target = 11;
    //Expected output: 0

    cout << minSubArrayLen(v, target) << endl;
    
    return 0;
}