class Solution {
public:
    int strStr(string haystack, string needle) {

    int nLen = needle.length();
    int hLen = haystack.length();
    
    if (nLen == 0) 
        return 0;

    int hIdx = 0;
    while (hIdx < hLen - nLen + 1) {
      // find the position of the first needle character
      // in the haystack string
      while (hIdx < hLen - nLen + 1 && haystack[hIdx] != needle[0] ) 
          ++hIdx;

      // compute the max match string
      int currLen = 0, nIdx = 0;
      while (nIdx < nLen && hIdx < hLen && haystack[hIdx] == needle[nIdx]) {
        ++hIdx;
        ++nIdx;
        ++currLen;
      }

      // if the whole needle string is found,
      // return its start position
      if (currLen == nLen) 
          return hIdx - nLen;

      // otherwise, backtrack
      hIdx = hIdx - currLen + 1;
    }
    return -1;
  }
};
