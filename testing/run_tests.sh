#! /bin/bash

FILES="../test_processes/*"

for file in $FILES;
do
  ./a.out $file
done
