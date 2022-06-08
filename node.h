#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
#include <cinttypes>
using namespace std;

namespace sol235
{
    struct Node
    {
        string word;
        vector<Node *> chars;
        Node() : word(""), chars(26, nullptr){};
    };
}
#endif