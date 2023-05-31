#!/bin/bash

touch temp.txt
# Create an associative array to hold the groups of words
declare -A word_groups

# Read the input file line by line
while read -r line; do
  # Count the number of vowels in the line
  num_vowels=$(echo "$line" | tr -cd 'aeiouAEIOU' | wc -m)

  # Add the line to the corresponding group in the array
  if [[ -z ${word_groups[$num_vowels]} ]]; then
    word_groups[$num_vowels]="$line"
  else
    word_groups[$num_vowels]="${word_groups[$num_vowels]} $line"
  fi
done < $1

# Sort the groups alphabetically by their keys (number of vowels)
for key in "${!word_groups[@]}"; do
  sorted_groups["$key"]=$(echo "${word_groups[$key]}" | tr ' ' '\n' | sort)
done

# Write the sorted groups to the output file
for key in $(echo "${!sorted_groups[@]}" | tr ' ' '\n' | sort ); do
  echo "${sorted_groups[$key]}" >> temp.txt
  echo >> temp.txt
done


tail -n +5 temp.txt >> $2

rm temp.txt


