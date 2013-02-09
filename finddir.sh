#!/bin/bash
#

# need to check if shinything is in the path at all first.

# Move to the shinything directory to make sure everything is committed.
shinything_dir=$PWD
current_dir=$(basename $shinything_dir)
if [[ $current_dir != "shinything" ]]; then
  shinything_dir=$(echo $shinything_dir | perl -ne '@frags=split(/shinything\//,$_); print STDOUT "$frags[0]/shinything";')
fi
cd $shinything_dir

pwd
