class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;

        vector<int> volumes;

        //had to push_back here instead of doing a manual finding of
        //volume; otherwise time limit would exceed
        while (left < right) {
            if (height[left] < height[right]) {
                //be careful about the logic
                //you calculated (right + 1) and (left + 1) last time
                //that's wrong because you don't account
                //for the distance between the height of the left value
                //and the right value, so you'd always be calculating
                //the max distance with the height of whatever you're looking at
                volumes.push_back(height[left] * (right - left));
                left++;
            }
            else {
                volumes.push_back((right - left) * height[right]);
                right--;
            }
        }

        return *max_element(volumes.begin(), volumes.end());
    }
};