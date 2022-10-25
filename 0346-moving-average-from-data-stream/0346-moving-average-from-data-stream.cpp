class MovingAverage(object):

    def __init__(self, size):
        """
        :type size: int
        """
        self.window = collections.deque()
        self.maxsize = size
        self.total = 0

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        self.window.append(val)
        self.total += val
        
        if len(self.window) > self.maxsize:
            popped = self.window.popleft()
            self.total -= popped
        
        return float(self.total)/len(self.window)
        


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)