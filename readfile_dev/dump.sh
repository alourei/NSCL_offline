#!/bin/bash
for i in `seq $1 $2`;
do
    #echo "ls /events/e14066/experiment/run${i}|wc -l"
    nfiles=`ls /events/e14066/experiment/run${i}|wc -l`
    #nfiles=1
    echo "$nfiles evt files in run${i}"
    nfiles=$[nfiles-1]
    #echo "$nfiles evt files in run${i}"
    for j in `seq 0 $[nfiles]`;
    do
	echo "run${i}-${j}.evt"
	echo "/user/e14066/ddasdumper/ddasdumper --source=file:///events/e14066/experiment/run{i}/run-00{i}-0${j}.evt --fileout=/events/e14066/rootdata/r${i}-${j}.root"
	/user/e14066/ddasdumper/ddasdumper --source=file:///events/e14066/experiment/run${i}/run-00${i}-0${j}.evt --fileout=/events/e14066/rootdata/r${i}-${j}.root
    done
done
