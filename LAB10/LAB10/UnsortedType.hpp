#ifndef UnsortedType_hpp
#define UnsortedType_hpp

template<class ItemType>
struct NodeType_;

template<class ItemType>
class UnsortedType
{
public :
    UnsortedType();
    ~UnsortedType();
    void MakeEmpty();
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    bool IsFull();
    int LengthIs();
    void RetrieveItem(ItemType& item, bool& found);
    void ResetList();
    void GetNextItem(ItemType& item);
private :
    NodeType_<ItemType>* listData;
    int length;
    NodeType_<ItemType>* currentPos;
};

template<class ItemType>
struct NodeType_
{
    ItemType info;
    NodeType_* next;
};

#endif /* UnsortedType_hpp */

