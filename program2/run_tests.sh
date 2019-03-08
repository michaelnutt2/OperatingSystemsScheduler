#! /bin/bash

FILES="../test_processes/*"

for file in $FILES;
do
  ./bin/program2 $file
done
