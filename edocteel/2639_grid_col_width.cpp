#include "2639_grid_col_width.h"
using namespace std;

vector<int> GridColWidth2639::findColumnWidth(const vector<vector<int>>& grid) {
    vector<int> colWidths;
    if (grid.empty()) return colWidths;

    int rows = grid.size();
    int cols = grid[0].size();
    colWidths.assign(cols, 0);
    for (int c = 0; c < cols; ++c)
        for (int r = 0; r < rows; ++r)
            colWidths[c] = max(colWidths[c], findWidth(grid[r][c]));
    return colWidths;
}

int GridColWidth2639::findWidth(int num) {
    if (num == 0) return 1;

    int width = 0;
    if (num < 0) ++width, num *= -1;

    while(num) ++width, num /= 10;
    return width;
}