#!/bin/bash

echo "Enter fisrt number"
read n1
echo "Enter second number"
read n2

if [[ $n1 -lt $n2 ]]
then
	echo "$n1 is smallest"
else
	echo "$n2 is smallest"
fi

