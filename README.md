# OOCatcher

## Overview

OOCatcher is a C++ project developed as part of the CS 323 Advanced OOP course at the American University of Armenia. The objective is to simulate an anthropomorphic body composed of interconnected segments, capable of catching a circular object or throwing a snowball at a specified target. This involves concepts of object-oriented design, geometry, and constrained motion.

## Project Structure

The project is divided into two parts: **Preliminary** and **Final Implementation**.

---

## Preliminary implementation

This part includes the basic classes to implement the project. Those are the classes that we also looked at
during the lectures with some adjustments.

### Deliverables

point.h/cpp - a simple class for 2D coordinates

base_line, line(1/2).h/cpp - classes for lines with rotation capabilities

circle.h/cpp - class for the target object to be grabbed

body.h/cpp - class for the body with new methods for neck, back, segments created for testing


I reviewed one more time all the classes, and rewrote here to then use in the project for the main catching process.

I have tried to write little test (main.cpp) them sepearetly to just check whether they work fine.


### References:

Lecture codes(took the main logicof the classes to fit to this project specifications further)

M. Gregoire, “Professional C++”, 5th ed., 2021

AI prompts (paraphrased the question to write here):
- What would be a step-by-step approach to developing this project incrementally? I want to understand each component before putting it all together.
- Can you explain the concept of an anthropomorphic body representation using line segments in C++? I'm working on a project called OOCatcher.
- I'm trying to understand how to model rotation constraints for connected line segments. What approaches I can take?
- Can you suggest some test cases I should implement to my line, point, circle and body work correctly? 
  Also some examples of creating tests in C++.



## Final implementation


### Description

The final version integrates all the components to execute full simulations for two scenarios:

1. **Walker** – The body walks and catches a circle object
2. **Snowball Thrower** – The body throws a snowball to hit a target without walking

### Files:

main.cpp – Simple tests for preliminary components

mainvis.cpp – Visual simulation for catching object

oocatcher.cpp – High-level orchestration of object catching logic

snowball_thrower.cpp – Logic for snowball throw scenario

snowball_vis.cpp  - Visual simulation for throwing a snowball

segment.cpp, simplesegment.cpp – Logic for body segments

point.cpp, circle.cpp, body.cpp – Geometric and body logic


### Compile & Run Instructions

To build and run different scenarios:

#### Walker:
```bash
g++ -std=c++17 -o walker main.cpp oocatcher.cpp body.cpp circle.cpp point.cpp segment.cpp simplesegment.cpp
./walker
```

#### Walker Visualization:
```bash
g++ -std=c++17 -o mainvis mainvis.cpp oocatcher.cpp body.cpp circle.cpp point.cpp segment.cpp simplesegment.cpp
./mainvis
```

#### Snowball Thrower:
```bash
g++ -o snowball_thrower snowball_thrower.cpp point.cpp segment.cpp body.cpp
./snowball_thrower
```

#### Snowball Thrower Visualization:
```bash
g++ -o snowballvis snowball_vis.cpp  point.cpp segment.cpp body.cpp
./snowballvis
```

---

## Output

- **Result Logs**: Output data such as body movement steps, velocity values, and coordinates for snowball throws are saved in `.txt` files.
  - These are useful for validation, grading, or further visual analysis.



### References:

AI Prompts Used

Here are some example prompts that helped guide parts of the development and structure without generating full solutions:

- What would be a step-by-step approach to developing a C++ simulation project incrementally?
- How to model anthropomorphic motion using line segments and rotation constraints in C++?
- How do I apply rotation to a 2D segment given a pivot point and an angle?
- What would be a good structure for a class representing a body composed of jointed segments?
- Can you suggest some test cases for validating a geometric class like a 2D point, line, or circle?
- How can I visualize the walker in the terminal to see how it walks and grabs the object?
- How to combine all these files to create a snowball_thrower class to test the results?
