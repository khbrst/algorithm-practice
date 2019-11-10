#include <iostream>
using namespace std;

enum {
  MAX_H = 20,
  MAX_W = 20
};

const int coverTypes[4][3][2] = {
  { { 0, 0}, { 1, 0 }, { 0, 1 } },
  { { 0, 0}, { 0, 1 }, { 1, 1 } },
  { { 0, 0}, { 1, 0 }, { 1, 1 } },
  { { 0, 0}, { 1, 0 }, { 1, -1 } }
};

int H, W;
int board[MAX_H][MAX_W];

bool set(int type, int x, int y, int delta)
{
  bool ok = true;
  for (int i = 0; i < 3; ++i) {
    int ny = y + coverTypes[type][i][0];
    int nx = x + coverTypes[type][i][1];
    if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
      ok = false;
    } else if ((board[ny][nx] += delta) > 1) {
      ok = false;
    }
  }
  return ok;
}

int cover()
{
  int x = -1, y = -1;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (board[i][j] == 0) {
        y = i;
        x = j;
        break;
      }
    }
    if (y != -1) break;
  }
  if (y == -1) return 1;

  int covered = 0;
  for (int i = 0; i < 4; ++i) {
    if (set(i, x, y, 1)) {
      covered += cover();
    }
    set(i, x, y, -1);
  }
  return covered;
}

int main(int argc, char **argv) {
  int T;
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    int whiteCount = 0;
    cin >> H >> W;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        char c;
        cin >> c;
        if (c == '#') {
          board[i][j] = 1;
        } else {
          board[i][j] = 0;
          ++whiteCount;
        }
      }
    }

    int answer = 0;
    if (whiteCount > 0 && whiteCount % 3 == 0) {
      answer = cover();
    }
    cout << answer << endl;
  }
  return 0;
}
