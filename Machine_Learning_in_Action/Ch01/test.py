#! /tools/cfr/bin/python
# -*- coding: utf-8 -*-

from numpy import *
print random.rand(4,4)
randMat = mat(random.rand(4,4))
print randMat
print randMat.I
myEye = randMat*randMat.I
print eye(4)

