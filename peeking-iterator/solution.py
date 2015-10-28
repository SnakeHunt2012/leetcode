# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator(object):
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """

class PeekingIterator(object):
        def __init__(self, iterator):
            """
            Initialize your data structure here.
            :type iterator: Iterator
            """
            self.iterator = iterator
            self.peek_flag = False
            self.peek_value = None
            
        def peek(self):
            """
            Returns the next element in the iteration without advancing the iterator.
            :rtype: int
            """
            if self.peek_flag:
                return self.peek_value
            
            if self.iterator.hasNext():
                self.peek_flag = True
                self.peek_value = self.iterator.next()
                return self.peek_value

        def next(self):
            """
            :rtype: int
            """
            if self.peek_flag:
                self.peek_flag = False
                return self.peek_value
            else:
                return self.iterator.next()
            
            
        def hasNext(self):
            """
            :rtype: bool
            """
            return self.peek_flag or self.iterator.hasNext()
            
            
# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
            
