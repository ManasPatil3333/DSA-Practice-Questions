class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() <= 1) {
            return s.length();
        }
        int ans = 0;
        int len = s.length();
        Set<Character> set = new HashSet<>();
        int left = 0;
        int right = 0;
        while (right < len) {
            while (right < len && !set.contains(s.charAt(right))) {
                set.add(s.charAt(right));
                right++;
            }

            ans = Math.max(ans, right - left);
            set.remove(s.charAt(left));
            left++;
        }

        return ans;
    }
}