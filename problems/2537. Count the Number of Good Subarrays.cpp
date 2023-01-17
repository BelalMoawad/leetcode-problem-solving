// problem link : https://leetcode.com/problems/count-the-number-of-good-subarrays/description/

// code

class Solution {
public:
    long long countGood(vector<int>& v, int k) {
        int n = (int) v.size();
        map<int, int> mp;
        long long arrows = 0;
        int last = 0;
        for (int i = 0; i < n; ++i) {
            arrows += mp[v[i]];
            mp[v[i]]++;
            if(arrows >= k) {
                last = i;
                break;
            }
        }
        if(arrows < k) return 0;
        long long ret = (n - last);
        for (int i = 1; i < n; i++) {
            mp[v[i - 1]]--;
            arrows -= mp[v[i - 1]];
            while(last + 1 < n && arrows < k) {
                last++;
                arrows += mp[v[last]];
                mp[v[last]]++;
            }
            if(arrows < k) return ret;
            ret += (n - last);
        }
        return ret;
    }
};
