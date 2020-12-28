#include <bits/stdc++.h>
using namespace std;

#define M 3

struct TrieNode
{
    map<char, TrieNode *> Child;

    bool isLeaf;
};

TrieNode *getNode()
{
    TrieNode *newNode = new TrieNode;
    newNode->isLeaf = false;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        newNode->Child[ch] = NULL;
    }
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        newNode->Child[ch] = NULL;
    }
    return newNode;
}

void insert(TrieNode *root, string key)
{
    TrieNode *temp = root;

    for (int i = 0; i < key.length(); i++)
    {
        if (temp->Child[key[i]] == NULL)
        {
            temp->Child[key[i]] = getNode();
        }
        temp = temp->Child[key[i]];
    }

    temp->isLeaf = true;
}

bool isSafe(int i, int j, bool visited[M][M])
{
    return (i >= 0 && i < M && j >= 0 &&
            j < M && !visited[i][j]);
}

void searchWord(TrieNode *root, char boggle[M][M], int i, int j, string str, bool visited[M][M])
{
    if (root->isLeaf == true)
    {
        cout << str << endl;
    }

    if (isSafe(i, j, visited))
    {
        visited[i][j] = true;

        for (auto itr = root->Child.begin(); itr != root->Child.end(); itr++)
        {
            if (itr->second != NULL)
            {
                char ch = itr->first;
                for (int row = i - 1; row <= i + 1 && row < M; row++)
                {
                    for (int col = j - 1; col <= j + 1 && col < M; col++)
                    {
                        if (isSafe(row, col, visited) && boggle[row][col] == ch)
                        {
                            searchWord(root->Child[ch], boggle, row, col, str + ch, visited);
                        }
                    }
                }
            }
        }

        visited[i][j] = false;
    }
}

void findWords(char boggle[M][M], TrieNode *root)
{
    bool visited[M][M];
    memset(visited, false, sizeof(visited));

    TrieNode *temp = root;
    string str = "";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (temp->Child[boggle[i][j]] != NULL)
            {
                str.push_back(boggle[i][j]);
                searchWord(temp->Child[boggle[i][j]], boggle, i, j, str, visited);
                str = "";
            }
        }
    }
}

int main()
{
    string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GEE"};

    int n = sizeof(dictionary) / sizeof(dictionary[0]);

    TrieNode *root = getNode();

    for (int i = 0; i < n; i++)
    {
        insert(root, dictionary[i]);
    }

    char boggle[M][M] = {{'G', 'I', 'Z'},
                         {'U', 'E', 'K'},
                         {'Q', 'S', 'E'}};
    findWords(boggle, root);
}