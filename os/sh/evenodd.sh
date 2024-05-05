#!/bin/bash

echo "Enter a number"
read num

res=`expr $num % 2`
if [[ $res -eq 0 ]]
then
	echo "Number is even"
else
	echo "Number is odd"
fi
