#!/usr/bin/python

import os

def test(f):
    p = os.getcwd()
    os.chdir(f)
    cpps = list(filter(lambda f: f.endswith('.cpp'), os.listdir('.')))
    if cpps:
        compile_command = 'clang++ -O2 -std=c++11 -o %s ' % f
        os.system(compile_command + ' '.join(cpps))
        os.system('~/workspace/algolib/util/checksol.py %s' % f)
        os.remove(f)
    os.chdir(p)

def run():
    for f in os.listdir('.'):
        if os.path.isdir(f):
            test(f)

if __name__ == '__main__':
    run()
