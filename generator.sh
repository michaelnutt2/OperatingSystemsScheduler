#! /bin/bash

i="0"
while [ $i -lt 50 ]
do
  ./a.out > processes/output$i
  i=$[$i+1]
done
