# OOCatcher

## Preliminary implementation

This part includes the basic classes to implement the project. Those are the classes that we also looked at
during the lectures with some adjustments.

Deliverables
point.h/cpp - a simple class for 2D coordinates
base_line, line(1/2).h/cpp - classes for lines with rotation capabilities
circle.h/cpp - class for the target object to be grabbed
body.h/cpp - class for the body with new methods for neck, back, segments created for testing

I reviewed one more time all the classes, and rewrote here to then use in the project for the main catching process.
I have tried to write little test (main.cpp) them sepearetly to just check whether they work fine.


References:
Lecture codes(took the main logicof the classes to fit to this project specifications further)
M. Gregoire, “Professional C++”, 5th ed., 2021

AI prompts (paraphrased the question to write here):
- What would be a step-by-step approach to developing this project incrementally? I want to understand each component before putting it all together.
- Can you explain the concept of an anthropomorphic body representation using line segments in C++? I'm working on a project called OOCatcher.
- I'm trying to understand how to model rotation constraints for connected line segments. What approaches I can take?
- Can you suggest some test cases I should implement to my line, point, circle and body work correctly? 
  Also some examples of creating tests in C++.



## Final implementation
