

path = None

def foo(doit):
    global path
    if doit:
        from os import path
    
    print('foo', path)
    
foo(False)
foo(True)
foo(False)