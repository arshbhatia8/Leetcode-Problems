class SnapshotArray {
public:
    SnapshotArray(int length) {
        idx = 0;
        arr = vector<vector<pair<int, int>>>(length);
    }

    void set(int index, int val) {
        arr[index].push_back({idx, val});
    }

    int snap() {
        return idx++;
    }

    int get(int index, int snap_id) {
        auto& vals = arr[index];
        int left = 0, right = vals.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (vals[mid].first > snap_id) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left == 0 ? 0 : vals[left - 1].second;
    }

private:
    vector<vector<pair<int, int>>> arr;
    int idx;
};