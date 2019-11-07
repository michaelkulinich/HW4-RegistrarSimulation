# HW4_RegistrarOfficeSim
Imagine that the registrar’s office has approached you with the following issues. At certain times during the day students arrive in large numbers. If there are not enough windows open, the average student wait times are too long, and they receive many complaints. On the other hand, if they open too many windows, their staff will be idle for most of the time, and they will be wasting money. They want you to program a simulation that will allow them to calculate metrics on student wait times and window idle times given a specific traffic flow of students.


Michael Kulinich
2328386
kulinich@chapman.edu
Matthew Nwerem
2277158
nwere100@mail.chapman.edu

Assignment 4
Registrars office simulation

source files:
  Simulation.h
  Simulation.cpp
  main.cpp
  Student.h
  Student.cpp
  GenQueue.cpp
  GenQueue.h
  DoublyListNode.h
  GenDoublyLinkedList.h
  Window.h
  Window.cpp

For this assignment we used the textbook and the following sources
https://www.geeksforgeeks.org/vector-in-cpp-stl/

issues:

Instructions to run:
  make all
  ./HW4_RegistrarSimulation

Comments:
number of windows idle over 5 minutes. we interpreted this as how many windows had a total idle time of over 5 minutes, not when it is continuous 5 minutes
