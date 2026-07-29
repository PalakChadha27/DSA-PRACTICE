#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::unordered_map<char, int> targetCounts;
        for (char c : t) {
            targetCounts[c]++;
        }

        std::unordered_map<char, int> windowCounts;
        int left = 0;
        int right = 0;
        
        int formed = 0; 
        int required = targetCounts.size();

        int minLen = INT_MAX;
        int minStart = 0;

        while (right < s.length()) {
            char c = s[right];
            windowCounts[c]++;

            if (targetCounts.count(c) && windowCounts[c] == targetCounts[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                c = s[left];

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                windowCounts[c]--;
                if (targetCounts.count(c) && windowCounts[c] < targetCounts[c]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
