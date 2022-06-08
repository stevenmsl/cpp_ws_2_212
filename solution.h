
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol235
{

  class Solution
  {
  private:
    void _search(
        int x, int y, Node *root,
        vector<vector<char>> &board, vector<string> &result);

  public:
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words);
  };

}
#endif