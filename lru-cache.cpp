class LRUCache{
public:
    LRUCache(int capacity) {
        mymap.clear();
        n = capacity + 2;
        mynode = new node[n];
        mynode[0].next = -1, mynode[1].pre = 0, mynode[1].next = 2;
        mynode[2].pre = 0, mynode[2].next = -1;
        for (int i = 3; i < n; ++i) {
            mynode[i].pre = i - 1;
            mynode[i].next = -1;
        }
    }
    
    ~LRUCache() {
        delete[] mynode;
    }
    
    int get(int key) {
        if ((it = mymap.find(key)) != mymap.end()) {
            if (it->second == -1) return -1;
            set (key, mynode[it->second].value);
            return mynode[it->second].value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        int i = 0, j, k, p;
        if ((it = mymap.find(key)) != mymap.end() && (j = it->second) != -1) {
                mynode[j].value = value;
                k = mynode[j].next, p = mynode[j].pre;
                if (p != 0) {
                    if ( k != -1){
                        mynode[k].pre = p;
                    } else {
                        mynode[1].pre = p;
                    }
                    mynode[p].next = k;
                    mynode[j].next = mynode[0].next, mynode[mynode[0].next].pre = j;
                    mynode[j].pre = 0, mynode[0].next = j;
                }
                return;
        }
        if (n > 2) {
            k = mynode[1].next, mynode[1].next = k + 1;
            p = mynode[0].next;
            mynode[k].key = key, mynode[k].value = value;
            if ( p == -1) {
                mynode[0].next = k, mynode[k].pre = 0;
                mynode[k].next = -1;
                mynode[1].pre = k;
            } else {
                mynode[p].pre = k, mynode[k].next = p;
                mynode[k].pre = 0, mynode[0].next = k;
            }
            mymap[key] = k;
            --n;
        } else {
            k = mynode[1].pre, p = mynode[k].pre;
            mymap[mynode[k].key] = -1;
            mymap[key] = k;
            if (p != 0) {
                mynode[1].pre = p, mynode[p].next = -1;
                mynode[k].next = mynode[0].next, mynode[mynode[0].next].pre = k;
                mynode[0].next = k, mynode[k].pre = 0;
            }
            mynode[k].key = key, mynode[k].value = value;
        }
    }
private:
    typedef struct Node {
        int key, value, pre, next;
        Node() : key(0), value(0), pre(-1), next(-1){}
    }node;
    node *mynode;
    map<int, int> mymap;
    map<int, int>::iterator it;
    int n;
};