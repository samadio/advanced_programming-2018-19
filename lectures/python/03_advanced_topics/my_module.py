__all__ = ['my_sum', 'Point'] #__all__ does not contain the tests, so that import * does not use tests

def my_sum(a,b):
    return a+b

class Point:
    def __init__(self,x,y):
        self.x = x
        self.y = y

    def __abs__(self):
        import math
        return math.hypot(self.x,self.y)


import unittest
class TestMyModule(unittest.TestCase): #some class which will contain all the tests that will inherit from unittest.TestCase
    def test_my_sum(self):
        self.assertEqual(my_sum(3,4), 7)

    def test_point_ctor(self):
        p = Point(3,4)
        self.assertEqual(p.x,3)
        self.assertEqual(p.y,4)

    def test_point_abs(self):
        p = Point(3,4)
        self.assertEqual(abs(p),5)
        
if __name__ == '__main__': #Se faccio girare il modulo da solo, non come importato, fai i test. Se viene importato NO
    unittest.main()

    
#U have to import as usually, but when u run it you have to modify the name of  SEARCH ON THE INTERNET