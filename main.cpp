#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol235;

/*
Input:
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
*/

tuple<vector<vector<char>>, vector<string>, vector<string>>
testFixture1()
{
  auto board = vector<vector<char>>{
      {'o', 'a', 'a', 'n'},
      {'e', 't', 'a', 'e'},
      {'i', 'h', 'k', 'r'},
      {'i', 'f', 'l', 'v'}};

  auto words = vector<string>{"oath", "pea", "eat", "rain"};
  auto output = vector<string>{"eat", "oath"};

  return {board, words, output};
}

void test1()
{
  auto f = testFixture1();
  Solution sol;

  cout << "Expect to see: " << Util::toString(get<2>(f)) << endl;
  cout << Util::toString(sol.findWords(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
}