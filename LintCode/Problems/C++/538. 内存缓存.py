INT_MAX = 0x7fffffff


class Resource:
    def __init__(self, value, expired):
        self.value   = value
        self.expired = expired


class Memcache:
    def __init__(self):
        # do intialization if necessary
        self.cache = {}

    """
    @param: curtTime: An integer
    @param: key: An integer
    @return: An integer
    """
    def get(self, curtTime, key):
        # write your code here
        if key not in self.cache:
            return INT_MAX
        result = self.cache.get(key)
        if result.expired >= curtTime or result.expired == -1:
            return result.value
        else:
            return INT_MAX

    """
    @param: curtTime: An integer
    @param: key: An integer
    @param: value: An integer
    @param: ttl: An integer
    @return: nothing
    """
    def set(self, curtTime, key, value, ttl):
        # write your code here
        self.cache[key] = Resource(value, curtTime + ttl - 1 if ttl else -1)

    """
    @param: curtTime: An integer
    @param: key: An integer
    @return: nothing
    """
    def delete(self, curtTime, key):
        # write your code here
        if key in self.cache:
            del self.cache[key]

    """
    @param: curtTime: An integer
    @param: key: An integer
    @param: delta: An integer
    @return: An integer
    """
    def incr(self, curtTime, key, delta):
        # write your code here
        if self.get(curtTime, key) == INT_MAX:
            return INT_MAX
        self.cache[key].value += delta
        return self.cache[key].value

    """
    @param: curtTime: An integer
    @param: key: An integer
    @param: delta: An integer
    @return: An integer
    """
    def decr(self, curtTime, key, delta):
        # write your code here
        if self.get(curtTime, key) == INT_MAX:
            return INT_MAX
        self.cache[key].value -= delta
        return self.cache[key].value
