#ifndef TreeType_hpp
#define TreeType_hpp
#include <string>
#include <fstream>

typedef char ItemType;
struct TreeNode;

#include "QueType.hpp"

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};
class TreeType
{
public:
    TreeType();                     // constructor
    ~TreeType();                    // destructor
    TreeType(const TreeType& originalTree);
    void operator=(const TreeType& originalTree);
    // copy constructor
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    int LengthIs() const;
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetTree(OrderType order);
    void GetNextItem (ItemType& item, OrderType order,
                      bool& finished);
    void Print(std::ofstream& outFile) const;
    // Recursive version
    TreeNode* PtrToSuccessor_A(TreeNode* &tree);
    // Non-recursive version
    TreeNode* PtrToSuccessor_B(TreeNode* tree);
    // Return true if the tree is BST else false
    bool IsBST();
    int LeafCount();
    int SingleParentCount();
    
private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

#endif /* TreeType_hpp */
