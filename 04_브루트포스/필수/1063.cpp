#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> move(string king, string stone, string dir) {
    vector<string> result = {king, stone};
    
    if(dir == "R" && king[0] < 'H'){ //한칸 오른쪽
        king[0]++;
        if(king == stone) { //킹, 돌 위치 같으면 같은 방향으로 움직이기
            if(stone[0] < 'H') { //돌 내부에 있으면 돌 이동
                stone[0]++;
            }
            else { //아니면 킹 원위치
                king[0]--;
            }
        }
        return {king, stone};
    }
    else if(dir == "L" && king[0] > 'A'){ //한칸 왼쪽
        king[0]--;
        if(king == stone) {
            if(stone[0] > 'A') {
                stone[0]--;
            }
            else {
                king[0]++;
            }
        }
        return {king, stone};
    }
    else if(dir == "B" && king[1] > '1'){ //한칸 아래
        king[1]--;
        if(king == stone) {
            if(stone[1] > '1') {
                stone[1]--;
            }
            else {
                king[1]++;
            }
        }
        return {king, stone};
    }
    else if(dir == "T" && king[1] < '8'){ //한칸 위
        king[1]++;
        if(king == stone) {
            if(stone[1] < '8') {
                stone[1]++;
            }
            else {
                king[1]--;
            }
        }
        return {king, stone};
    }
    else if(dir == "RT" && king[0] < 'H' && king[1] < '8'){ //오른쪽 위 대각선
        king[0]++, king[1]++;
        if(king == stone) {
            if(stone[0] < 'H' && stone[1] < '8') {
                stone[0]++, stone[1]++;
            }
            else {
                king[0]--, king[1]--;
            }
        }
        return {king, stone};
    }
    else if(dir == "LT" && king[0] > 'A' && king[1] < '8'){ //왼쪽 위 대각선
        king[0]--, king[1]++;
        if(king == stone) {
            if(stone[0] > 'A' && stone[1] < '8') {
                stone[0]--, stone[1]++;
            }
            else {
                king[0]++, king[1]--;
            }
        }
        return {king, stone};
    }
    else if(dir == "RB" && king[0] < 'H' && king[1] > '1'){ //오른쪽 아래 대각선
        king[0]++, king[1]--;
        if(king == stone) {
            if(stone[0] < 'H' && stone[1] > '1') {
                stone[0]++, stone[1]--;
            }
            else {
                king[0]--, king[1]++;
            }
        }
        return {king, stone};
    }
    else if(dir == "LB" && king[0] > 'A' && king[1] > '1'){ //왼쪽 아래 대각선
        king[0]--, king[1]--;
        if(king == stone) {
            if(stone[0] > 'A' && stone[1] > '1') {
                stone[0]--, stone[1]--;
            }
            else {
                king[0]++, king[1]++;
            }
        }
        return {king, stone};
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string king;
    string stone;
    int num;
    cin >> king >> stone >> num;
    vector<string> v;

    for(int i=0; i<num; i++) {
        string dir;
        cin >> dir;
        v = move(king, stone, dir);

        king = v[0];
        stone = v[1];
    }

    cout << king << '\n' << stone;

}