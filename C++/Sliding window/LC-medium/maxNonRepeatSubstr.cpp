// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Given a string, find the length of the longest substring, which has no repeating characters.

#include <bits/stdc++.h>

using namespace std;

int longestNonRepeatingSubstr(string s) {
    int n = s.size();
    if(n == 0) return 0;
    if(n == 1) return 1;
        
    int windowStart = 0;
    int windowEnd = 0;
    int res = 0;
    unordered_map<char, int> umap;

    while(windowEnd < n) {
        if(umap.count(s[windowEnd]) == 0) {
            umap[s[windowEnd]] = windowEnd;
        }
        else {
            windowStart = max(windowStart, umap[s[windowEnd]]+1);
            umap[s[windowEnd]] = windowEnd;
        }
        res = max(res, windowEnd-windowStart+1);
        windowEnd++;
    }
    
    return res;
}

int main() {
    string s = "abcabcbb";
    cout << longestNonRepeatingSubstr(s) << endl;

    return 0;
}