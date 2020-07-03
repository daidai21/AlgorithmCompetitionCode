# column_key should using OrderDict
# Your submission beats 29.67% Submissions!
# Total runtime 1573 ms


"""
Definition of Column:
class Column:
    def __init__(self, key, value):
        self.key = key
        self.value = value
"""


class MiniCassandra:

    def __init__(self):
        # do intialization if necessary
        self.dic = {}

    """
    @param: row_key: a string
    @param: column_key: An integer
    @param: value: a string
    @return: nothing
    """
    def insert(self, row_key, column_key, value):
        # write your code here
        if row_key in self.dic:
            for item in self.dic[row_key]:
                if item[0] == column_key:
                    self.dic[row_key].remove(item)
                    break
            self.dic[row_key].append(tuple((column_key, str(value))))
        else:
            self.dic[row_key] = [tuple((column_key, str(value)))]

    """
    @param: row_key: a string
    @param: column_start: An integer
    @param: column_end: An integer
    @return: a list of Columns
    """
    def query(self, row_key, column_start, column_end):
        # write your code here
        if row_key not in self.dic:
            return []
        result = []
        for item in self.dic[row_key]:
            if column_start <= item[0] <= column_end:
                result.append(Column(item[0], item[1]))
        result.sort(key=lambda x: x.key)
        return result
