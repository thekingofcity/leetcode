struct Node {
	int key;
	int value;
	Node(int k, int v) { key = k; value = v; };
};

class LRUCache {
private:
	size_t c;
	list<Node*> l;
	map<int, list<Node*>::iterator> m;

	Node* set_head(map<int, list<Node*>::iterator>::iterator it) {
		Node* n = *(it->second);
		l.erase(it->second);
		l.push_front(n);
		return n;
	}
public:
	LRUCache(int capacity) {
		c = capacity;
	}

	int get(int key) {
		auto it = m.find(key);
		if (it == m.end()) return -1;

		set_head(it);
		m[key] = l.begin();
		return (*(it->second))->value;
	}

	void put(int key, int value) {
		auto it = m.find(key);
		if (it == m.end()) {
			// not in cache
			Node* n = new Node(key, value);
			if (l.size() >= c) {
				int del_key = (*(--l.end()))->key;
				m.erase(del_key);
				l.pop_back();
			}
			l.push_front(n);
		}
		else {
			// move to front
			set_head(it)->value = value;
		}
		m[key] = l.begin();
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */