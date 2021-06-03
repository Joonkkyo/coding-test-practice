from collections import deque

class MyCircularDeque:

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        """
        self.maxlen = k
        self.dq = deque(maxlen=k)

        
    def insertFront(self, value: int) -> bool:
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        """
        if len(self.dq) == self.maxlen: return False
        else: 
            self.dq.appendleft(value)
            return True
        

    def insertLast(self, value: int) -> bool:
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        """
        if len(self.dq) == self.maxlen: return False
        else:
            self.dq.append(value)
            return True

        
    def deleteFront(self) -> bool:
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        """
        if not self.dq: return False
        else:
            self.dq.popleft()
            return True
        

    def deleteLast(self) -> bool:
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        """
        if not self.dq: return False
        else:
            self.dq.pop()
            return True

        
    def getFront(self) -> int:
        """
        Get the front item from the deque.
        """
        if self.dq: return self.dq[0]
        else: return -1
        

    def getRear(self) -> int:
        """
        Get the last item from the deque.
        """
        if self.dq: return self.dq[-1]
        else: return -1
        

    def isEmpty(self) -> bool:
        """
        Checks whether the circular deque is empty or not.
        """
        if not self.dq: return True
        else: return False
        

    def isFull(self) -> bool:
        """
        Checks whether the circular deque is full or not.
        """
        if len(self.dq) == self.maxlen: return True
        else: return False
        


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
