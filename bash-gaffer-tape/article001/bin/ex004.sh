#!/bin/bash
# Run a command, but throw away the standard output and standard error
rm /tmp &> /dev/null # Thankfully, this command will fail.
