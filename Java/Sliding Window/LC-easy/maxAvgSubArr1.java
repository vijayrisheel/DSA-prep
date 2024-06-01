// https://leetcode.com/problems/maximum-average-subarray-i/
// Given an array, find the average of all contiguous subarrays of size ‘K’ in it.

public double findMaxAverage(int[] nums, int k) {
    int n = nums.length;
    int windowStart = 0;
    int windowSum = 0;
    int windowEnd = 0;
    int maxSum = Integer.MIN_VALUE;

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

public static void main(String args[]) {
    int v[] = {1,12,-5,-6,50,3};
    int k = 4;
    //Expected output: 2.75000

    // int v[] = {5};
    // int k = 1;
    //Expected output: 5.00000

    System.out.println(findMaxAverage(v, k));
    
    return 0;
}