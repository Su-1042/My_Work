#!/bin/bash

cat $1 | tr '[:upper:]' '[:lower:]'| shuf | grep "\S" >> $2


# grep -Eo prints all li


