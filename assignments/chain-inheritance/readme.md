 Chained Inheritance  (Smart Tech Hierarchy)

This program demonstrates Chained (Multilevel) Inheritance in C++ using a 3-tier technology device hierarchy.

 Hierarchy Structure
1. Device (Base Class): Houses the general `brand` property.
2. Computer (Intermediate Class): Inherits from `Device` and adds `ramGB`.
3. Laptop (Derived Class): Inherits from both classes, adding a `batteryLevel` property.

Technical Highlights
  Constructor Chaining: Parameters are forwarded up the inheritance pipeline during initialization.
  Access Control: Demonstrates how derived classes inherit and utilize ancestral variables.


