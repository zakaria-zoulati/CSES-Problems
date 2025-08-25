#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int,int>> intervals(n);
    for(int i=0;i<n;i++) cin >> intervals[i].first >> intervals[i].second;

    vector<tuple<int,int,int>> m;
    for(int i=0;i<n;i++) m.push_back({intervals[i].first, intervals[i].second, i});
    sort(m.begin(), m.end()); 

    vector<int> rs(n);
    int nextRoom = 1;


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    for(auto [l, r, idx] : m) {
        if(!pq.empty() && pq.top().first < l) {
            auto [end, room] = pq.top(); pq.pop();
            rs[idx] = room;
            pq.push({r, room});
        } else {
            rs[idx] = nextRoom;
            pq.push({r, nextRoom});
            nextRoom++;
        }
    }

    cout << nextRoom-1 << "\n";
    for(int i=0;i<n;i++) cout << rs[i] << " ";
    cout << "\n";
}
