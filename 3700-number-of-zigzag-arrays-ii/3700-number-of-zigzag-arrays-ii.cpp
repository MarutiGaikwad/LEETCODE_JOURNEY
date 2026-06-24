class Solution {
public:
    static const long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    vector<long long> mulMatVec(const Matrix& A,
                                const vector<long long>& v) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;
            for (int j = 0; j < n; j++) {
                cur = (cur + A[i][j] * v[j]) % MOD;
            }
            res[i] = cur;
        }
        return res;
    }

    Matrix mulMat(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!A[i][k]) continue;

                long long aik = A[i][k];
                for (int j = 0; j < n; j++) {
                    if (!B[k][j]) continue;
                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        // State: [U(1..m), D(1..m)]
        Matrix T(S, vector<long long>(S, 0));

        for (int y = 0; y < m; y++) {
            // U'[y] = sum D[x], x < y
            for (int x = 0; x < y; x++) {
                T[y][m + x] = 1;
            }

            // D'[y] = sum U[x], x > y
            for (int x = y + 1; x < m; x++) {
                T[m + y][x] = 1;
            }
        }

        vector<long long> state(S, 0);

        // Length 2 initialization
        for (int y = 0; y < m; y++) {
            state[y] = y;           // U[y] = y-1 (0-based => y)
            state[m + y] = m - 1 - y; // D[y]
        }

        long long p = n - 2;

        while (p > 0) {
            if (p & 1) state = mulMatVec(T, state);
            T = mulMat(T, T);
            p >>= 1;
        }

        long long ans = 0;
        for (long long x : state) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};