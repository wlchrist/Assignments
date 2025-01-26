# PA1

# About

## For this assignment, we are creating a quiz game which is designed to help the player learn how to effectively navigate their linux command line.

# Design and Intuition

## In this assignment, we need to store two chunks of data. One chunk is allocated for user profile storage (persistent) and another chunk is allocated for linux commands. We can think of the user profile storage as a rather rigid storage and we can think of the linux commands as a living docket of commands that will be added/removed as needed in our program.

## One advantage to using a linked list is that you can add/remove nodes at low compute cost (O(1) time-space complexity). However, one disadvantage is if the node is at an unknown point in the linked list, the time-space complexity increases to O(n) when the node in question is at an unknown location in the linked list. Linked lists also offer another distinct advantage over arrays: the programmer can resize linked lists dynamically, without needing to copy over elements and creating a completely new list. For this reason, we are going to use linked lists to store our linux commands for the game.

## Despite the advantages aforementioned, for the sake of this asignment, using a linked list over an array to store persistent data (such as user profiles) would be the least utilitarian choice of the two. As we already know the memory location for the user, there should be little compute overhead involved in searching our persistent storage implementation and moreover, there is little memory overhead as arrays are stored contiguously, rather than allowing the compiler to direct where our linked list nodes are stored.

## To Build and Run
### Navigate to the folder where the files are in your terminal
```
make
./pa1
```
### Once you are done running the executable
```
make clean
```
