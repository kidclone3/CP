#!/bin/bash

currentMode=$(cat /proc/sys/vm/laptop_mode)

if [ $currentMode -eq 0 ]
 then
  echo "5" > /proc/sys/vm/laptop_mode
  echo "Laptop Mode Enabled"
 else
  echo "0" > /proc/sys/vm/laptop_mode
  echo "Laptop Mode Disabled"
fi
