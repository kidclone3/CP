#!/bin/bash
echo "Liet ke tat ca cac file trong /Desktop"
ls ~/Desktop
echo 

echo "Liet ke cac file co duoi .sh"
ls ~/Desktop | grep -E "^.*[.]?sh$"