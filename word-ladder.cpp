class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int len = start.size();
        string str, tmp;
        queue<string> que;
        unordered_map<string, int> dis;
        
        que.push(start);
        dis[start] = 1;
        
        while (!que.empty()) {
            tmp = que.front();
            que.pop();
            if (str == end) 
                break;
            for (int i = 0; i < len; ++i) {
                str = tmp;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if (str[i] == ch) continue;
                    str[i] = ch;
                    if (dict.find(str) != dict.end() && dis.find(str) == dis.end()) {
                        dis[str] = dis[tmp] + 1;
                        que.push(str);
                    }
                }
            }
        }
        return dis.find(end) == dis.end() ? 0 : dis[end];
    }
};
