// https://leetcode.com/problems/insert-delete-getrandom-o1/discuss/85401/Java-solution-using-a-HashMap-and-an-ArrayList-along-with-a-follow-up.-(131-ms)
class RandomizedSet {
private:
    unordered_map<int, int> m;
    vector<int> vals;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = m.find(val);
        if (it!=m.end()) return false;
        m.insert({val, vals.size()});
        vals.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = m.find(val);
        if (it==m.end()) return false;
        if (vals.size()>1&&vals.begin()+it->second!=--vals.end()){
            unordered_map<int, int>::iterator s=m.find(*(--vals.end()));
            s->second=it->second;
            swap(vals[it->second], vals[vals.size()-1]);
        }
        vals.pop_back();
        m.erase(it);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vals[rand()%vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */