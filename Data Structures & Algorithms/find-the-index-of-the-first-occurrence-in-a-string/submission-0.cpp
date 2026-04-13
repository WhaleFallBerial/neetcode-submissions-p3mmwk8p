class Solution {
public:
    int strStr(string haystack, string needle) {
     auto iter=haystack.find(needle);
     if(iter==string::npos)
     {
        return -1;
     }else{
        return iter;
     } 
    }
};