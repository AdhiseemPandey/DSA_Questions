// Just read teh editorial and find some video 
// 
// NOT SOLVED 


class Solution {
private:
    static constexpr long long MODULO = 1'000'000'007;
    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int rows = A.size();
        int cols = B[0].size();
        Matrix result(rows, vector<long long>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < A[0].size(); k++) {
                long long val = A[i][k];
                if (val == 0) continue;
                for (int j = 0; j < cols; j++) {
                    result[i][j] = (result[i][j] + val * B[k][j]) % MODULO;
                }
            }
        }
        return result;
    }

    Matrix matrixPower(Matrix base, long long exponent, Matrix result) {
        while (exponent > 0) {
            if (exponent & 1) {
                result = multiply(result, base);
            }
            base = multiply(base, base);
            exponent >>= 1;
        }
        return result;
    }

public:
    int zigZagArrays(int length, int left, int right) {
        int rangeSize = right - left + 1;
        if (length == 1) {
            return rangeSize;
        }

        int matrixSize = 2 * rangeSize;
        Matrix transition(matrixSize, vector<long long>(matrixSize, 0));

        for (int i = 0; i < rangeSize; i++) {
            for (int j = 0; j < i; j++) {
                transition[i][j + rangeSize] = 1;
            }
            for (int j = i + 1; j < rangeSize; j++) {
                transition[i + rangeSize][j] = 1;
            }
        }

        Matrix dp(1, vector<long long>(matrixSize, 1));

        dp = matrixPower(std::move(transition), length - 1, std::move(dp));

        long long answer = 0;
        for (int i = 0; i < matrixSize; i++) {
            answer = (answer + dp[0][i]) % MODULO;
        }

        return answer;
    }
};
