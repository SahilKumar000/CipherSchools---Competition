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

void solve() {
    int n;
    cin >> n;
    vi<int>a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int i = 0;
    int j = n - 1;
    int ans = INT_MIN;

    while(i < j){
        int w = j - i;
        int Mn = min(a[i],a[j]);
        int water = w*Mn;
        ans = max(ans,water);
        if(a[i] < a[j]) i++;
        else j--;
    }
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
