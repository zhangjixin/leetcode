class Node {
public :
    vector<int> next;
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        Node node[numCourses];
        vector<int> inDegree(numCourses, 0);
        vector<int> ans;
        int cnt = 0;
        
        for (auto pir : prerequisites) {
            ++inDegree[pir.first];
            node[pir.second].next.push_back(pir.first);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                ++cnt;
                ans.push_back(i);
                dfs(node, inDegree, ans, cnt, i);
            }
        }
        
        if (cnt != numCourses) {
            ans.clear();
        }
        return ans;
    }
    void dfs(const Node node[], vector<int> &inDegree, vector<int> &ans, int &cnt, int idx) {
        for (auto i : node[idx].next) {
            --inDegree[i];
            if (inDegree[i] == 0) {
                ++cnt;
                inDegree[i] = -1;
                ans.push_back(i);
                dfs(node, inDegree, ans, cnt, i);
            }
        }
    }
};