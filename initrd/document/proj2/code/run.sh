#!/bin/sh
mknod -m 666 /dev/null c 1 3
./process > 1 &
sleep 1
./process > 2 &

