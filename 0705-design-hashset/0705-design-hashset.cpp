class MyHashSet {
public:
    bool data[1000001];

    MyHashSet() {
        memset(data, false, sizeof data);
    }

    void add(int key) {
        data[key] = true;
    }

    void remove(int key) {
        data[key] = false;
    }

    bool contains(int key) {
        return data[key];
    }
};