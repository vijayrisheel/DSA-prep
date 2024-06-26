// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

// Given a string, find the length of the longest substring in it with no more than K distinct
// characters.
// You can assume that K is less than or equal to the length of the given string.

public int longestSubStringWithKdist(String s, int k) {
    int windowStart = 0;
    int windowEnd = 0;
    int n = s.length();
    Map<Character, Integer> charCount = new HashMap<>();
    int res = 0;

    while(windowEnd < n) {
        char rightChar = s.charAt(windowEnd);
        charCount.put(rightChar, charCount.getOrDefault(rightChar, 0)+1);

        while(charCount.size() > k) {
            char leftChar = s.charAt(windowStart);
            charCount.put(leftChar, charCount.get(leftChar)-1);


            if(charCount.get(leftChar) == 0) {
                charCount.remove(leftChar);
            }
            windowStart++;
        }
        windowEnd++;

        res = Math.max(res, windowEnd-windowStart+1);
    }

    return res;
}


public static void main(String[] args) {
    String s = "araaci";
    int k = 2;
    System.out.println(longestSubStringWithKdist(s, k));
}