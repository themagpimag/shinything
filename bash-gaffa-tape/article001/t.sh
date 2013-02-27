#/bin/bash
#
i=1
j=2
if [[ $i -ne $j ]]; then
  echo "$i != $j"
fi

if [[ ($i != 0) && $j ]]; then
  echo "$i && $j"
fi
