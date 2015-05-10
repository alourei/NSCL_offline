#!/bin/bash
for i in `seq ${1} ${2}`;
do
	nfiles=`ls /events/e14066/rootdata/r${i}*|wc -l`
	#nfiles=2
	if [ ${nfiles} -ne 0 ]
	then		
	echo "$nfiles evt files in run${i}"
	echo "./readFile r${i} ${nfiles}  /events/e14066/rootdata/sorted/run${i}_sorted.root"
	./readFile r${i} ${nfiles} /events/e14066/rootdata/sorted/run${i}_sorted.root
	else
	echo "File not found!!"
	fi

done

