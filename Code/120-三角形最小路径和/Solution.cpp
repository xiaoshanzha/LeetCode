#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    动态规划：自底向上，求出最底到某位置的最小路径和
        triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
*/

int minimumTotal(vector<vector<int>>& triangle) {
	int n = triangle.size();
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < triangle[i].size(); j++) {
			triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
	}
	return triangle[0][0];
}

int main()
{
	vector<vector<int>> triangle = { {2},{3,4} ,{6,5,7} ,{4,1,8,3} };
	int min_road = minimumTotal(triangle);
	cout << min_road << endl;
	return 0;
}