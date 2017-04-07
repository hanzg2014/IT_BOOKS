from urllib2 import urlopen
from bs4 import BeautifulSoup as bs
import pandas as pd
from lxml.html import parse

parsed = parse(urlopen('http://finance.yahoo.com/q/op?s=AAPL+Options'))
doc = parsed.getroot()

tables = doc.findall('.//table')

rows = doc.findall('.//tr')
print rows

def _unpack(row, kind='td'):
	elts = row.findall('.//%s' % kind)
	return [val.text_content() for val in elts]

print _unpack(rows, kind='th')