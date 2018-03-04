#include <iostream>
#include <vector>
using namespace std;

namespace {
vector<int> heights;

int getLargestArea(int left, int right) {
  if (left == right) return heights[left];
  int mid = (left + right) / 2;
  int area = max(getLargestArea(left, mid), getLargestArea(mid + 1, right));
  int lo = mid, hi = mid + 1;
  int height = min(heights[lo], heights[hi]);
  area = max(area, height * 2);
  while (left < lo || hi < right) {
    if (hi < right && (lo == left || heights[lo - 1] < heights[hi + 1])) {
      ++hi;
      height = min(height, heights[hi]);
    } else {
      --lo;
      height = min(height, heights[lo]);
    }
    area = max(area, height * (hi - lo + 1));
  }
  return area;
}
}

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    int size, height;
    cin >> size;
    for (int i = 0; i < size; ++i) {
      cin >> height;
      heights.push_back(height);
    }
    cout << getLargestArea(0, size - 1) << endl;
    heights.clear();
  }
}