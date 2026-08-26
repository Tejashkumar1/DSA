class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> secretMap(10, 0);
        vector<int> guessMap(10, 0);
        int bulls = 0, cows = 0;

        for (int i = 0; i < secret.size(); i++) {
            int x = secret[i] - '0';
            int y = guess[i] - '0';
            if (x == y) {
                bulls++;
            } else {
                secretMap[x]++;
                guessMap[y]++;
            }
        }

        for (int i = 0; i < 10; i++) {
            cows += min(secretMap[i], guessMap[i]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};