class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int operations = 0;

        while (target != startValue && target > startValue) {

            if (target % 2 == 0) {
                target = target / 2;
                operations++;
            }
            else {
                target += 1;
                operations++;
            }
        }

        while (target < startValue) {
            target += 1;
            operations++;
        }

        return operations;
    }
};