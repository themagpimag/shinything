#!/bin/bash
if [[ $var == 1 ]]; then
  cat /proc/cpu # Check the CPU type
elif [[ $var == 2 ]]; then
  cat /proc/meminfo # Memory information
else
  date -I # The current date
fi
