class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        int aMax = min(n, limit);
        for (int a = 0; a <= aMax; ++a) {
            int bMax = min(n - a, limit);
            int bMin = max(0, n - a - limit);
            if (bMax >= bMin) {
                res += (long long)(bMax - bMin + 1);
            }
        }
        return res;
    }
};