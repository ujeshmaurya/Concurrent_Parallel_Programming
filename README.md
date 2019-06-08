# Concurrent_Parallel_Programming
Important assignments and their solutions for the course: Concurrent and Parallel programming (B.Tech, CSE, MNIT (2015-2019))

Week - 2:
Q.2 Write a program for matrix multiplication using pthread_join(). No mutex should be used.

Q.3 Write a C program in which a filename is passed as a command line argument. In case a wrong name or no file name is passed is passed using CLA it should print an error message using perror().

Q.4 Write a C program that continuously print(with a sleep time of 1 second) the process id and the total sleep time. This program should send a SIGINT signal using signal() call, when a particular key is pressed.

Q.5 Write a program using pthread to find out the sum of following series:
1+4+9+16+.......+ n. Here main function should write the final output on screen. Main thread will create the child threads and child threads will find out the sum of series.


Week - 4:

Q. 1 Implement all the four attempt of Dekker’s algorithm to solve
critical section problem.
Q.2 Implement Dekker’s Algorithm for mutual exclusion.
Q.3 Implement fisher’s algorithm for mutual exclusion
Q.4 Implement Manna-Pnueli algorithm for Mutual exclusion. 

Week - 5:

1.	Implement solution of Critical Section problem with Semaphores (two processes).
 
2.	Implement solution of Critical Section problem with Semaphores (N processes).
 
3.	Implement solution of Critical Section problem with Semaphores (k out of N processes).
 
4.	Implement producer-consumer problem with Semaphores (infinite buffer).
 
5.	Implement producer-consumer problem with Semaphores (finite buffer).
 
6.	Implement producer-consumer problem with Semaphores (circular buffer).
 
7.	Implement critical section problem with exchange
 
exchange (a, b) is
integer temp 
Temp  <-   a
 a	<-    b
 b	<-   Temp	
 
 Week - 6:
 
 1.	Implement Critical Section problem using semaphores with a monitor.
 
2.	Implement the solution of producer-consumer bounded buffer problem with a monitor. 
 
3.	Implement the solution of Readers and writers with a monitor.
 
4.	Consider a system consisting of processes P1, P2, ..., Pn, each of which has a unique priority number. Write a monitor that allocates three identical line printers to these processes, using the priority numbers for deciding the order of allocation.

Week - 7:

1.	Write MPI Program (SPMD) to get started.
2.	Write MPI Program (MPMD) to get started. 
3.	Write MPI program to find sum of n integers on Parallel Processing Platform. You have to use MPI point-to-point blocking communication library calls.
4.	Write MPI program to find sum of n integers on Parallel Processing Platform. You have to use MPI point-to-point blocking communication library calls.
5.	Write MPI program to find sum of n integers on a Parallel Computing System in which processors are connected with ring topology and use MPI point-to-point blocking communication library calls.
6.	Write MPI program to find sum of n integers on a Parallel Computing System in which processors are connected with tree topology (Associative-fan-in rule for tree can be assumed) and use MPI point-to-point blocking communication library calls.
7.	Write MPI program to compute the value of PI by numerical integration using MPI point-to-point blocking communication library calls.
8.	Write MPI program for prefix sum (scan operation) calculation using MPI point-to-point blocking communication library calls.
9.	Write MPI program to find sum of n integers on a Parallel Computing System in which processors are connected with tree topology (Associative-fan-in rule for tree can be assumed) and use MPI point-to-point non-blocking communication library calls.
10.	Write MPI program to broadcast message "Hello world" to all the process.

Week - 8:

11.	Write a OpenMP program to print unique identifier.
12.	Write a "Hello world" Program Using OpenMP pragmas.
13.	Illustrate a program for loop recurrence using OpenMP PARALLEL FOR directive.
14.	Write an OpenMP program to find Sum of Natural Numbers using OpenMP Parallel FOR directive.
15.	Write an OpenMP program to find Sum of Natural Numbers using OpenMP REDUCTION clause.
16.	Write an OpenMP program for Loop-carried dependence using OpenMP parallel Directive.


