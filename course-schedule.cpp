class Node {
public:
  vector<int> next;  
};
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Node node[numCourses];
        vector<int> inDegree(numCourses, 0);
        queue<int> que;
        int cnt = 0;
        for (auto par : prerequisites) {
            inDegree[par.first]++;
            node[par.second].next.push_back(par.first);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                que.push(i);
                ++cnt;
            }
        }
        while (!que.empty()) {
            int iFront = que.front();
            que.pop();
            for (auto idx : node[iFront].next) {
                if (inDegree[idx] > 0)
                    --inDegree[idx];
                if (inDegree[idx] <= 0) {
                    que.push(idx);
                    ++cnt;
                }
            }
        }
        return cnt == numCourses;
    }
};