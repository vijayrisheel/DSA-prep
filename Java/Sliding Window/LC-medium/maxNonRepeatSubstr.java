// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Given a string, find the length of the longest substring, which has no repeating characters.

public int longestNonRepeatingSubstr(String s) {
    int n = s.length();
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    int windowStart = 0;
    int windowEnd = 0;
    int res = 0;
    Map<Character, Integer> umap = new HashMap<>();

    while(windowEnd < n) {
        if(!umap.containsKey(s.charAt(windowEnd))) {
            umap.put(s.charAt(windowEnd), windowEnd);
        }
        else {
            windowStart = Math.max(windowStart, umap.get(s.charAt(windowEnd))+1);
            umap.put(s.charAt(windowEnd), windowEnd);
        }
        res = Math.max(res, windowEnd-windowStart+1);
        windowEnd++;
    }
    return res;
}


public static void main(String[] args) {
    String s = "abcabcbb";
    System.out.println(longestNonRepeatingSubstr(s));
}