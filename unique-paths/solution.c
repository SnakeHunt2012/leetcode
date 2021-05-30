#define MAX 100
int uniquePaths(int m, int n){
    int route[MAX][MAX];
    for (int i = 0; i < m; ++i) {
        route[i][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
        route[0][i] = 1;
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            route[i][j] = -1;
        }
    }
    return recursive(m, n, (int **)route);
}

int recursive(int m, int n, int route[MAX][MAX]) {
    if (m == 1) {
        return route[0][n - 1];
    } else if (n == 1) {
        return route[m - 1][0];
    } else if (route[m - 1][n - 1] > 0) {
        return route[m - 1][n - 1];
    } else {
        int res = recursive(m, n - 1, route) + recursive(m - 1, n, route);
        route[m - 1][n - 1] = res;
        return res;
    }
}
