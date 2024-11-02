// Task Assignment

// You're given an integer k representing a number of workers and an array of positive integers
// representing durations of tasks that must be completed by the workers. Specifically, each worker
// must complete two unique tasks and can only work on one task at a time. The number of tasks
// will always be equal to 2k such that each worker always has exactly two tasks to complete. All
// tasks are independent of one another and can be completed in any order. Workers will complete
// their assigned tasks in parallel, and the time taken to complete all tasks will be equal to the time
// taken to complete the longest pair of tasks (see the sample output for an explanation).

// Write a function that returns the optimal assignment of tasks to each worker such that the tasks
// are completed as fast as possible. Your function should return a list of pairs, where each pair
// stores the indices of the tasks that should be completed by one worker. The pairs should be in
// the following format: [taskl, task2] , where the order of taskl and task2 doesn't
// matter. Your function can return the pairs in any order. If multiple optimal assignments exist,
// any correct answer will be accepted.

// Note: you'll always be given at least one worker (i.e., k will always be greater than O).

#include <algorithm>
#include <cassert>
#include <vector>

std::vector<std::vector<int>> taskAssignment(int k, std::vector<int> tasks) {
  int size = tasks.size();
  std::vector<std::vector<int>> task_idx;
  for (int i = 0; i < size; i++) task_idx.push_back({tasks[i], i});

  std::sort(task_idx.begin(), task_idx.end());

  std::vector<std::vector<int>> assign;
  for (int i = 0; i < size / 2; i++) {
    assign.push_back({task_idx[i][1], task_idx[size - i - 1][1]});
  }

  return assign;
}

int main() {
  int k = 3;
  std::vector<int> tasks = {1, 3, 5, 3, 1, 4};
  std::vector<std::vector<int>> expected = {{4, 2}, {0, 5}, {3, 1}};
  auto actual = taskAssignment(k, tasks);
  assert(expected == actual);
}
