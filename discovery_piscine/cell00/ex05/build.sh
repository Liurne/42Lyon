#!/bin/bash

args=("$@")
i=0

while [ $i -lt "$#" ];
do
	mkdir "ex${args[i]}"
	i=$((i + 1))
done
