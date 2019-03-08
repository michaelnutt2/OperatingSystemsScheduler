#! /bin/bash

FILES="../test_processes/*"

for file in $FILES;
do
  ./bin/program3 $file
done
