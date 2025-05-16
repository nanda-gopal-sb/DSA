#include <iostream>
#include <string>

using namespace std;
class Solution {
 public:
  void trim(string& s) {
    while (s.front() == ' ') {
      s.erase();
      cout << s.front();
    }
    while (s.back() == ' ') {
      s.pop_back();
    }
  }
  int lengthOfLastWord(string s) {
    int lastLetter = 0;
    int posWhite = 0;
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
    s.erase(0, s.find_first_of(" \n\r\t"));
    cout << s;
    for (int i = 0; i < s.length(); i++) {
      if (s.at(i) == ' ') {
        posWhite = i;
      }
    }

    if (s.length() == 1) {
      cout << "LMAO\n";
      return s.length();
    }
    return (s.length() - posWhite);
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  cout << sol.lengthOfLastWord("  a ");
  return 0;
}
