#!/bin/bash

module="stupid"
device="stupid"
mode="664"

# remove module
/sbin/rmmod ./$module.ko $* || exit 1
# remove stale nodes
rm -f /dev/${device}[0-3]
