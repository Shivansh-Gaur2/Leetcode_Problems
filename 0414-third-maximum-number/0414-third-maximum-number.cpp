class Solution {
public:
    int thirdMax(vector<int>& nums) {
          // Initialize three variables to store the top three unique maximum values
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;

        for (int num : nums) {
            // Skip duplicates
            if (num == first || num == second || num == third) continue;

            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        // If the third maximum value is still LONG_MIN, it means there are less than 3 unique numbers
        return third == LONG_MIN ? first : third;
    }
};