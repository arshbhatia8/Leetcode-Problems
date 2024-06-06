class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        
        if (hand.size() % groupSize != 0) {
            return false;
        }

        
        std::unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

    
        std::vector<int> sortedKeys;
        for (auto& pair : count) {
            sortedKeys.push_back(pair.first);
        }
        std::sort(sortedKeys.begin(), sortedKeys.end());

       
        for (int key : sortedKeys) {
            if (count[key] > 0) {  
                int startCount = count[key];
                
                for (int i = key; i < key + groupSize; i++) {
                    if (count[i] < startCount) {
                        return false;
                    }
                    count[i] -= startCount;
                }
            }
        }

  
        return true;
    }
};