class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (head && top <= bottom && left <= right) {
            // left -> right along the top row
            for (int j = left; j <= right && head; j++) {
                res[top][j] = head->val;
                head = head->next;
            }
            top++;

            // top -> bottom along the right column
            for (int i = top; i <= bottom && head; i++) {
                res[i][right] = head->val;
                head = head->next;
            }
            right--;

            // right -> left along the bottom row
            if (top <= bottom) {
                for (int j = right; j >= left && head; j--) {
                    res[bottom][j] = head->val;
                    head = head->next;
                }
                bottom--;
            }

            // bottom -> top along the left column
            if (left <= right) {
                for (int i = bottom; i >= top && head; i--) {
                    res[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
        }
        return res;
    }
};