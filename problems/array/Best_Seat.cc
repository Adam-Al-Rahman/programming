// Best Seat

// You walk into a theatre you're about to see a show in. The usher within the theatre walks you
// to your row and mentions you're allowed to sit anywhere within the given row. Naturally you'd
// like to sit in the seat that gives you the most space. You also would prefer this space to be
// evenly distributed on either side of you (e.g. if there are three empty seats in a row, you would
// prefer to sit in the middle of those three seats).

// Given the theatre row represented as an integer array, return the seat index of where you
// should sit. Ones represent occupied seats and zeroes represent empty seats.

// You may assume that someone is always sitting in the first and last seat of the row. Whenever
// there are two equally good seats, you should sit in the seat with the lower index. If there is no
// seat to sit in, return -1 . The given array will always have a length of at least one and contain
// only ones and zeroes.

#include <cassert>
#include <vector>

int bestSeat(const std::vector<int>& a) {
  int idx = -1;
  int max_space = 0;

  int i = 0;
  while (i < a.size()) {
    // i-th seat not free
    if (a[i] != 0) {
      i += 1;
      continue;
    }

    // start of free space
    int start = i;
    while (i < a.size() && a[i] == 0) i += 1;  // a[i] value 0 are visited only once including parent loop
    int end = i - 1;                           // -1: at current i-th the value is != 0;

    int space_size = end - start + 1;  // +1: both start and end are inclusive indices
    if (space_size > max_space) {
      max_space = space_size;
      idx = (start + end) / 2;
    }
  }

  return idx;
}

int main() {
  std::vector<int> input = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1};
  auto expected = 3;
  auto actual = bestSeat(input);
  assert(expected == actual);
}
