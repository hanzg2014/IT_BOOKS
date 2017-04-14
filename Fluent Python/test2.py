#coding:utf8
#!/usr/bin/python

import re

birth = raw_input('birth: ')
print isinstance(birth, str)
if birth < 2000:
    print '00前'
else:
    print '00后'

classmates = ['Michael', 'Bob', 'Tracy']
classmates.insert(1, 'Jack')
print classmates

classmates.pop(1)
print classmates

classmates[1] = 'Sarah'
print classmates

t = (1,)
print t

print len(u'中文') #2
print len('中文') #6
print u'中文'.encode("utf-8").decode("utf-8")
print 'Hi, %s, you have $%d.' % ('Michael', 1000000)
print '%2d-%02d' % (3, 1) # 3-01
print '%.2f' % 3.1415926 #3.14
print u'Hi, %s' % u'Michael'
print 'growth rate: %d %%' % 7

PI = 3.14159
print PI


d = {'Michael': 95, 'Bob': 75, 'Tracy': 85}
print 'Michael' in d
print d.get('Micael')
print d.get('Micael', -1)
print d.pop('Michael')
print d

print cmp(1,2) #-1
 
print int(12.34) #12

print bool(1) #True

print bool(-1) #False


print bool(2) #True

a= abs #
print a (-1)

a = "string"

bs=[]
for s in a:
	bs.append(s)
print bs


re("( *)[+-]?(\\d+|\\d+\\.\\d*|\\d*\\.\\d+)([eE][+-]?[0-9]+)?", )

