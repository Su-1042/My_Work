from wordcloud import WordCloud
import matplotlib.pyplot as plt

with open('stopwords.txt', 'r') as f:
    stop_words = set(f.read().split())

with open('sh.txt', 'r') as f:
    text = f.read()

# removing all the punctuations before removing the stopwords (all basic punctuations have been removed) some might still be left which might affect the wordcount
# also all the words are being converted to the lower case so that it is easy to count them
words = text.replace(',', '').lower().replace('.', '').replace('\n', '').replace('=', '').replace('!', '').replace('--', '').replace('?', '').replace('-', '').replace('"', '').replace('\'', '').replace(';', '').split()

filtered_words = [word for word in words if word.lower() not in stop_words]
filtered_text = ' '.join(filtered_words)

counts = {}
for i in range(len(filtered_words)):
    if filtered_words[i] in counts:
        counts[filtered_words[i]] += 1
    else:
        counts[filtered_words[i]] = 1

# now we will create a word cloud
wordcloud = WordCloud(width=800, height=800, background_color='white').generate_from_frequencies(counts)

# overwriting the text in sh.txt with the filtered text 
with open('sh.txt', 'w') as f:
    f.write(filtered_text)


max_count = max(counts.values())
most_common_words = []
for word, count in counts.items():
    if count == max_count:
        most_common_words.append(word)

print(f"The word(s) with the highest frequency is/are: {', '.join(most_common_words)}")

total_length = 0
for word in filtered_words:
    total_length += len(word)
average_length = total_length / len(filtered_words)
print("Average word length after the word file is filtered is:", average_length)

# plotting the word cloud
plt.figure(figsize=(8,8))
plt.imshow(wordcloud)
plt.axis('off')
plt.show()


