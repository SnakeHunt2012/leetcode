class Solution(object):
    
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        label_dict = {} # {word:label}
        word_list = str.split()
    
        if len(pattern) != len(word_list):
            return False
    
        if len(set(pattern)) != len(set(word_list)):
            return False
        
        for label, word in zip(pattern, word_list):
            if word in label_dict:
                if label != label_dict[word]:
                    return False
                else:
                    continue
            else:
                label_dict[word] = label

        return True
