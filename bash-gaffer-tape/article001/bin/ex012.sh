#!/bin/bash
touch /tmp/t1 # Create a zero length file to test basename
$(basename $(ls /tmp/t1)) # Print the name of the file only
