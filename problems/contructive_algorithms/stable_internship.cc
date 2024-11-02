// Stable Internships

// A company has hired N interns to each join one of N different teams. Each intern has ranked
// their preferences for which teams they wish to join, and each team has ranked their preferences
// for which interns they prefer.

// Given these preferences, assign 1 intern to each team. These assignments should be "stable,"
// meaning that there is no unmatched pair of an intern and a team such that both that intern and
// that team would prefer they be matched with each other.

// In the case there are multiple valid stable matchings, the solution that is most optimal for the
// interns should be chosen (i.e. every intern should be matched with the best team possible for
// them).

// Your function should take in 2 2-dimensional lists, one for interns and one for teams. Each inner
// list represents a single intern or team's preferences, ranked from most preferable to least
// preferable. These lists will always be of length N, with integers as elements. Each of these
// integers corresponds to the index of the team/intern being ranked. Your function should return
// a 2-dimensional list of matchings in no particular order. Each matching should be in the format
// [internlndex, teamlndex].

#include <cassert>
#include <stack>
#include <unordered_map>
#include <vector>

// TC: O(n^2) | SC: O(n^2)
std::vector<std::vector<int>> stableInternships(std::vector<std::vector<int>> interns,
                                                std::vector<std::vector<int>> teams) {
  std::unordered_map<int, int> chosen_interns;

  std::stack<int> free_interns;
  for (int i = 0; i < interns.size(); i++) free_interns.push(i);

  std::vector<int> current_intern_choices(interns.size(), 0);

  std::vector<std::unordered_map<int, int>> team_maps;
  for (std::vector<int> team : teams) {
    std::unordered_map<int, int> rank;
    for (int i = 0; i < teams.size(); i++) rank[team[i]] = i;

    team_maps.push_back(rank);
  }

  while (!free_interns.empty()) {
    int intern_num = free_interns.top();
    free_interns.pop();

    std::vector<int> intern = interns[intern_num];

    int team_preference = intern[current_intern_choices[intern_num]];
    current_intern_choices[intern_num] += 1;

    if (chosen_interns.find(team_preference) == chosen_interns.end()) {
      chosen_interns[team_preference] = intern_num;
      continue;
    }

    int previous_intern = chosen_interns[team_preference];
    int previous_intern_rank = team_maps[team_preference][previous_intern];
    int current_intern_rank = team_maps[team_preference][intern_num];

    if (current_intern_rank < previous_intern_rank) {
      free_interns.push(previous_intern);
      chosen_interns[team_preference] = intern_num;
    } else {
      free_interns.push(intern_num);
    }
  }

  std::vector<std::vector<int>> matches;
  for (auto chosen_intern : chosen_interns) {
    matches.push_back({chosen_intern.second, chosen_intern.first});
  }

  return matches;
}

int main() {
  std::vector<std::vector<int>> interns = {{0, 1}, {1, 0}};
  std::vector<std::vector<int>> teams = {{1, 0}, {1, 0}};
  std::vector<std::vector<int>> expected = {{0, 0}, {1, 1}};
  auto actual = stableInternships(interns, teams);

  assert(expected.size() == actual.size());

  for (auto match : expected) {
    bool containsMatch = false;
    for (auto actualMatch : actual) {
      if (actualMatch[0] == match[0] && actualMatch[1] == match[1]) {
        containsMatch = true;
      }
    }
    assert(containsMatch);
  }
}
