#!/bin/bash

grep -E ^[aeiou] words.txt | grep -v 'a$' | grep -v 'e$' | grep -v 'i$' | grep -v 'o$' | grep -v 'u$' >> output_3.txt