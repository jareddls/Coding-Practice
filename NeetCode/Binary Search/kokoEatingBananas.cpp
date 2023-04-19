class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int low = 1;
        int high = piles[piles.size()-1];
        int result = high;

        while (low <= high) {
            int k = (low + high) / 2;
            double hours = 0;

            for (int p = 0; p < piles.size(); ++p) {
                hours += ceil((double)piles[p] / k);
            }

            if (hours <= h) {
                result = min(result, k);
                high = k - 1;
               
            }
            else {
                low = k + 1;
            }
        }

        return result;

    }
};