class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> need(128, 0);

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int count = 0;

        int bestStart = 0;
        int bestLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            if (need[c] > 0) {
                count++;
            }

            need[c]--;

            while (count == t.size()) {
                int windowLen = right - left + 1;

                if (windowLen < bestLen) {
                    bestLen = windowLen;
                    bestStart = left;
                }

                char leftChar = s[left];
                need[leftChar]++;

                if (need[leftChar] > 0) {
                    count--;
                }

                left++;
            }
        }

        if (bestLen == INT_MAX) {
            return "";
        }

        return s.substr(bestStart, bestLen);
    }
};