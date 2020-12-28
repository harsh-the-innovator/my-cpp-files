#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 26;

struct TrieNode
{
    struct TrieNode *children[MAX_SIZE]; //every element is pointing to TrieNode

    bool isEndOfWord;
};

TrieNode *getNode(void)
{
    TrieNode *newNode = new TrieNode; //creating new node
    newNode->isEndOfWord = false;     //initially false
    for (int i = 0; i < MAX_SIZE; i++)
    {
        newNode->children[i] = NULL; // initially every character is pointing to NULL
    }

    return newNode;
}

bool search(TrieNode *root, string key)
{
    TrieNode *temp = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (temp->children[index] == NULL)
            return false;
        temp = temp->children[index];
    }

    return (temp != NULL && temp->isEndOfWord);
}

void insert(TrieNode *root, string key)
{
    TrieNode *temp = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a'; //converting to numbers : a as 0,b as 1 to get the index

        if (temp->children[index] == NULL) //if pointing to null
        {
            temp->children[index] = getNode();
        }
        temp = temp->children[index];
    }

    temp->isEndOfWord = true; //last node is leaf that means word is completed
}

int main()
{
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their"};

    int n = sizeof(keys) / sizeof(keys[0]);
    TrieNode *root = getNode();

    for (int i = 0; i < n; i++)
    {
        insert(root, keys[i]);
    }

    // Search for different keys
    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    search(root, "these") ? cout << "Yes\n" : cout << "No\n";
    search(root, "there") ? cout << "Yes\n" : cout << "No\n";
    search(root, "thaw") ? cout << "Yes\n" : cout << "No\n";
}