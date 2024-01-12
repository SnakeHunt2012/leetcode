class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        bitmap_str_dict = dict()
        for item in strs:
            bitmap = [0] * 26
            for char in item:
                bitmap[ord(char) - ord('a')] += 1
            bitmap = tuple(bitmap)
            if bitmap not in bitmap_str_dict:
                bitmap_str_dict[bitmap] = []
            bitmap_str_dict[bitmap].append(item)

        return list(bitmap_str_dict.values())
