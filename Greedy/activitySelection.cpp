#include <bits/stdc++.h>

using namespace std;

int maxMeetings(int *, int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}

int maxMeetings(int start[], int end[], int n) {
    if(!n) return n;
    vector<pair<int,int>> tim;
    
    for(int i=0;i<n;i++){
        tim.push_back({end[i],start[i]});
    }
    
    sort(tim.begin(),tim.end());
    int count = 1;
    int st = tim[0].second;
    int en = tim[0].first;
    
    for(int i=1;i<n;i++){
        if(tim[i].second > en){
            en = tim[i].second;
            count++;
        }
    }
    return count;
}