#!/usr/bin/env bash

CPU=$(cat /proc/cpuinfo | grep "model name" -m1)
MEM=$(head -n3 /proc/meminfo)
UNAME=$(uname -srvm)

echo -e "$UNAME\n$CPU ($(nproc) cores)\n$MEM" > sysinfo
