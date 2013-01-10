#!/bin/bash
# Print "Hello Joe" then replace Joe with Fred. 
echo "Hello Joe" | sed 's/Joe/Fred/g'

# Replace Hello with Goodbye too.
echo "Hello Joe" | sed 's/Joe/Fred/g' | sed 's/Hello/Goodbye/g'
