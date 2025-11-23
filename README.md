# OS Asignment 2 Deadlock Avoidance With Bankers Algorithm
    - Caroline Shantery

## Overview
    - This project impliments the bankers algorithm to determind wether or not a sequence is in the safe state
    - The program reads in the data from the input.txt file containing the number of processes and reuired resources, allocation, max and avaliable matrix
    - If the sequence is deemed safe the ouput will be the order of the safe sequence 

## Requirments
    - built and run in Dockercontainer
    - linux or unix required

## To Build and Run
    - g++ banker.cpp -o banker
    - ./banker

## Expected
    - the expected output based on the provided input file
    - system is in a safe state P1->P3->P4->P0->P2

## How it Works
    - read input from input.txt
    - calculate the required for each process require[i][j] = Max[i][j] - allocation[i][j]
    - initialize bankers algorithim
        - initialize work vector that acts as a copy of avaliable and Finished vector
        - iterate through all processes to find a process that is not finished and required resources is less than or equal to work
        - if found add the processes allocation back to work, releasing resources, mark as finihsed, and append to the safe sequence
        - continue until all processes are finished or it is deemed there is not safe sequence 
