#!/bin/bash

pid_max=$(cat /proc/sys/kernel/pid_max)
echo "Max PID is: $pid_max"
