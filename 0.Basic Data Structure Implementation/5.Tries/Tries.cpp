#include<bits/stdc++.h>
#include "Tries.h"

using namespace std;

int main()
{
    Trie t1;
    t1.insertWord("are");
    t1.insertWord("and");
    t1.insertWord("not");

    cout <<t1.searchWord("and")<<endl;

    t1.removeWord("and");

    cout <<t1.searchWord("and")<<endl;


}
