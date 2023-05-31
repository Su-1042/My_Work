#!/bin/bash

IFS='.' read -r -a parts <<< "$1"
#splits ip address

binary=""
for part in "${parts[@]}"; do
  binary="$binary$(bc <<< "obase=2;$part") "
done

binary=${binary::-1}

echo "$binary" 
