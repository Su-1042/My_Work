# Import the necessary libraries
import requests
from bs4 import BeautifulSoup
import matplotlib.pyplot as plt
import pandas as pd
import copy

titles = []
years = []
genres = []
runtimes = []
grosses = []
imdbratings = []

# Make a request to the IMDB website
for i in range(1, 11):
    url = "https://www.imdb.com/list/ls098063263/?st_dt=&mode=detail&page=" + \
        str(i)+"&sort=list_order,asc"
    html = requests.get(url).text
    soup = BeautifulSoup(html, 'lxml')

    # Find all the movie titles, years of release, worldwide gross values, IMDB ratings, genres, and runtimes on the page
    movies = soup.find_all('div', class_='lister-item-content')
    flag = 0
    for movie in movies:
        # Extract the movie title
        title = movie.h3.a.text

        if (title == 'The Lion King' and flag == 0):
            title = 'The Lion King 1'
            flag = 1
        if (title == 'The Lion King' and flag == 1):
            title = 'The Lion King 2'
        titles.append(title)

        # Extract the year of release
        year = movie.h3.find('span', class_='lister-item-year').text
        years.append(year)

        # Extract the genre(s)
        gen = movie.find('span', class_='genre').text.replace(
            ' ', '').replace('"', '').replace('\n', '').split(',')
        genres.append(gen)

        # Extract the runtime
        time = movie.find('span', class_='runtime').text
        runtimes.append(int(time.replace(' min', '')))

        rating = movie.find('div', class_='ipl-rating-star small').find('span',
                                                                        class_='ipl-rating-star__rating').text
        imdbratings.append(rating)


for i in range(1, 11):
    url = "https://www.imdb.com/list/ls098063263/?st_dt=&mode=detail&page=" + \
        str(i)+"&sort=list_order,asc"
    html = requests.get(url).text
    soup = BeautifulSoup(html, 'lxml')

    moviehtml = soup.find_all('div', class_='lister-item mode-detail')
    for movie in moviehtml:
        gross_element = movie.find_all(
            'div', class_='list-description')[-1].find('p').find('b')
        gross = gross_element.text.strip('$')
        gross = gross.replace(',', '')
        grosses.append(gross)

# Create a pandas DataFrame with the extracted data
genre_counts = {}

for i, genre_list in enumerate(genres):
    for genre in genre_list:
        if genre not in genre_counts:
            genre_counts[genre] = [0] * len(titles)
        genre_counts[genre][i] += 1

data = {'Title': titles, 'Year': years, 'Runtime': runtimes,
        'Genre': genres, 'IMDB Rating': imdbratings, 'Grosses': grosses}
df = pd.DataFrame(data)
df.to_csv('q1txt.csv', index=False, lineterminator='\n\n')


tempdf = copy.deepcopy(df)
top_100 = tempdf.head(100)
top_100 = top_100.sort_values(by='Grosses', ascending=False)
# print(top_100)
plt.plot(top_100['Title'], top_100['Grosses'])
plt.xticks(rotation=90)
plt.title('Top 100 Movies by Gross')
plt.xlabel('Movie Title')
plt.ylabel('Gross (in millions)')
# plt.set_yscale('linear')
plt.tick_params(axis='x', pad=10)  # Increase the distance of x-axis tick labels from the x-axis
plt.tick_params(axis='y', pad=10)  # Increase the distance of y-axis tick labels from the y-axis
plt.show()

# Add a new column to the DataFrame with the frequencies of each genre
for genre, counts in genre_counts.items():
    df[genre] = counts

# using a csv file to save data of all the movies
df.to_csv('q1text.csv', index=False, lineterminator='\n\n')


# Get the total count of movies for each genre
genre_totals = df.loc[:, 'Action':'Documentary'].sum()

# Create a bar graph of the genre counts
genre_totals.plot.bar()
plt.title('Frequency of movies by genre')
plt.xlabel('Genre')
plt.ylabel('Number of movies')
plt.show()


# df = df.sort_values(by=['Grosses'], ascending=False)

# Create a line graph of the top 100 movies and their gross values
