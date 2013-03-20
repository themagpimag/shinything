#!/bin/bash
for file in $(ls *.txt); do
  gzip $file
done
