class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int one = 1;
        int i = 0;
        reverse(digits.begin(), digits.end());

        while (one) {
            if (i < digits.size()) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                } else {
                    digits[i] += 1;
                    one = 0;
                }
            } else {
                digits.push_back(one);
                one = 0;
            }
            i++;
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
