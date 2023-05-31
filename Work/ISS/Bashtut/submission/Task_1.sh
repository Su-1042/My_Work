#!/bin/bash

declare -i a=$1 b=$2
c=0

gcd (){
	m=$1
	if [ $m -gt $2 ]
	then
		m=$2
	fi

	for (( i=1 ; i <= $m ; i++ ))
	do
		declare -i dd=$(( $1 % $i ))
		if [ $dd -eq 0 ]
		then 
			declare -i d=$(( $2 % $i ))
			if [ $d -eq 0 ]
			then
				g=$i
				c=$g
				e=$g
			fi
		fi
	done
	echo "GCD:$g" 
		
}

lcm (){

	x=$(( $1*$2 ))
	y=$(( $x/$e ))

	echo "LCM:$y"
}



gcd $1 $2
lcm $1 $2

