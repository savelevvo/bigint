#!/usr/bin/env python
# -*- coding: utf-8 -*-

from os import system
from sys import argv
from sys import exit
from random import randint

EXE_PATH = "D:\Projects\cpp\BigNumbers\Debug\BigNumbers.exe"
DISPLAY_DATA = False

if (len(argv) == 2):
    ITERATORS_COUNT = int(argv[1])
    for i in range(ITERATORS_COUNT):
        lhs = str(randint(-2000000, 2000000))
        rhs = str(randint(-2000000, 2000000))
        if (DISPLAY_DATA):
            print "x = %s, y = %s" % (lhs, rhs)
        system(EXE_PATH + " " + rhs + " " + rhs)
elif (len(argv) == 3):
    system(EXE_PATH + " " + argv[1] + " " + argv[2])
else:
    exit(u"Format error!\n")

print u"Done\n"
