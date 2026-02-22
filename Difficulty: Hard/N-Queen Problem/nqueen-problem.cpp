class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> temp(n);  // temp[row] = col+1
        vector<bool> col(n, false);
        vector<bool> diag1(2*n, false);
        vector<bool> diag2(2*n, false);

        backtrack(0, n, temp, ans, col, diag1, diag2);
        return ans;
    }

    void backtrack(int row, int n,
                   vector<int>& temp,
                   vector<vector<int>>& ans,
                   vector<bool>& col,
                   vector<bool>& diag1,
                   vector<bool>& diag2) {

        if(row == n){
            ans.push_back(temp);
            return;
        }

        for(int c = 0; c < n; c++){

            // diagonal indices
            int d1 = row - c + n;   // shifted to avoid negative
            int d2 = row + c;

            if(col[c] || diag1[d1] || diag2[d2])
                continue;

            // place queen
            col[c] = diag1[d1] = diag2[d2] = true;
            temp[row] = c + 1;   // 1-based indexing for GFG

            backtrack(row + 1, n, temp, ans, col, diag1, diag2);

            // backtrack
            col[c] = diag1[d1] = diag2[d2] = false;
        }
    }
};