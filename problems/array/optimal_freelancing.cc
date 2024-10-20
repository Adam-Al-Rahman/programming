// Optimal Freelancing

// You recently started freelance software development and have been offered a variety of job
// opportunities. Each job has a deadline, meaning there is no value in completing the work after
// the deadline. Additionally, each job has an associated payment representing the profit for
// completing that job. Given this information, write a function that returns the maximum profit
// that can be obtained in a 7-day period.

// Each job will take 1 full day to complete, and the deadline will be given as the number of days
// left to complete the job. For example, if a job has a deadline of 1, then it can only be completed if
// it is the first job worked on. If a job has a deadline of 2, then it could be started on the first or
// second day.

// Note: There is no requirement to complete all of the jobs. Only one job can be worked on at a
// time, meaning that in some scenarios it will be impossible to complete them all.

#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

int optimalFreelancing(std::vector<std::unordered_map<std::string, int>> jobs) {
  int profit = 0;
  std::vector<bool> days(7, false);

  std::sort(jobs.begin(), jobs.end(), [](auto& a, auto& b) { return a.at("payment") > b.at("payment"); });

  for (const auto& job : jobs) {
    int deadline = std::min(job.at("deadline"), 7);
    for (int i = deadline - 1; i >= 0; --i) {
      if (!days[i]) {
        days[i] = true;
        profit += job.at("payment");
        break;
      }
    }
  }

  return profit;
}

int main() {
  std::vector<std::unordered_map<std::string, int>> jobs = {{{"deadline", 1}, {"payment", 1}}};
  auto expected = 1;
  auto actual = optimalFreelancing(jobs);
  assert(expected == actual);
}
