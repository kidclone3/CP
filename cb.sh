#!/bin/bash

# From an idea, when I want use script to copy my template to clipboard
# faster and easier.

_copy(){
  cat /home/delus/Documents/code/template.cpp | xclip -selection clipboard 
}
