
struct TrieNode {
    TrieNode* children[2]; // 0 and 1 branches
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    // Insert a number into the trie (bit by bit)
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) { // 32-bit integers
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    // Find max XOR for a given number
    int getMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            // Greedy: try to go opposite for maximizing XOR
            if (node->children[oppositeBit]) {
                maxXor |= (1 << i); // set this bit in result
                node = node->children[oppositeBit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
           Trie trie;
    for (int num : nums) trie.insert(num);

    int result = 0;
    for (int num : nums) {
        result = max(result, trie.getMaxXor(num));
    }
    return result;
 
    }
};