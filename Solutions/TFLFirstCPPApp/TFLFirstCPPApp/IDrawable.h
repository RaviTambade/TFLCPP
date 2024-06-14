#pragma once

//Pure Abstract  base Class:
// Abstract Class: where miniumum one method should be pure virtual function
//Interface : interface where all methods are pure virtual function
//What is the difference between interface and abstract class

//In C++ whenever you want to define your entity as interface,
//always start name with I
//Interface
class IDrawable
{
	public:
		virtual void draw() = 0; // Pure virtual function
		//function which does not have implementation

};

//What is the difference between class and interface

//Class	: we can create object from class
//		: we can have muliple functions with implemetation
//		: we can have virutal functions
//		: we can have pure virutal functions
// 
//Interface: we can not create object from interface
//		:we can have all methods pure virtual functions

















