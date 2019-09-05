
import requests
import pandas as pd
from bs4 import BeautifulSoup

# creating empty list to store contents
products = []
prices = []
ratings = []

content = requests.get("https://www.amazon.in/s/ref=mega_elec_s23_2_1_1_1?rh=i%3Acomputers%2Cn%3A1375424031&ie=UTF8&bbn=976392031",headers={'User-agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:61.0) Gecko/20100101 Firefox/61.0'}) #retrieve contents from the webpage URL

soup = BeautifulSoup(content.content,"html.parser")
for a in soup.find_all('div',attrs={'class':'a-fixed-left-grid-inner'}):
    product = a.find('h2',attrs={'class':'a-size-medium s-inline s-access-title a-text-normal'})
    price = a.find('span',attrs={'class':'currencyINR'}) 
    rating = a.find('span',attrs={'class':'a-icon-alt'})
    products.append(product.text)
    prices.append(price.text)
    ratings.append(rating.text)
df = pd.DataFrame({"Product Name":products,"Price":prices,"Rate":ratings})
df.to_csv("amazon.csv")




