#! /bin/bash

FILES="../test_processes/*"

for file in $FILES;
do
  ./bin/program4 $file
done
