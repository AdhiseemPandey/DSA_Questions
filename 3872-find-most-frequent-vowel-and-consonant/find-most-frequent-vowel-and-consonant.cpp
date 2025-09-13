class Solution {
public:
    int maxFreqSum(string input) {
        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;

        int freqCount[26] = {0};

        for (char &currentChar : input) {
            freqCount[currentChar - 'a']++;

            if (string("aeiou").find(currentChar) != string::npos) {
                maxVowelFreq = max(maxVowelFreq, freqCount[currentChar - 'a']);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, freqCount[currentChar - 'a']);
            }
        }

        return maxConsonantFreq + maxVowelFreq;
    }
};

