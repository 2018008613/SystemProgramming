#!/bin/sh
y=1
while [ $y -le 1000 ]; do
	touch $y.txt
	y=$((y+1))
done

