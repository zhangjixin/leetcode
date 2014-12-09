struct node{
  int val,dex;  
  node() : val(0),dex(0) {}
  bool operator < (const node& str) const{
        return (val < str.val);
    } 
};
class Solution {
public:
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        
        std::vector<int> ans;
        int mytmp = 0, mycnt = 1, mysize = numbers.size();
        int myleft = 0, myright = mysize-1;
        struct node myvec[mysize+10];
        std::vector<int>::iterator itbegin = numbers.begin(), itend = numbers.end();
        while(itbegin != itend){
            myvec[mycnt-1].val = *itbegin;
            myvec[mycnt-1].dex = mycnt;
            ++mycnt;
            ++itbegin;
        }
        std::sort(myvec, myvec+mysize);
        while(myleft < myright){
           mytmp = myvec[myleft].val + myvec[myright].val;
           if(mytmp < target){
               ++myleft;
           }else if(mytmp > target){
               --myright;
           }else{
               int index1 = myvec[myleft].dex, index2 = myvec[myright].dex;
               if(index1 > index2){
                    ans.push_back(index2);
                    ans.push_back(index1);
               }else{
                   ans.push_back(index1);
                   ans.push_back(index2);
               }
               return ans;
           }
       }
    }
};
