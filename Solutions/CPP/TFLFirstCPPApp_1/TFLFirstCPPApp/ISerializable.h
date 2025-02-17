#pragma once

//interface
//Whenever we define interface. They are defined using only .h (header files)
//Interface does not have .cpp as implementation file 

class ISerializable
{
	public:
		virtual void serialize() = 0; // Pure virtual function

};

