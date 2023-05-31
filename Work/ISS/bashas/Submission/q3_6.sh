#!/bin/bash

grep -E '^[[:alpha:]]+$' words.txt | grep -E '(.).*\1' -v >> output_3.txt


    # grep -E '^[[:alpha:]]+$' file.txt: This command searches for lines that contain only alphabetic characters. The regular expression ^[[:alpha:]]+$ matches one or more alphabetic characters from the beginning (^) to the end ($) of the line.
    # grep -E '(.).*\1' -v: This command filters out lines that contain duplicate characters. The regular expression (.).*\1 matches any character (.) followed by zero or more characters (*) and then the same character again (\1). The -v option inverts the match, so it prints only lines that do not match the regular expression.
