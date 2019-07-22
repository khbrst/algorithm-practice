#include <iostream>
using namespace std;

#define ATOI(a) ((a) - '0')

struct Paper {
  int left;
  int right;
};
Paper papers[1000];

int main(int argc, char **argv) {
  int test_case;
  int T;
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int N, answer = 0, left = 0, right = 0, mid = 0, paper_count = 0;
    char paper[4];
    cin >> N;
    for (int i = 1; i <= N; ++i) {
      cin >> paper;
      if (paper[0] == '*') {
        if (paper[1] == '*') {
          if (paper[2] != '*') {
            int third = ATOI(paper[2]);
            if (left < third) {
              left = third;
            }
          }
        } else {
          int second = ATOI(paper[1]);
          if (paper[2] == '*') {
            if (mid < second) {
              mid = second;
            }
          } else {
            int third = ATOI(paper[2]) + second;
            if (left < third) {
              left = third;
            }
          }
        }
      } else {
        int first = ATOI(paper[0]);
        if (paper[1] == '*') {
          if (paper[2] == '*') {
            if (right < first) {
              right = first;
            }
          } else {
            papers[paper_count].left = ATOI(paper[2]);
            papers[paper_count].right = first;
            ++paper_count;
          }
        } else {
          int second = ATOI(paper[1]);
          if (paper[2] == '*') {
            second += first;
            if (right < second) {
              right = second;
            }
          } else {
            answer += ATOI(paper[2]) + first + second;
          }
        }
      }
    }

    int anchor = left + right;
    for (int i = 0; i < paper_count; ++i) {
      if (anchor < (papers[i].left + right)) {
        anchor = papers[i].left + right;
      }
      if (anchor < (left + papers[i].right)) {
        anchor = left + papers[i].right;
      }
      for (int j = 0; j < paper_count; ++j) {
        if (i != j) {
          if (anchor < (papers[i].left + papers[j].right)) {
            anchor = papers[i].left + papers[j].right;
          }
        }
      }
    }

    answer += anchor;
    if (answer < mid) {
      answer = mid;
    }
    cout << "#" << test_case << " " << answer << endl;
  }
  return 0;
}
