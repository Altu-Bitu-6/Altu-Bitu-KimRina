#include <iostream>
#include <vector>

using namespace std;

//청소 완료된 칸 2로 표시
const int CLEAN = 2;

//방향 배열
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}; // 북 동 남 서

int clean(int n, int m, int r, int c, int d, vector<vector<int>> &board) {
    int cnt = 0;

    while(true) {
        // 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
        if(board[r][c] != CLEAN) {
            cnt++; //청소한 칸 count
        }
        board[r][c] = CLEAN; //현재 칸 청소완료로 바꾸기

        bool find = false; // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는가
        
        //현재 위치 주변 4칸 탐색하기
        for(int i = 0; i < 4; i++) {
            int nd = (d-i+3) % 4; //반시계 방향으로 90도 회전하기
            int nr = r + dy[nd], nc = c + dx[nd]; //새로운 좌표

            if(board[nr][nc] == 0) { // 3-2. 아직 청소되지 않은 빈 칸 발견
                find = true;
                r = nr; c = nc; d = nd; //해당 방향으로 이동, 방향 설정
                break;
            }
        }
        if(find) { // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우 1번으로 돌아감
            continue;
        }

        // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        int bd = (d+2) % 4; // 현재방향 반대방향(뒤로 한칸)
        int br = r + dy[bd], bc = c + dx[bd]; //뒤로 한칸 갔을 때 좌표

        // [바라보는 방향을 유지한 채로 한 칸 후진할 수 있는가]
        // 2-2. 뒤쪽 칸이 벽이라 후진할 수 없는 경우
        if(board[br][bc] == 1) {
            return cnt; //청소한 칸 수 return
        }
        // 2-1. 바라보는 방향을 유지한 채로 한 칸 후진
        r = br; c = bc;
    }
    return cnt;
}

/*
 * [로봇 청소기 작동]
 * 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
 * 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
 *  2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
 *  2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
 * 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
 *  3-1. 반시계 방향으로 90º 회전한다.
 *  3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
 *  3-3. 1번으로 돌아간다.
*/

int main() {
    int n, m, r, c, d;
    vector<vector<int>> board;

    cin >> n >> m;
    cin >> r >> c >> d;

    // 방 상태 입력
    board.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 연산 & 출력
    cout << clean(n, m, r, c, d, board);
    
    return 0;
}