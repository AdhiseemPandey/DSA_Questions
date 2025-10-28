using db = double;
using ll = long long;
using I = int;

class Solution {
public:
    const I MOD = 1e9 + 7;

    // Binary exponentiation: (base^exp) % MOD
    ll binExp(ll base, ll exp) {
        ll result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    I countGoodNumbers(ll n) {
        ll evenCount = n / 2;
        ll oddCount = n - evenCount;
        ll result = (binExp(5, oddCount) * binExp(4, evenCount)) % MOD;
        return static_cast<I>(result);
    }
};