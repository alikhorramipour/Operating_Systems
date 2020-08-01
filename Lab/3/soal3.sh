#!/bin/bash
while [ true ]
do
	echo -ne "Enter a Number: "
	read n
	if [ $n == "finish" ]
	then
		break
	fi
	input=$n
	digitTmp=0
	reverse=0
	while [ $input -gt 0 ]
		do
    		digitTmp=$(( $input % 10 ))
		reverse=$(( $reverse * 10 ))
		reverse=$(( $reverse + $digitTmp ))
    		input=$(( $input / 10 ))
		done
	echo "Reverse of $n is $reverse"

	inputTmp=$n
	g=$inputTmp
	sum=0
	while [ $inputTmp -gt 0 ] 
		do
    			digit=$(( $inputTmp % 10 ))  
    			inputTmp=$(( $inputTmp / 10 ))
    			sum=$(( $sum + $digit ))  
		done
	echo "Sum of $n is $sum"
done
