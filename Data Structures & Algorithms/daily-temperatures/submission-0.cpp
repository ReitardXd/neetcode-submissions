#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        // 1. Initialize result array with the correct size (temperatures.size())
        std::vector<int> results(temperatures.size(), 0); 
        
        // 2. Initialize the stack to store indices
        std::stack<int> stack;

        // 3. Iterate through the temperatures array
        for (int i = 0; i < temperatures.size(); ++i) {
            
            // The Pop/Update Phase: Check if the current day 'i' is warmer 
            // than the day at the index on the top of the stack.
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
                
                // Get the index of the day that just found its warmer day
                int previous_day_index = stack.top();
                stack.pop();

                // Calculate the difference (the number of days waited)
                results[previous_day_index] = i - previous_day_index;
            } 
            
            // The Push Phase: Push the current day's index onto the stack
            // It is now waiting for its own warmer day.
            stack.push(i);
        }
        
        // Days left in the stack automatically have a result of 0 (from initialization)
        return results;
    }
};