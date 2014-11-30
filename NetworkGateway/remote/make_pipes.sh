#!/bin/bash
IP=192.168.2.147
PORT=8000
if [ ! -e /tmp/pipe_in ];  then mkfifo /tmp/pipe_in  ; fi
if [ ! -e /tmp/pipe_out ]; then mkfifo /tmp/pipe_out ; fi
while true ; do netcat ${IP} ${PORT} < /tmp/pipe_in > /tmp/pipe_out ; done &
