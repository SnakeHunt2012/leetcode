class Solution:
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):

        head = None
        tail = None
        range_list = []
        for i in nums:
            if head is None:
                head = i
                tail = i
            else:
                if (i - tail) == 1:
                    tail = i
                else:
                    range_list.append((head, tail))
                    head = i
                    tail = i
        if head is not None:
            range_list.append((head, tail))

        solution = []
        for range in range_list:
            if range[0] == range[1]:
                solution.append("%d" % range[0])
            else:
                solution.append("%d->%d" % range)
        return solution
