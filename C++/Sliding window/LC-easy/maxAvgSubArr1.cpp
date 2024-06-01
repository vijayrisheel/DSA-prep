// https://leetcode.com/problems/maximum-average-subarray-i/
// Given an array, find the average of all contiguous subarrays of size ‘K’ in it.

#include <bits/stdc++.h>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    int windowStart = 0;
    int windowSum = 0;
    int windowEnd = 0;
    int maxSum = -1e9;

    while(windowEnd < n) {
        while(windowEnd-windowStart < k) {
            windowSum += nums[windowEnd];
            windowEnd++;
        }
        if(maxSum < windowSum) maxSum = windowSum;
        windowSum -= nums[windowStart];
        windowStart++;
    }
    return ((double)maxSum)/((double)k);
}

int main() {
    vector<int> v{1,12,-5,-6,50,3};
    int k = 4;
    //Expected output: 2.75000

    // vector<int> v{5};
    // int k = 1;
    //Expected output: 5.00000

    cout << findMaxAverage(v, k) << endl;
    
    return 0;
}