#!/bin/bash

grep -v 'j' $1>> $2

#grep -Eo does the work of putting each word in a separate line of the output file
