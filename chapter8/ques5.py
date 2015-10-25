"""
@Question:

    Given n pairs of parentheses, write a function to generate
    all combinations of well-formed parentheses.
    For example, given n = 3, a solution set is:
    "((()))", "(()())", "(())()", "()(())", "()()()"
"""

class Solution(object):
    def _generate(self, deep, num, string, result):
        if deep == num:
            if string not in result:
                result.append(string)
            return
        if "" == string:
            self._generate(deep+1, num, "()", result)
            return
        for i in range(0, len(string)+1):
            self._generate(deep+1, num, string[0:i]+"()"+string[i:], result)
            
    def generateParenthesis(self, n):

        """
        :type n: int
        :rtype: List[str]
        """
        result = []
        self._generate(0, n, "", result)
        return result
        

if __name__ == "__main__":
    s = Solution()
    result = s.generateParenthesis(4)
    print result
    print len(result)
