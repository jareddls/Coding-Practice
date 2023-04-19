class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix[0].size()-1;

        int idx_to_look = 0;

        for (int idx = 0; idx < matrix.size(); ++idx) {
            if (target == matrix[idx][0]) {
                return true;
            }
            else if (matrix[idx][0] < target) {
                idx_to_look = idx;
                cout << "idx to look is: " << idx_to_look << endl;
            }
            else {
                break;
            }
        }

        while (low <= high) {
            int middle = (low + high) / 2;
            cout << "middle: " << middle << endl;
            cout << "high: " << high << endl;
            cout << "low: " << low << endl;

            if (matrix[idx_to_look][middle] == target) {
                return true;
            }
            else if (matrix[idx_to_look][middle] < target) {
                low = middle + 1;
            }
            else if (matrix[idx_to_look][middle] > target) {
                high = middle - 1;
            }
        }

        return false;
        
    }
};