#!/bin/bash

#1
cal > output1.txt

#2
date +"%F" >> output1.txt
#saw this from the manual

#3
for (( i=0; i<100 ;i++ ))
do
echo "ISS is cool">> output1.txt
done

#4
cat output1.txt

#5 
head -3 output1.txt | tail +1

#6
head -15 output1.txt | tail +6

#7
cat output1.txt | wc -l

#8
echo "I'm UG1">> output1.txt

#9
cat output1.txt | wc -w

#10
echo "I'm studying ISS">> output1.txt

#11
awk '{print $4}' output1.txt

#12
awk '{ for (i = 2; i <= 5; ++i) printf $i" "; print ""}' output1.txt

#13
awk 'NR >= 0 && NR <= 106 { print $3 }' output1.txt

#14
awk '{print $2 " " $4}' output1.txt

