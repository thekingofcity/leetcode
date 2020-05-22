// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/discuss/85541/C%2B%2B-128m-Solution-Real-O(1)-Solution
class RandomizedCollection {
private:
    unordered_map<int, vector<int>> m;
    vector<pair<int, int>> vals;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val){
        auto result = m.find(val) == m.end();
        
        m[val].push_back(vals.size());
        vals.push_back(pair<int, int>(val, m[val].size() - 1));
        
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto result = m.find(val) != m.end();
        if(result)
        {
            auto last = vals.back();
            m[last.first][last.second] = m[val].back();
            vals[m[val].back()] = last;
            m[val].pop_back();
            if(m[val].empty()) m.erase(val);
            vals.pop_back();
        }
        return result;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vals[rand()%vals.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */