class Stack :
    def __init__(self, MAX_ITEMS = 10) :
        self.items = []
        self.MAX_ITEMS = MAX_ITEMS

    def IsEmpty(self) :
        if(len(self.items) == 0) :
            return True
        else : 
            return False
      
    def IsFull(self) :
        if(len(self.items) == self.MAX_ITEMS) :
            return True
        else : return False
      
    def Push(self, item) :
        if(self.IsFull() == False) :
            self.items.append(item)

    def Pop(self) :
        self.items.pop()

    def Top(self) :
        return self.items[-1]
    
if __name__ == '__main__' :
    stack = Stack(5)
    print(stack.items)
    print(stack.IsEmpty())
    stack.Push(1)
    stack.Push(2)
    stack.Push(3)
    print(stack.IsFull())
    stack.Push(4)
    stack.Push(5)
    print(stack.items)
    print(stack.IsFull())
    stack.Push(6)
    print(stack.items)
    stack.Pop()
    stack.Push(6)
    print(stack.Top())
