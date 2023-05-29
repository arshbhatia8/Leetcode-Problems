class ParkingSystem {
public:
    vector<int> cnt;

    ParkingSystem(int big, int medium, int small) {
        cnt = {0, big, medium, small};
    }

    bool addCar(int carType) {
        if (cnt[carType] == 0) return false;
        --cnt[carType];
        return true;
    }
};