class Solution {
public:
    string simplifyPath(string path) {
        size_t i(0), j(0);
        vector<string> str;
        string ss;
        path.append("/");
        while ((j = path.find('/', i + 1)) != string::npos) {
            ss = path.substr(i + 1, j - i - 1);
            if (ss == "." || ss =="") ;
            else if (ss == "..") {
                if (!str.empty()) str.pop_back();
            }
            else {
                str.push_back(ss);
            }
            i = j;
        }
        ss = str.size() ? "" : "/";
        for (int i = 0; i < str.size(); ++i) ss += "/"+str[i];
        return ss;
    }
};
