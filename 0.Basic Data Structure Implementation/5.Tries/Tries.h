#include<string>
#include "TrieNode.h"
using namespace std;

class Trie{

    TrieNode *root;

public:
    Trie()
    {
        root=new TrieNode('/0');
    }

private:

    void insertWord(TrieNode *root,string word)
    {
        //Base case
        if(word.size() == 0) //word has been inserted
        {
            root->isTerminal=true;
            return;
        }

        //Small Calculation
        int index=word[0]-97;
        TrieNode *child;
        if(root->children[index] == NULL)
        {
            TrieNode *newNode = new TrieNode(word[0]);
            root->children[index]=newNode;
            child=root->children[index];
        }
        else
        {
            child=root->children[index];
        }

        //Recursive Call
        insertWord(child,word.substr(1));
    }

public:

    void insertWord(string word)
    {
        insertWord(root,word);
    }
private:

    bool searchWord(TrieNode *root,string word)
    {
        //Base Case
        if(word.size() == 0)
        {
            if(root -> isTerminal == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int index = word[0]-97;
        if(root->children[index] == NULL)
        {
            return false;
        }
        else
        {
            bool solve = searchWord(root->children[index],word.substr(1));
            return solve;
        }
    }

public:

    bool searchWord(string word)
    {
        return searchWord(root,word);
    }

private:
    bool isChildrenNull(TrieNode **Array)
    {
        for(int i=0;i<26;i++)
        {
            if(Array[i] != NULL)
            {
                return false;
            }
        }
        return true;
    }

    void removeWord(TrieNode *root,string word)
    {
        //Base Case
        if(word.size() == 0)
        {
            root->isTerminal=false;
            return;
        }

        int index = word[0]-97;
        if( root ->children[index] == NULL)
        {
            return;
        }
        else
        {
            TrieNode *child=root->children[index];
            removeWord(child,word.substr(1));
            if(child->isTerminal == false && isChildrenNull(child->children) == true) //deleting Node.
            {
                delete child;
                root->children[index]=NULL;
            }

            return;
        }
    }

public:

    void removeWord(string word)
    {
        removeWord(root,word);
    }

};
