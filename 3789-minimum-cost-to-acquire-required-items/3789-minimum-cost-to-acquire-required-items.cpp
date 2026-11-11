class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = min(cost1, costBoth);
        long long c2 = min(cost2, costBoth);
        long long cb = min((long long)costBoth, c1 + c2);

        long long n1 = need1;
        long long n2 = need2;

        long long common = min(n1, n2);
        long long totalCost = common * cb;

        if (n1 > n2) {
            totalCost += (n1 - n2) * c1;
        } else {
            totalCost += (n2 - n1) * c2;
        }

        return totalCost;
    }
};