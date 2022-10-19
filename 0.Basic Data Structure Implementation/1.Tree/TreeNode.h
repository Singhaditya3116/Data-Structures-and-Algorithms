#include<vector>
using namespace std;

template <typename T>
class TreeNode{
public:
    T data;
    vector<TreeNode*> children;
    //vector<TreeNode<T>*>children;

    TreeNode(int data)
    {
        this->data=data;
    }

    ~TreeNode()  //Destructor
    {

    }
};
