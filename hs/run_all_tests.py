#!/usr/bin/python

import os

def test(f):
    p = os.getcwd()
    os.chdir(f)
    hss = list(filter(lambda f: f.endswith('.hs'), os.listdir('.')))
    if hss:
        os.system('~/workspace/algolib/util/checksol.py %s.hs -e runghc' % f)
    os.chdir(p)

def run():
    print(os.getcwd())
    for f in os.listdir('.'):
        if os.path.isdir(f):
            test(f)

if __name__ == '__main__':
    run()
