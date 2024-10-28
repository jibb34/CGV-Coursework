#!/bin/bash

for i in {10,20,33,75,50,37,100}; do
  for j in {5,20,33,75,37,50,100}; do
    echo $i x $j
    bash check.sh $i $j
  done
done
