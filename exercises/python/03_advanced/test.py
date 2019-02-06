__all__ = ['MyRange','my_range']

class MyRange():
    
    def __init__(self,start,stop,step=1):
        self.range=range(start,stop,step)

def my_range(*args):
    n=len(args)
    if n not in (1,2,3):
        raise TypeError("argument given" +str(n)+ "cannot be start,stop,step")
    if n==1:
        return MyRange(0,args[0]).range
    if n==2:
        return MyRange(args[0],args[1]).range
    if n==3:
        return MyRange(args[0],args[1],args[2]).range
    
    

import unittest
class TestMyModule(unittest.TestCase):
    def test1(self):
        self.assertEqual([i for i in my_range(1,10,5)], [i for i in range(1,10,5)])
      
    def test2(self):
        self.assertEqual([i for i in my_range(1,10)], [i for i in range(1,10)])
    
    
    def test3(self):
        self.assertEqual([i for i in my_range(100)], [i for i in range(100)])
            
if __name__ == '__main__':
    unittest.main()

