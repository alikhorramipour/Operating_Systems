#!/bin/bash

var1=$1
var2=$2

result=$((var1+var2))
echo $result

if [[ ! $1 =~ ^[[:digit:]]+$ ]] || [[ ! $2 =~ ^[[:digit:]]+$ ]]
then
	echo "WRONG ENTRY"
elif [ $var1 -gt $var2 ] 
then
	echo "$var1 is greater than $var2"
else
	echo "$var2 is greater than or equal to $var1"
fi
