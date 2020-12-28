// gfg challenge
#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 26;
struct TrieNode
{
    map<char, TrieNode *> children;

    bool isEndOfWord;
};
TrieNode *getNode(void)
{
    TrieNode *newNode = new TrieNode;
    newNode->isEndOfWord = false;
    for (char i = 'a'; i <= 'z'; i++)
    {
        newNode->children[i] = NULL;
    }

    return newNode;
}
void insert(TrieNode *root, string key)
{
    TrieNode *temp = root;

    for (int i = 0; i < key.length(); i++)
    {

        if (temp->children[key[i]] == NULL)
        {
            temp->children[key[i]] = getNode();
        }
        temp = temp->children[key[i]];
    }

    temp->isEndOfWord = true;
}

void displayContactsUtil(struct TrieNode *curNode, string prefix)
{
    if (curNode->isEndOfWord)
        cout << prefix << " ";

    for (char i = 'a'; i <= 'z'; i++)
    {
        struct TrieNode *nextNode = curNode->children[i];
        if (nextNode != NULL)
            displayContactsUtil(nextNode, prefix + (char)i);
    }
}

void displayContacts(struct TrieNode *root, string query)
{
    struct TrieNode *prevNode = root;
    string prefix = "";

    int i;
    for (i = 0; i < query.length(); i++)
    {
        prefix += query[i];

        char lastchar = prefix[i];
        struct TrieNode *curNode = prevNode->children[lastchar];

        if (curNode == NULL)
        {
            cout << "0" << endl;
            i++;
            break;
        }

        displayContactsUtil(curNode, prefix);
        cout << endl;

        prevNode = curNode;
    }

    for (; i < query.length(); i++)
    {
        prefix += query[i];
        cout << "0" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string contacts[n];
        for (int i = 0; i < n; i++)
        {
            cin >> contacts[i];
        }
        struct TrieNode *root = getNode();
        for (int i = 0; i < n; i++)
        {
            insert(root, contacts[i]);
        }
        string query;
        cin >> query;
        displayContacts(root, query);
    }
}