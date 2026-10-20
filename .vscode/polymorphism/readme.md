 Polymorphism  (Smart Home Hub)

This project demonstrates **Runtime Polymorphism** in C++ using a real-world smart home automation network written inside `polymorphism.cpp`.

 System Components
   SmartDevice (Base Class): Establishes a generic framework containing a `virtual void activate()` method.
   SmartLight (Derived Class 1): Overrides the base method to power on bulbs and adjust brightness percentages.
   SmartThermostat (Derived Class 2): Overrides the base method to initialize the AC unit and set target temperatures.

 OOP Principles Showcased
    Virtual Functions: Enables dynamic binding at execution time.
    Base Class Pointers: Uses a uniform vector of `SmartDevice*` points to manage distinct objects smoothly inside `main()`.
    Override Safety: Utilizes explicit keywords to guarantee identical function blueprints across children.

Build Requirements
     A standard C++ compiler (like GCC/g++) supporting C++11 or newer.
