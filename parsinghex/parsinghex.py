import sys
import re

for line in sys.stdin.readlines():
    for _hex in re.findall('(?:0x|0X)[0-9a-fA-F]+', line):
        n = int(_hex, 16)
        print _hex, n

