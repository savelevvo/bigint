#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys
import random

EXE_PATH = "D:\Projects\cpp\BigNumbers\Debug\BigNumbers.exe"

if (len(sys.argv) == 2):
    ITERATORS_COUNT = int(sys.argv[1])
    for i in range(ITERATORS_COUNT):
        lhs = str(random.randint(0, 10000))
        rhs = str(random.randint(0, 10000))
        os.system(EXE_PATH + " " + rhs + " " + rhs)
elif (len(sys.argv) == 3):
    os.system(EXE_PATH + " " + sys.argv[1] + " " + sys.argv[2])
else:
    sys.exit(u"Format error!\n")

print u"Success!\n"
