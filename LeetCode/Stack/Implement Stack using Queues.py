class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue_1 = []
        self.queue_2 = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue_1.append(x)

        
    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        for _ in range(len(self.queue_1) - 1):
            self.queue_2.append(self.queue_1.pop(0))
        val = self.queue_1.pop(0)
        for _ in range(len(self.queue_2)):
            self.queue_1.append(self.queue_2.pop(0))
        return val
    
    
    def top(self) -> int:
        """
        Get the top element.
        """
        for _ in range(len(self.queue_1) - 1):
            self.queue_2.append(self.queue_1.pop(0))
        val = self.queue_1[0]
        self.queue_2.append(self.queue_1.pop(0))
        
        for _ in range(len(self.queue_2)):
            self.queue_1.append(self.queue_2.pop(0))
        return val
    
    
    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return True if not self.queue_1 else False
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
