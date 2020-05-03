# 关于超时的记录

## 剑指offer

#### 1. 多余且频繁的内存分配和释放导致算法时间增加 && 函数传参导致

### 面试题12. 矩阵中的路径
https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/submissions/

这个题比较简单，是一个dfs遍历的题，找出矩阵中的指定路径。但是我的解法一直超时，通过的同学也是dfs解法。

```
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = m == 0 ? 0 : board[0].size(), len = word.length();
        if (m == 0 || n == 0 || len == 0) return false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> records(m, vector<bool>(n, false));
                if (back_trace(i, j, board, word, m, n, records))
                    return true;
            }
        }
        return false;
    }
    bool back_trace(int i, int j, vector<vector<char>>& board, string word, int m, int n, vector<vector<bool>>& records) {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (word[0] != board[i][j] || records[i][j]) return false;
        if (word.length() == 1 && word[0] == board[i][j]) return true;
        records[i][j] = true;
        // up
        if (back_trace(i - 1, j, board, std::string(word.begin() + 1, word.end()), m, n, records)) return true;
        // down
        if (back_trace(i + 1, j, board, std::string(word.begin() + 1, word.end()), m, n, records)) return true;
        // left
        if (back_trace(i, j - 1, board, std::string(word.begin() + 1, word.end()), m, n, records)) return true;
        // right
        if (back_trace(i, j + 1, board, std::string(word.begin() + 1, word.end()), m, n, records)) return true;
        records[i][j] = false;
        return false;
    }
};
```
第二层for循环中新建 records 数组，每次循环都新建和析构，占用了运行时间。

有的同学则是参数传递的时候没有使用引用，大量拷贝构造和析构的时间被浪费。

