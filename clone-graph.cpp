/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 #define unode UndirectedGraphNode
 #define umap unordered_map
 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return node;
        umap<int, unode *> mm;
        return doit(node, mm);
    }
private:
    unode *doit(unode *node, umap<int, unode *> &mm) {
        unode *p = new unode(node->label);
        mm[p->label] = p;
        for (auto it = (node->neighbors).begin(); it != (node->neighbors).end(); ++it) {
            if (mm.find((*it)->label) == mm.end()) {
                p->neighbors.push_back(doit(*it, mm));
            }
            else {
                p->neighbors.push_back(mm[(*it)->label]);
            }
        }
        return p;
    }
};
