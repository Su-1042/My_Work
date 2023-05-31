#!/bin/bash


grep 'a' words.txt | grep 'e' | grep -v 'i'  >> output_3.txt

#-v takes those patterns which doesnt have th pattern specified 