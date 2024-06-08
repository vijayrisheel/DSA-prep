// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

// Given a string, find the length of the longest substring in it with no more than K distinct
// characters.
// You can assume that K is less than or equal to the length of the given string.

#include <bits/stdc++.h>

using namespace std;

int longestSubStringWithKdist(string s, int k) {
    int windowStart = 0;
    int windowEnd = 0;
    int n = s.size();
    unordered_map<char, int> charCount;\
    int res = 0;

    while(windowEnd < n) {
        charCount[s[windowEnd]]++;

        while(charCount.size() > k) {
            charCount[s[windowStart]]--;
            if(charCount[s[windowStart]] == 0) {
                charCount.erase(s[windowStart]);
            }
            windowStart++;
        }
        windowEnd++;

        res = max(res, windowEnd-windowStart+1);
    }

    return res;
}

int main() {
    string s = "araaci";
    int k = 2;
    cout << longestSubStringWithKdist(s, k) << endl;

    return 0;
}