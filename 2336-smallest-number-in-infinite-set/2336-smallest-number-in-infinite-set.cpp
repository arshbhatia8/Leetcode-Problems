class SmallestInfiniteSet {
public:
    unordered_set<int> black;

    SmallestInfiniteSet() {
    }

    int popSmallest() {
        int i = 1;
        for (; black.count(i); ++i)
            ;
        black.insert(i);
        return i;
    }

    void addBack(int num) {
        black.erase(num);
    }
};