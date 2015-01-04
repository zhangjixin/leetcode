class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size(), dex = len - 2, k;
        while(dex >= 0 && num[dex] >= num[dex+1]) --dex;
        if(dex < 0) exchange(num, 0, len - 1);
        else{
            k = len-1;
            while(num[dex] >= num[k]) --k;
            num[dex]^=num[k], num[k]^=num[dex], num[dex]^=num[k];
            exchange(num, dex + 1, len-1);
        }
    }
private:
    void exchange(vector<int> &num, int i, int j) {
        while(j > i) {
            num[i]^=num[j], num[j]^=num[i], num[i]^=num[j];
            --j, ++i;
        }
    }
};