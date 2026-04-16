class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> total(3, 0);
        for (char c : s) total[c - 'a']++;
        
        // If impossible
        if (total[0] < k || total[1] < k || total[2] < k) return -1;
        
        vector<int> window(3, 0);
        int left = 0, maxWindow = 0;
        
        for (int right = 0; right < n; right++) {
            window[s[right] - 'a']++;
            
            
            while (total[0] - window[0] < k ||
                   total[1] - window[1] < k ||
                   total[2] - window[2] < k) {
                window[s[left] - 'a']--;
                left++;
            }
            
            maxWindow = max(maxWindow, right - left + 1);
        }
        
        return n - maxWindow;
    }
};
