import requests
from bs4 import BeautifulSoup
import pandas as pd

products = []
prices = []
ratings = []
content = requests.get("https://www.flipkart.com/laptops/~buybac+k-guarantee-on-laptops-/pr?sid=6bo%2Cb5g&uniq")
response = content.content
# content = driver.page_source
soup = BeautifulSoup(response,"html.parser")
for a  in soup.findAll('a',href=True,attrs={'class':'_31qSD5'}):
    name = a.find('div',attrs={'class':'_3wU53n'})
    price = a.find('div',attrs={'class':'_1vC4OE _2rQ-NK'})
    rating = a.find('div',attrs={'class':'hGSR34'})
    products.append(name.text)
    prices.append(price.text)
    ratings.append(rating.text)
df = pd.DataFrame({'Product Name':products, 'Price':prices,'Ratings':ratings})
df.to_csv('flipkart.csv')
print(df)
