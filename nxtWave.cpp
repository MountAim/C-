#include<iostream>
#include<vector>
#include<map>
using namespace std;

// int main(){
//     int n;
//     cin >> n; 
//     vector<vector<int>> v;
//     v.push_back({1});
//     for(int i = 1; i < n; ++ i){
//         vector<int> cur;
//         int prev = 0;
//         for(int j = 0; j < v[i - 1].size(); ++ i){
//             cur.push_back(prev + v[i - 1][j]);
//             prev = v[i - 1][j];
//         }
//         cur.push_back(v[i - 1].back());
//         v.push_back(cur);
//     }

//     for(int i = 0; i < n; ++ i){
//         for(int j = 0; j < v[i].size(); ++ j){
//             cout << v[i][j] << ' ';
//         }
//         cout << '\n';
//     }
//     return 0;

// }



// 6
// 7
// 3 2 6
// 5 3 1 
// 0 1 5
// 1 5 -3
// 1 2 -2 
// 3 4 -2 
// 2 4 3 
// 0




// void belman_ford(int n, int m,vector<vector<int>> adj, int root){
//     vector<int> dis(n, 10000);
//     dis[root] = 0;
    
//     for(int i = 0; i < n; ++ i){
//         int flag = 0;
//         for(int j = 0; j < m; ++ j){
//             if(dis[adj[j][0]] + adj[j][2] < dis[adj[j][1]]){
//                 dis[adj[j][1]] = dis[adj[j][0]] + adj[j][2];
//                 flag = 1;
//             }
//         }
//         if(flag == 0){
//           for(int i = 0; i < n; ++ i){
//                 if(dis[i] == 10000){
//                     cout << "No Valid Path ";
//                 }
//                 else{
//                     cout << dis[i] << ' ';
//                 }
//             }
//             return;
//         }
//     }
    
//     cout << "Negative weight Cycle exist";
    
    
    
// }

// a b cost

int calMaxMeetings(vector<int> start, vector<int> end){
    vector<pair<int,int> > a;
    
    map<pair<int,int>,int> mp;
    for(int i = 0; i <start.size(); ++ i){
        a.push_back({start[i], end[i]});
        mp[a.back()] = i;
    }
    
    sort(a.begin(), a.end());
    
    int meetings = 0;
    int curEnd = 0;
    
    vector<int> meetingsV;
    
    int prev = - 1;
    for(int i = 0 ;i < a.size(); ++ i){
        if(curEnd <= a[i].first){
            if(prev != - 1)
                meetingsV.push_back(prev);
            prev = mp[a[i]];
            ++ meetings;
            curEnd = a[i].second;
        }
        else{
            if(a[i].second < curEnd){
                curEnd = a[i].second;
                prev = mp[a[i]];
            }
        }
    }
    
    if(prev != - 1)
        meetingsV.push_back(prev);
    
    for(auto i : meetingsV){
        cout << i + 1 << ' ';
    }
    
    cout <<'\n';
    
    return meetings;
    
}

int main(){
    
    
    //start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}
     // 1 2 4 5
      // [1,3] [3,4] [0, 5] [5, 7] [8, 9] [5, 9]
      // [0, 5] [1, 3] [3, 4] [5, 7] [5, 9] [8, 9]
     // cur = -1
    
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for(int i = 0; i < n; ++ i){
        cin >> start[i];
    }
    
    for(int i = 0; i < n; ++ i){
        cin >> end[i];
    }
    
    cout << calMaxMeetings(start, end);
      
      
    return 0;
}
