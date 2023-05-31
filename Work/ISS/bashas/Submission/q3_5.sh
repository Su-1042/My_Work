#!/bin/bash

# for word in `grep -E '^[a-z]{3,45}$' words.txt`
#     do [ $word == `echo $word | rev` ] && echo $word >> output_3.txt
# done


#!/bin/bash

# Read the filename from the command line argument


# Read the file line by line
while read -r line; do
  # Remove non-alphanumeric characters and convert to lowercase
  cleaned=$(echo "$line" | tr -dc '[:alnum:]' | tr '[:upper:]' '[:lower:]')
  # Reverse the string
  reversed=$(echo "$cleaned" | rev)
  # Check if the string is a palindrome
  if [[ "$cleaned" == "$reversed" ]]; then
    echo "$line" >> output_3.txt
  fi
done < words.txt



#This line begins a for loop that iterates over each word that matches the regular expression '^[a-z]{3,45}$' in the file words.txt. The regular expression matches strings of lowercase alphabetic characters that are between 3 and 45 characters long. The command grep -E '^[a-z]{3,45}$' words.txt searches the file for lines that match this pattern and outputs the matching words.
#This line checks if the current word is equal to its reverse. The expression [ $word == echo $word | rev ] evaluates to true if the word is equal to its reverse. The && operator is used to run the echo command only if the previous test succeeded. The echo command writes the current word to the file output_3.txt.