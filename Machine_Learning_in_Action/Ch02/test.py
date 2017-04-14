#! /tools/cfr/bin/python
# -*- coding: utf-8 -*-

from numpy import *
import kNN
import matplotlib
import matplotlib.pyplot as plt


##########Ch01#########
if(False):
	print random.rand(4,4)
	randMat = mat(random.rand(4,4))
	print randMat
	print randMat.I
	myEye = randMat*randMat.I
	print eye(4)

	zero = zeros((3,3))
	print zeros
	line = "	show my the	money  "
	print line
	line = line.strip()
	print line
	line = line.split()	
	print line  

	print zero[1,]
##########Ch02###########
datingDataMat,datingLabels = kNN.file2matrix('datingTestSet2.txt')


if(False):
	print datingDataMat
	print datingLabels[0:20]

	fig = plt.figure()
	ax = fig.add_subplot(111)
	ax.scatter(datingDataMat[:,1], datingDataMat[:,2], 15.0*array(datingLabels), 15.0*array(datingLabels))
	plt.show()

	normMat, ranges, minVals = kNN.autoNorm(datingDataMat)
	print normMat
	print ranges
	print minVals

	kNN.datingClassTest()
	kNN.classifyPerson()
	testVector = kNN.img2vector('digits/testDigits/0_13.txt')
	print testVector[0,0:31]
	print testVector[0,32:63]

kNN.handwritingClassTest()