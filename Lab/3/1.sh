#!/bin/bash
a=$1
b=$2
re='^[0-9]+$'
if [[ $a =~ $re && $b =~ $re ]]
then
    c=$((a + b))
    echo sum is $c
    if [ $a -gt $b ]
    then
        echo $a is greater than $b
    elif [ $b -gt $a ]
    then
        echo $b is greater than $a
    else
        echo $a is equal with $bash
    fi
else
    echo not a number
fi