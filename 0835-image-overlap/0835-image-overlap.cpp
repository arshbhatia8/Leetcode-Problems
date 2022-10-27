class Solution {
public:
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    const int n = img1.size();
    unordered_map<int, int> m;
    for (int y1 = 0; y1 < n; ++y1)
      for (int x1 = 0; x1 < n; ++x1)
        if (img1[y1][x1])
          for (int y2 = 0; y2 < n; ++y2) 
            for (int x2 = 0; x2 < n; ++x2)
              if (img2[y2][x2])                 
                ++m[(x1 - x2) * 100 + (y1 - y2)];
    int ans = 0;
    for (const auto [key, count] : m)
      ans = max(ans, count);
    return ans;
  }
};