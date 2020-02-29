#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        if (rows == 0) return count;
        int cols = grid[0].size();
        
        //记录是否被访问过
        vector<vector<bool> > visited(rows, vector<bool>(cols, false));
        //访问队列
        queue<int> q;
        //队列前端坐标
        int x = 0;
        int y = 0;
        //相邻坐标
        int xx = 0;
        int yy = 0;
        //坐标增量
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++){
                //若当前坐标访问过或当前坐标值为0，则进入下一个坐标
                if (grid[i][j] == '0' || visited[i][j]) continue;
                //若当前坐标未访问过，且其值为1，那么就发现新岛屿
                count = count + 1;
                //将当前坐标送入队列
                q.push(i);
                q.push(j);
                //访问该坐标
                visited[i][j] = true;
                while (!q.empty()){
                    //取出队列前的坐标
                    x = q.front();
                    q.pop();
                    y = q.front();
                    q.pop();
                    
                    //将周围岛屿送入队列
                    for (int k = 0; k < 4; k++) {
                        xx = x + dx[k];
                        yy = y + dy[k];
                        //坐标越界
                        if (xx < 0 || xx >= rows || yy < 0 || yy >= cols) continue;
                        //若周围坐标也为1，说明是同一岛屿
                        if (grid[xx][yy] == '1' && !visited[xx][yy]) {
                            q.push(xx);
                            q.push(yy);
                            visited[xx][yy] = true;
                        }
                    }
                }
            }
        }
        return count;
    }
};

void test(vector<vector<char> > grid) {
    int rows = grid.size(), cols = rows > 0 ? grid[0].size() : 0;
    if (rows == 0 || cols == 0)
        cout << "Empty datas." << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << grid[i][j];
        cout << endl;
    }
    Solution s;
    int count = s.numIslands(grid);
    if (count <= 1)
        cout << "There is " << count << " island." << endl;
    else
        cout << "There are " << count << " islands." << endl;
}
int main() {
    vector<vector<char> > grid;
    vector<char> tmp;
    tmp.push_back('1'); tmp.push_back('1'); tmp.push_back('1'); tmp.push_back('1'); tmp.push_back('0');
    grid.push_back(tmp);
    tmp.clear();
    tmp.push_back('1'); tmp.push_back('1'); tmp.push_back('0'); tmp.push_back('1'); tmp.push_back('0');
    grid.push_back(tmp);
    tmp.clear();
    tmp.push_back('1'); tmp.push_back('1'); tmp.push_back('0'); tmp.push_back('0'); tmp.push_back('0');
    grid.push_back(tmp);
    tmp.clear();
    tmp.push_back('0'); tmp.push_back('0'); tmp.push_back('0'); tmp.push_back('0'); tmp.push_back('0');
    grid.push_back(tmp);
    test(grid);

    grid.clear();
    tmp.clear();
    tmp.push_back('1'); tmp.push_back('1'); tmp.push_back('0'); tmp.push_back('0'); tmp.push_back('0');
    grid.push_back(tmp);
    tmp.clear();
    tmp.push_back('1'); tmp.push_back('1'); tmp.push_back('0'); tmp.push_back('0'); tmp.push_back('0');
    grid.push_back(tmp);
    tmp.clear();
    tmp.push_back('0'); tmp.push_back('0'); tmp.push_back('1'); tmp.push_back('0'); tmp.push_back('0');
    grid.push_back(tmp);
    tmp.clear();
    tmp.push_back('0'); tmp.push_back('0'); tmp.push_back('0'); tmp.push_back('1'); tmp.push_back('1');
    grid.push_back(tmp);
    test(grid);

    cout << "press enter to continue" << endl;
    cin.get();

    return 0;
}