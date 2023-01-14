import os 
import sys
import random

from numpy import number
def compile(filename: str):
    os.system(f"g++ {filename}/{filename}.cpp -o a")
# path = "hsgTpHN2019B2"
def create(filename: str):
    if not os.path.exists(filename):
        os.mkdir(filename)
    if not os.path.exists(f"{filename}/input"):
        os.mkdir(f"{filename}/input")
    if not os.path.exists(f"{filename}/output"):
        os.mkdir(f"{filename}/output")

def input(filename: str, number: int):
    return "{}/input/input{:02d}.txt".format(filename, number)

def output(filename: str, number: int):
    return "{}/output/output{:02d}.txt".format(filename, number)

def run(filename: str, number: int):
    _input = input(filename, number)
    _output = output(filename, number)
    os.system("./a < {} > {}".format(_input, _output))
