#! /bin/bash

FILES="../processes/*"

for file in $FILES;
do
  ./bin/program2 $file
done
