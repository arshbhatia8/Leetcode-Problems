class Solution {
public:
  string predictPartyVictory(string senate) {
    vector<int> data;
    for (int i = 0; i < senate.length(); ++i) {
      int j = i + 1;
      while (j < senate.length() && senate[j] == senate[i]) ++j;
      data.push_back(senate[i] == 'R' ? j - i : i - j);
      i = j - 1;
    }
      long long remains_ban{0LL};
      long long ban{0LL};
      while (data.size() > 1) {
        vector<int> second;
        for (int i = 0; i < data.size(); ++i) {
        if (remains_ban != 0) {
          if ((remains_ban > 0) ^ (data[i] > 0)) {
            if (remains_ban + data[i] == 0) {
              remains_ban = 0;
              continue;
            } else if (((remains_ban + data[i] > 0) ^ (remains_ban > 0))) {
              data[i] += remains_ban;
              remains_ban = 0;
            } else {
              remains_ban += data[i];
              continue;
            }
          }
        }
        if (ban == 0) {
          second.push_back(data[i]);
          ban += data[i];
        } else {
          if (ban + data[i] == 0) {
            ban = 0;
          } else if (((ban + data[i] > 0) ^ (second.back() > 0))) {
            ban += data[i];
            second.push_back(ban);
          } else {
            ban += data[i];
            if (!((data[i] > 0) ^ (second.back() > 0))) second[second.size() - 1] += data[i];
          }
        }
      }
      remains_ban = ban;
      ban = 0;
      data.swap(second);
    }
    return data.front() > 0 ? "Radiant" : "Dire";
  }
};