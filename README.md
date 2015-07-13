# csci3453-lab2-scheduler
simulation of process scheduling algorithms

## assignment

CSCI 3453: Lab 2
Summer 2015


Due Date
4:00p July 10th 2015
No late submissions will be accepted.


Delivery Method
You will likely write a multi-file C and/or C++ program. You should submit this source code as a tar archive. Deliver a single file named lab2.tgz (all lowercase) using Canvas.

Here is a tar command for this assignment. Change to the parent directory of your source code directory which should be named lab2:

`
% tar czvf lab2.tgz lab2
`

This command will create a tarball named lab2.tgz that you can attach to your Canvas submission.

Your source code directory should use a make to build the executable that should be named lab2.

Grading
This lab will be worth 10 pts.

Goal of this programming assignment
The primary goal of this lab assignment is to understand various CPU scheduling algorithms and gain some experience building a simulator for CPU scheduling algorithm to evaluate their performances.

Requirements
1. Programming language: You have to use either C or C++ to develop your program.
2. Running Environment: Your program should be compiled at CSEGRID and be able to be tested without errors.

Problem Description
Write a C/C++ program to simulate a CPU scheduler which selects a process from a ready queue and executes the process using a specified scheduling algorithm. Display its activities and evaluate its performance based on collected some measurements such as average turn-around time, average waiting time, average response time. When a process is scheduled, the simulator will simply print what the process is running at what time, collecting some measurement data and producing Gantt Chart-like outputs.

Specification
You will implement the FCFS (First Come First Serve), SRTF (Shortest Remaining Task First), RR (Round Robin) scheduling algorithms. The detailed algorithms are well described Chapter 5 in textbook.

Assumptions
Use the following assumptions when you design and implement a CPU simulator.

* There is only one CPU
* All processes perform only CPU operations.
* All processes have the same priority.
* A newly arriving process is immediately stored at the ready queue.
* We will use only the ready queue for this simulation.
* Assume the context switching cost is 0.5 milliseconds
* Context switch occurs only when the current process is moved to the ready queue.
* Time units are milliseconds.
* We use FCFS policy for breaking the tie. (For Round-Robin case)

DO NOT USE any built-in queue library or class (do not use stl library in C++ or C). You have to implement your own queue management functions (or method).

Measurements and Evaluation
You should collect the following information of each process:
* Time of completion
* Waiting time
* Turn around time
* Response time
* No. of Context switches occurred

 

You should calculate the following information using collected measurements:
* Average CPU burst time
* Average waiting time
* Average turn around time
* Average response time
* Total number of Context Switching performed

Please refer Chapter 5 in textbook for detail information about the measurements: waiting time, turn around time, response time, average waiting time, average turn around time, and average response time.

Simulator Input
There are three inputs will be given as arguments when the simulator begins.

1. Process arrival information
(expect total number of arrival processes are up to 100) The process information will be read from a text input file. The information for each process will include the following fields:
pid: a unique numeric process ID.
arrival time: the time when the task arrives in the unit of milliseconds
CPU burst time: the CPU time requested by a process

An example of input file:

```
1 0 10
2 1 2
3 2 9
4 3 5
```

Note: The time unit for arrival time and CPU burst time is millisecond. You can assume that all time values are integer and pids provided in an input file are unique.

2. Type of scheduling algorithm
You will be implementing two scheduling algorithms, and you will select one algorithm when you start the simulator as the 2nd argument. You will enter an integer value from one of the followings:

```
FCFS: % myscheduler test_input_file 0
SRTF: % myscheduler test_input_file 1
RR: % myscheduler test_input_file 2 quantumsize
```

3. Time Quantum size
You will define the time quantum when the simulator begins as the first argument. The time quantum is essential for the RR scheduling and the time quantum value is an integer value and should be greater than 0. Thus, your program should be able to take the time quantum value as the first input value. So, your program will be executed as follows:
% myscheduler test_input 2 4

Output (Sample)
The simulator will display both history of process, like Gantt Chart-like outputs, and measurements. The expected output format is as follows:

```
*********************************************************************
***************** Scheduling algorithm : FCFS ***********************
*********************************************************************
pid arrival CPUburst finish waiting turnaround response Context
1 0 10 10.0 0.0 10.0 0.0 0
2 1 2 12.0 9.0 11.0 9.0 0
3 2 9 21.0 10.0 19.0 10.0 0
4 3 5 26.0 18.0 23.0 18.0 0
Average CPU burst time = 6.50 ms, Average waiting time = 9.25 ms
Average turn around time = 15.75 ms, Average response time = 9.25 ms
Total No. of Context Switching Performed =0


*********************************************************************
*************** Scheduling algorithm : SRTF *************************
*********************************************************************
pid arrival CPUburst finish waiting turnaround response Context
1 0 10 17.5 7.5 17.5 0.0 1
2 1 2 3.5 0.5 2.5 0.5 0
3 2 9 26.5 15.5 24.5 15.5 0
4 3 5 8.5 0.5 5.5 0.5 0
Average CPU burst time = 6.50 ms, Average waiting time = 6.0 ms
Average turn-around time = 12.5 ms, Average response time = 4.125 ms
Total No. of Context Switching Performed =1


*********************************************************************
********* Scheduling algorithm: Round Robin *************************
*********** ( No. of Task = 4 Quantum= 4 ) **************************
*********************************************************************
pid arrival CPUburst finish waiting turnaround response Context
1 0 10 26.5 16.5 26.5 0.0 2
2 1 2 6.5 3.5 5.5 3.5 0
3 2 9 27.5 16.5 25.5 4.5 2
4 3 5 25.5 17.5 22.5 8.0 1
Average CPU burst time = 6.50 ms, Average waiting time = 13.5 ms
Average turn around time = 20.0 ms, Average response time = 4.00 ms
Total No. of Context Switching Performed = 5
```
