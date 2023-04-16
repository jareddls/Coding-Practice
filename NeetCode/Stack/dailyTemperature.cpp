class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temps;
        vector<int> answer(temperatures.size(), 0);
        
        for (size_t idx = 0; idx < temperatures.size(); ++idx) {
            // while the temps stack isn't empty and the temperature at the index
            // of the top of temps is less than the temperature at the current index
            // we subtract the index with the current top of the temps
            while (!temps.empty() and temperatures[temps.top()] < temperatures[idx]) {
                answer[temps.top()] = idx - temps.top();
                temps.pop();
            } 

            temps.push(idx);
        }
        return answer;
    }
};