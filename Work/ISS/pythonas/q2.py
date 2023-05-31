import pandas as pd

df = pd.read_csv('q1text.csv')
df = df.sort_values(by=['IMDB Rating', 'Runtime'], ascending=[False, True]).reset_index(drop=False)
top_100 = df.head(100)

print('Top 100 Movies by IMDB Rating:')
for i, row in top_100.iterrows():
    print(f'{i+1}. {row["Title"]}')

while True:
    print('\nFilter options:')
    print('1. Duration')
    print('2. IMDB Rating')
    print('3. Year of Release')
    print('4. Genre')
    print('5. Exit')
    choice = input('\nEnter your choice (1-5): ')

    if choice == '1':
        duration_min = int(input('Enter minimum duration (in minutes): '))
        duration_max = int(input('Enter maximum duration (in minutes): '))
        filtered = df[(df['Runtime'] >= duration_min) & (df['Runtime'] <= duration_max)].reset_index(drop=False)
        print(f'Top movies with duration between {duration_min} and {duration_max} minutes:')
        for i, row in filtered.iterrows():
            print(f'{i+1}. {row["Title"]}')
    
    elif choice == '2':
        rating_min = float(input('Enter minimum IMDB rating: '))
        rating_max = float(input('Enter maximum IMDB rating: '))
        filtered = df[(df['IMDB Rating'] >= rating_min) & (df['IMDB Rating'] <= rating_max)].reset_index(drop=False)
        print(f'Top movies with IMDB rating between {rating_min} and {rating_max}:')
        for i, row in filtered.iterrows():
            print(f'{i+1}. {row["Title"]}')
    
    elif choice == '3':
        year_min = int(input('Enter minimum year of release: '))
        year_max = int(input('Enter maximum year of release: '))
        filtered = df[(df['Year'] >= year_min) & (df['Year'] <= year_max)].reset_index(drop=False)
        print(f'Top movies with year of release between {year_min} and {year_max}:')
        for i, row in filtered.iterrows():
            print(f'{i+1}. {row["Title"]}')
    
    elif choice == '4':
        genre = input('Enter a genre: ')
        filtered = df[df['Genre'].apply(lambda x: genre in x)].reset_index(drop=False)
        print(f'Top movies in the {genre} genre:')
        for i, row in filtered.iterrows():
          print(f'{i+1}. {row["Title"]}')
    
    
    elif choice == '5':
        exit()

