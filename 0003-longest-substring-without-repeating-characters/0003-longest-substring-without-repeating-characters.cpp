class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int ans = 0;

        unordered_map<char, int> mp;

        for (int r = 0; r < s.size(); r++) {
            if (mp.find(s[r]) != mp.end()) {
                l = max(l, mp[s[r]] + 1);
            }

            mp[s[r]] = r;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};