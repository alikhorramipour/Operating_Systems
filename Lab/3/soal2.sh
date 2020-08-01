#!/bin/bash
echo -ne "Enter first operand: "
read op1
operand1=$op1

echo -ne "Enter second operand: "
read op2
operand2=$op2

echo -ne "Enter the operator: "
read opr
operator=$opr

case $operator in
    +)
        echo $(( $op1 + $op2 ))
    ;;

    -)
        echo $(( $op1 - $op2 ))
    ;;

    '*')
        echo $(( $op1 * $op2 ))
    ;;

    '/')
        result=$(( $op1 / $op2 ))
	echo "$result"
    ;;
esac
