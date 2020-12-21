#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("AllergenAssessmentIn.txt", "r", stdin);
  string s;
  vector<set<string>> ingredients(1), allergens(1);
  while (cin >> s) {
    if (s[0] == '(') {
      while (cin >> s) {
        string t = s;
        t.pop_back();
        allergens.back().insert(t);
        if (s.back() == ')') {
          break;
        }
      }
      allergens.resize((int) allergens.size() + 1);
      ingredients.resize((int) ingredients.size() + 1);
    } else {
      ingredients.back().insert(s);
    }
  }
  allergens.pop_back();
  ingredients.pop_back();
  map<string, int> ingredientCount;
  for (auto& ingredientsList : ingredients) {
    for (string ingredient : ingredientsList) {
      ++ingredientCount[ingredient];
    }
  }
  map<string, int> allergenCount;
  for (auto& allergensList : allergens) {
    for (string allergen : allergensList) {
      ++allergenCount[allergen];
    }
  }
  map<string, set<int>> allergenPos;
  int n = (int) ingredients.size();
  for (int i = 0; i < n; i++) {
    for (string ingredient : ingredients[i]) {
      for (string allergen : allergens[i]) {
        allergenPos[allergen].insert(i);
      }
    }
  }
  vector<string> names;
  for (auto& [allergen, cnt] : allergenCount) {
    names.push_back(allergen);
  }
  vector<pair<string, string>> res;
  while (true) {
    bool found = false;
    for (string& name : names) {
      int m = allergenPos[name].size();
      vector<int> pos(allergenPos[name].begin(), allergenPos[name].end());
      set<string> candidates = ingredients[pos[0]];
      for (int i = 1; i < m; i++) {
        set<string> intersect;
        for (string ingredient : ingredients[pos[i]]) {
          if (candidates.count(ingredient)) {
            intersect.insert(ingredient);
          }
        }
        candidates = intersect;
      }
      if ((int) candidates.size() == 1) {
        string ingredient = *candidates.begin();
        res.emplace_back(name, ingredient);
        for (auto& v : ingredients) {
          if (v.count(ingredient)) {
            v.erase(ingredient);
          }
        }
        found = true;
      }
    }
    if (!found) {
      break;
    }
  }
  sort(res.begin(), res.end());
  string answer;
  for (auto& [allergen, ingredient] : res) {
    answer += ingredient;
    answer += ',';
  }
  answer.pop_back();
  cout << answer << '\n';
  return 0;
}