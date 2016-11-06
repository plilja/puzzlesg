#!/usr/bin/python

import os

def test(f):
    p = os.getcwd()
    os.chdir(f)
    pys = list(filter(lambda f: f.endswith('.py'), os.listdir('.')))
    if pys:
        os.system('~/workspace/algolib/util/checksol.py %s.py -e python2' % f)
    os.chdir(p)

def run():
    print(os.getcwd())
    for f in os.listdir('.'):
        if os.path.isdir(f):
            test(f)

if __name__ == '__main__':
    run()
