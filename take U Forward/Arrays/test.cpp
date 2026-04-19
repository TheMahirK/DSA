class Solution
{
public:
    void rotate90(vector<vector<int>> &matrix)
    {
        vector<vector<int>> result;
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> col;
            for (int j = 0; j < n; j++)
            {
                col.push_back(matrix[j][i]);
            }
            reverse(col.begin(), col.end());
            result.push_back(col);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = result[i][j];
            }
        }
    }
    void rotateMatrix(vector<vector<int>> &matrix)
    {
        rotate90(matrix);
        rotate90(matrix);
        rotate90(matrix);
    }
};
