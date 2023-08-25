//Jai Sachidanand
#include <iostream>
typedef long long ll;
using namespace std;
#define vector vi
#include <bits/stdc++.h>
#define pb push_back
#define mod 1000000007
#define srt(v) sort(v.begin(),v.end())
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define all(v)  v.begin(),v.end()
//int ind = max_element(all(a)) - a.begin();
#define dis(v)  distance(v.begin(),max_element(all(v)))
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));// Apply after Sorting
// else only consecutive duplicates would be removed 
int  kSum(vector<int>& nums, int k) {
        
		ll sum=0,n=nums.size();
        vector<ll> ans;
        for(ll i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                sum+=nums[i];
            nums[i]=abs(nums[i]); 
			
        }
        ans.push_back(sum);
        priority_queue<pair<ll,ll>> pq;   
        sort(nums.begin(),nums.end());  
        pq.push({sum-nums[0],0});
		
        while(ans.size()<k)
        {
            auto it = pq.top();
            sum = it.first;
            int ind = it.second;
            pq.pop();
            if(ind+1<n)
            {
			
                pq.push({sum+nums[ind]-nums[ind+1],ind+1}); 
                pq.push({sum-nums[ind+1],ind+1});  
            }
            ans.push_back(sum);			
        }
        return ans.back();            
    }

void solve() {
    int n,k;
    cin >> n >> k;
    vi<int>a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int ans = kSum(a,k);
    cout << ans << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
