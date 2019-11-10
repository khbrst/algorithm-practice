#include <iostream>
using namespace std;

enum {
  NUM_SWITCHES = 10,
  NUM_CLOCKS = 16,
  INF = 987654321
};

const int linked[NUM_SWITCHES][NUM_CLOCKS] = {
  { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
  { 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0 },
  { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
  { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
  { 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
  { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 }
};

int clocks[NUM_CLOCKS];

bool are_aligned()
{
  for (int clock = 0; clock < NUM_CLOCKS; ++clock) {
    if (clocks[clock] != 12) {
      return false;
    }
  }
  return true;
}

void press(int switch_index)
{
  for (int clock = 0; clock < NUM_CLOCKS; ++clock) {
    if (linked[switch_index][clock]) {
      clocks[clock] += 3;
      if (clocks[clock] == 15) {
        clocks[clock] = 3;
      }
    }
  }
}

int solve(int switch_index)
{
  if (switch_index == NUM_SWITCHES) {
    return are_aligned() ? 0 : INF;
  }

  int answer = INF;
  for (int switch_count = 0; switch_count < 4; ++switch_count) {
    answer = min(answer, switch_count + solve(switch_index + 1));
    press(switch_index);
  }
  return answer;
}

int main(int argc, char **argv) {
  int T;
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    for (int i = 0; i < NUM_CLOCKS; ++i) {
      cin >> clocks[i];
    }
    int answer = solve(0);
    answer = (answer == INF) ? -1 : answer;
    cout << answer << endl;
  }
  return 0;
}
