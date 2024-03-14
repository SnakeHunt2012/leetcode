class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        status_dict = dict([(i, 0) for i in range(numCourses)])
        prerequisity_dict = dict((i, []) for i in range(numCourses))
        for prerequisity in prerequisites:
            from_course, to_course = prerequisity
            prerequisity_dict[from_course].append(to_course)

        def dfs(course):
            if status_dict[course] == 2:
                return True
            if status_dict[course] == 1:
                return False

            status_dict[course] = 1
            for prerequisity in prerequisity_dict[course]:
                if dfs(prerequisity):
                    continue
                else:
                    return False
            status_dict[course] = 2
            return True

        for i in range(numCourses):
            if status_dict[i] == 2:
                continue
            if dfs(i):
                continue
            else:
                return False

        return True
