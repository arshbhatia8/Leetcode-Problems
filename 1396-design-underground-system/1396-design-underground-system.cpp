class UndergroundSystem {
public:
    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t) {
        ts[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [station, t0] = ts[id];
        auto key = station + "-" + stationName;
        auto [tot, cnt] = d[key];
        d[key] = {tot + t - t0, cnt + 1};
    }

    double getAverageTime(string startStation, string endStation) {
        auto [tot, cnt] = d[startStation + "-" + endStation];
        return (double) tot / cnt;
    }

private:
    unordered_map<int, pair<string, int>> ts;
    unordered_map<string, pair<int, int>> d;
};