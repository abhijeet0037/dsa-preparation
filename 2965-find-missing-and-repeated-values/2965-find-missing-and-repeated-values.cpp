class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        unordered_set<int>s;
        int n = grid.size();
        int expected = 0, actual = 0;
        int a,b;

        for(int i=0 ; i<n ; i++){
            for( int j=0; j<n; j++){
                actual += grid[i][j];
                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j] ;
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        expected = (n*n)*(n*n + 1)/2;

        b = expected + a - actual;
        ans.push_back(b);
        return ans;
    }
};