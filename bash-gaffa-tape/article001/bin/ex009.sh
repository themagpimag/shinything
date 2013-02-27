#!/bin/bash
# Fill a file with some strings
echo "Apple Orange" > list # Truncate and then append
echo "Pear" >> list # Append to list
# print each word in the input file.
for l in $(<list); do
  echo $l
done
