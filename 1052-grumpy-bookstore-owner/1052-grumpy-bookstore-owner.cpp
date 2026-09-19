class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int n = customers.size();

        // Customers already satisfied
        int total = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                total += customers[i];
            }
        }

        // Extra satisfied customers in the first window
        int window = 0;

        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                window += customers[i];
            }
        }

        int maxWindow = window;

        // Slide the window
        for (int i = minutes; i < n; i++) {

            // Add the new customer entering the window
            if (grumpy[i] == 1) {
                window += customers[i];
            }

            // Remove the customer leaving the window
            if (grumpy[i - minutes] == 1) {
                window -= customers[i - minutes];
            }

            maxWindow = max(maxWindow, window);
        }

        // Already satisfied + maximum additional satisfaction
        return total + maxWindow;
    }
};