#include<iostream>
#include<vector>
using namespace std;

int getDistance(string word){
    vector<vector<int>> keyboard;
    vector<string> row;

    row[0] = "QWERTYUIOP";
    row[1] = "ASDFGHJKL?";
    row[2] = "?ZXCVBNM??";

    for(int i = 0; i < 3; ++ i){
        vector<int> temp;
        for(int j = 0; j < 10; ++ j){
            temp.push_back(row[i][j] - 'A');
        }
        keyboard.push_back(temp);
    }

    vector<vector<int>> dis(26, vector<int>(26,0));

    for(int i = 0; i < 3; ++ i){
        for(int j = 0; j < 10; ++ j){
            for(int k = 0; k < 3; ++ k){
                for(int l = 0; l < 10; ++ l){
                    dis[keyboard[i][j]][keyboard[k][l]] = abs(i - k) + abs(j - l);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < word.size() - 1; ++ i){
        ans += dis[word[i] - 'A'][word[i + 1] - 'A'];
    }

    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << getDistance(s);
}
