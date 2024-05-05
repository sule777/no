#!/bin/bash

echo "Enter first number"
read x1
echo "Enter second number"
read x2

if [[ $x1 -gt $x2 ]]
then
	echo "$x1 is largest"
else
	echo "$x2 is largest"
fi
