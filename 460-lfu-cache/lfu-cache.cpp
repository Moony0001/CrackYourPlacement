class LFUCache {
private:
    struct Node{
        int freq;
        int key;
        int value;
        list<int>::iterator it;
    };
    int cap;
    int mini;

    unordered_map<int, Node> kmap;
    unordered_map<int, list<int>> fmap;

    void promote(int key){
        Node& node = kmap[key];
        int f = node.freq;

        fmap[f].erase(node.it);

        if(fmap[f].empty() && f==mini){
            mini++;
        }

        node.freq++;
        fmap[node.freq].push_front(key);

        node.it = fmap[node.freq].begin();
    }


public:


    LFUCache(int capacity) {
        cap = capacity;
        mini = 0;
    }
    
    int get(int key) {
        if(kmap.count(key)){
            promote(key);
            return kmap[key].value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(kmap.count(key)){
            kmap[key].value = value;
            promote(key);
            return;
        }

        if(kmap.size()==cap){
            int rkey = fmap[mini].back();
            fmap[mini].pop_back();
            kmap.erase(rkey);
        }

        mini = 1;
        fmap[1].push_front(key);
        kmap[key] = {1, key, value, fmap[1].begin()};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */