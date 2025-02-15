#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    // Each Trie Node contains a Map 'child'
    // where each alphabet points to a Trie
    // Node.
    // We can also use a fixed size array of
    // size 256.
    unordered_map<char, TrieNode *> child;

    // 'isLast' is true if the node represents
    // end of a contact
    bool isLast;

    // Default Constructor
    TrieNode()
    {
        // Initialize all the Trie nodes with NULL
        for (char i = 'a'; i <= 'z'; i++)
            child[i] = NULL;

        isLast = false;
    }
};

// Making root NULL for ease so that it doesn't
// have to be passed to all functions.
TrieNode *root = NULL;

// Insert a Contact into the Trie
void insert(string s)
{
    int len = s.length();

    // 'itr' is used to iterate the Trie Nodes
    TrieNode *itr = root;
    for (int i = 0; i < len; i++)
    {
        // Check if the s[i] is already present in
        // Trie
        TrieNode *nextNode = itr->child[s[i]];
        if (nextNode == NULL)
        {
            // If not found then create a new TrieNode
            nextNode = new TrieNode();

            // Insert into the Map
            itr->child[s[i]] = nextNode;
        }

        // Move the iterator('itr') ,to point to next
        // Trie Node
        itr = nextNode;

        // If its the last character of the string 's'
        // then mark 'isLast' as true
        if (i == len - 1)
            itr->isLast = true;
    }
}

// This function simply displays all dictionary words
// going through current node. String 'prefix'
// represents string corresponding to the path from
// root to curNode.
void displayContactsUtil(TrieNode *curNode, string prefix)
{
    // Check if the string 'prefix' ends at this Node
    // If yes then display the string found so far
    if (curNode->isLast)
        cout << prefix << endl;

    // Find all the adjacent Nodes to the current
    // Node and then call the function recursively
    // This is similar to performing DFS on a graph
    for (char i = 'a'; i <= 'z'; i++)
    {
        TrieNode *nextNode = curNode->child[i];
        if (nextNode != NULL)
            displayContactsUtil(nextNode, prefix + (char)i);
    }
}

// Display suggestions after every character enter by
// the user for a given query string 'str'
void displayContacts(string str)
{
    TrieNode *prevNode = root;

    string prefix = "";
    int len = str.length();

    // Display the contact List for string formed
    // after entering every character
    int i;
    for (i = 0; i < len; i++)
    {
        // 'prefix' stores the string formed so far
        prefix += (char)str[i];

        // Get the last character entered
        char lastChar = prefix[i];

        // Find the Node corresponding to the last
        // character of 'prefix' which is pointed by
        // prevNode of the Trie
        TrieNode *curNode = prevNode->child[lastChar];

        // If nothing found, then break the loop as
        // no more prefixes are going to be present.
        if (curNode == NULL)
        {
            cout << "nNo Results Found for "
                    " << prefix 
                 << "" n "; 
                i++;
            break;
        }

        // If present in trie then display all
        // the contacts with given prefix.
        cout << "nSuggestions based on "
                " << prefix 
             << "" are n "; 
            displayContactsUtil(curNode, prefix);

        // Change prevNode for next prefix
        prevNode = curNode;
    }

    // Once search fails for a prefix, we print
    // "Not Results Found" for all remaining
    // characters of current query string "str".
    for (; i < len; i++)
    {
        prefix += (char)str[i];
        cout << "nNo Results Found for "
                " << prefix 
             << "" n "; 
    }
}

// Insert all the Contacts into the Trie
void insertIntoTrie(string contacts[], int n)
{
    // Initialize root Node
    root = new TrieNode();

    // Insert each contact into the trie
    for (int i = 0; i < n; i++)
        insert(contacts[i]);
}

// Driver program to test above functions
int main()
{
    // Contact list of the User
    string contacts[] = {"gforgeeks", "geeksquiz"};

    // Size of the Contact List
    int n = sizeof(contacts) / sizeof(string);

    // Insert all the Contacts into Trie
    insertIntoTrie(contacts, n);

    string query = "gekk";

    // Note that the user will enter 'g' then 'e', so
    // first display all the strings with prefix as 'g'
    // and then all the strings with prefix as 'ge'
    displayContacts(query);

    return 0;
}