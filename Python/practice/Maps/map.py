import pandas
import folium
import os
from geopy import ArcGIS
nom=ArcGIS()
data = pandas.read_csv("practice/Volcanoes.txt")
lat = list(data["LAT"])
lng = list(data["LON"])
elv = list(data["ELEV"])
def color(elevation):
    if elevation < 1000:
        return 'green'
    elif 1000 <= elevation < 3000:
        return 'orange'
    else:
        return 'red'
map = folium.Map(location=[38.58, -99.09])
fgv = folium.FeatureGroup(name="Volcanoes")
for lt,ln,el in zip(lat,lng,elv):
    fgv.add_child(folium.CircleMarker(location=[lt,ln],radius = 6,popup= str(el)+" m",fill_color=color(el),fille=True,color='grey',opacity=1))
fgp = folium.FeatureGroup(name="Population")
fgp.add_child(folium.GeoJson(data=(open('practice/world.json','r',encoding='utf-8-sig')).read(),
style_function= lambda x :{'fillColor':'green' if x['properties']['POP2005']<10000000 else 'orange' if 10000000<=x['properties']['POP2005']<20000000 else 'red'}))
map.add_child(fgv)
map.add_child(fgp)
map.add_child(folium.LayerControl())
map.save("practice/MAPS.html")
