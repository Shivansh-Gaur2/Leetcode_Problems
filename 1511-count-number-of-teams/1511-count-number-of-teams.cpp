class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;

        // Loop through each element in the rating array
        for (int j = 0; j < n; ++j) {
            int leftSmaller = 0, leftLarger = 0;
            int rightSmaller = 0, rightLarger = 0;

            // Count elements to the left of j
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    ++leftSmaller;
                } else if (rating[i] > rating[j]) {
                    ++leftLarger;
                }
            }

            // Count elements to the right of j
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) {
                    ++rightSmaller;
                } else if (rating[k] > rating[j]) {
                    ++rightLarger;
                }
            }

            // Calculate the number of valid teams with j as the middle element
            count += leftSmaller * rightLarger + leftLarger * rightSmaller;
        }

        return count;
    }
};
