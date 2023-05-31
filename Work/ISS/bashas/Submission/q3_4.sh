#!/bin/bash

grep -E "\w*[aeiou][^aeiou\W][^aeiou\W][^aeiou\W][aeiou]\w*|^[^aeiou\W][^aeiou\W][^aeiou\W][aeiou\W]\w*|\b^[^aeiou\W][^aeiou\\W][^aeiou\W]\b|\w*[aeiou\W][^aeiou\W][^aeiou\W][^aeiou\W]$" words.txt >> output_3.txt

#4 cases 
#case 1 vcccv
#case 2 ^cccv
#case 3 vccc$
#case 4 ccc (3letter words)
