class Solution {
    using Matrix = array<array<int, 26>, 26>;
    int MOD = 1e9 + 7;

    inline Matrix multiplyMatrices(Matrix& A, Matrix& B) {
        Matrix result{};
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    result[i][j] = (result[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
                }
            }
        }
        return result;
    }

    inline Matrix raiseMatrixToPower(Matrix& baseMatrix, int exponent) {
        Matrix identityMatrix{};
        for (int i = 0; i < 26; ++i)
            identityMatrix[i][i] = 1;

        while (exponent) {
            if (exponent & 1)
                identityMatrix = multiplyMatrices(baseMatrix, identityMatrix);

            baseMatrix = multiplyMatrices(baseMatrix, baseMatrix);
            exponent /= 2;
        }
        return identityMatrix;
    }

public:
    int lengthAfterTransformations(string inputString, int numTransformations, vector<int>& shiftValues) {
        array<int, 26> initialFrequencies{};
        for (char c : inputString)
            initialFrequencies[c - 'a']++;

        Matrix transformationMatrix{};
        for (int ch = 0; ch < 26; ++ch) {
            for (int offset = ch + 1; offset <= ch + shiftValues[ch]; ++offset)
                transformationMatrix[offset % 26][ch]++;
        }

        Matrix finalTransformationMatrix = raiseMatrixToPower(transformationMatrix, numTransformations);

        array<int, 26> transformedFrequencies{};
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j)
                transformedFrequencies[i] = (transformedFrequencies[i] + (1LL * finalTransformationMatrix[i][j] * initialFrequencies[j]) % MOD) % MOD;
        }

        int finalStringLength = 0;
        for (int i = 0; i < 26; ++i)
            finalStringLength = (finalStringLength + transformedFrequencies[i]) % MOD;

        return finalStringLength;
    }
};



/*


class Solution {
    using Matrix = array<array<int, 26>, 26>;
    int MOD = 1e9 + 7;

    inline Matrix multiplyMatrices(Matrix& A, Matrix& B) {
        Matrix result{};
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    result[i][j] = (result[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
                }
            }
        }
        return result;
    }

    inline Matrix raiseMatrixToPower(Matrix& baseMatrix, int exponent) {
        Matrix identityMatrix{};
        for (int i = 0; i < 26; ++i)
            identityMatrix[i][i] = 1;

        while (exponent) {
            if (exponent & 1)
                identityMatrix = multiplyMatrices(baseMatrix, identityMatrix);

            baseMatrix = multiplyMatrices(baseMatrix, baseMatrix);
            exponent /= 2;
        }
        return identityMatrix;
    }

public:
    int lengthAfterTransformations(string inputString, int numTransformations, vector<int>& shiftValues) {
        array<int, 26> initialFrequencies{};
        for (char c : inputString)
            initialFrequencies[c - 'a']++;

        Matrix transformationMatrix{};
        for (int ch = 0; ch < 26; ++ch) {
            for (int offset = ch + 1; offset <= ch + shiftValues[ch]; ++offset)
                transformationMatrix[offset % 26][ch]++;
        }

        Matrix finalTransformationMatrix = raiseMatrixToPower(transformationMatrix, numTransformations);

        array<int, 26> transformedFrequencies{};
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j)
                transformedFrequencies[i] = (transformedFrequencies[i] + (1LL * finalTransformationMatrix[i][j] * initialFrequencies[j]) % MOD) % MOD;
        }

        int finalStringLength = 0;
        for (int i = 0; i < 26; ++i)
            finalStringLength = (finalStringLength + transformedFrequencies[i]) % MOD;

        return finalStringLength;
    }
};


*/