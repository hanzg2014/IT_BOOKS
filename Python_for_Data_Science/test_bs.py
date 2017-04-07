import pandas as pd
from urllib2 import urlopen
from bs4 import BeautifulSoup as bs

soup = bs(urlopen('http://finance.yahoo.com/q/op?s=AAPL+Options'),'html.parser')
links = soup.find_all('a')
print links
