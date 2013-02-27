#!/bin/bash
str1="Raspberry"
str2="berry"
if [[ $str1 == "$str2"* ]]; then
  echo "$str1 begins with $str2"
fi
if [[ $str1 == *"$str2" ]]; then
  echo "$str1 ends with $str2"
fi
if [[ $str1 == *"$str2"* ]]; then
  echo "$str1 contains $str2"
fi
