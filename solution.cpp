#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace sol235;
using namespace std;

/*takeaways
  - build a trie tree from the words
  - exhaust all the possible paths (DFS) starting
    for every location on the board. Check if
    a given path is in the trie tree
  - time complexity O(sum(m*n*4^l))
*/

vector<string> Solution::findWords(vector<vector<char>> &board,
                                   vector<string> &words)
{
  /* build the trie tree */
  auto trie = new Node();

  /* build the trie tree */
  for (auto w : words)
  {
    auto p = trie;
    for (auto c : w)
    {
      auto indx = c - 'a';
      if (p->chars[indx] == nullptr)
        p->chars[indx] = new Node();
      p = p->chars[indx];
    }
    /* store the word so we don't need to remember the path */
    p->word = w;
  }

  auto result = vector<string>();

  /* start from every possible location on the board */
  for (auto i = 0; i < board.size(); i++)
    for (auto j = 0; j < board[0].size(); j++)
      _search(j, i, trie, board, result);

  return result;
}

/* x is the col and y is the row */
void Solution::_search(
    int x, int y, Node *root,
    vector<vector<char>> &board, vector<string> &result)
{
  /* board[y][x] == '*' meaning this node has been visisted
     while constructing this path
  */
  int n = board.size(), m = board[0].size();
  if (x < 0 || y < 0 || x == m || y == n || board[y][x] == '*')
    return;
  auto c = board[y][x];
  auto idx = c - 'a';
  if (root->chars[idx] == nullptr)
    return;

  auto next = root->chars[idx];

  if (next->word != "")
  {
    result.push_back(next->word);
    /* so we won't pick it up again to avoid creating duplicates */
    next->word = "";
  }

  /* visiting all neighbors */
  board[y][x] = '*';

  _search(x, y - 1, next, board, result);
  _search(x, y + 1, next, board, result);
  _search(x - 1, y, next, board, result);
  _search(x + 1, y, next, board, result);

  /* restore it as we need to roll back everything
     before visiting the next location on the board
  */
  board[y][x] = c;
}
