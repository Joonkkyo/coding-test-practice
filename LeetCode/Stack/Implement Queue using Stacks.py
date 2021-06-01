class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack_1 = []
        self.stack_2 = []
        

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stack_1.append(x)

        
    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        for _ in range(len(self.stack_1)):
            self.stack_2.append(self.stack_1.pop())
        val = self.stack_2.pop()
        
        while self.stack_2:
            self.stack_1.append(self.stack_2.pop())
        return val
            
    def peek(self) -> int:
        """
        Get the front element.
        """
        for _ in range(len(self.stack_1)):
            self.stack_2.append(self.stack_1.pop())
        val = self.stack_2[-1]
        
        while self.stack_2:
            self.stack_1.append(self.stack_2.pop())
            
        return val

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not self.stack_1
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
