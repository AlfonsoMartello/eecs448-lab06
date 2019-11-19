/**
*	@file main.cpp
*	@author John Gibbons
*	@date 2014.04.02
*/

#include <iostream>
#include <stdexcept>
#include "Queue.h"
#include "Test.h"

int main()
{
	Queue q;
	Test testQ(q);
	testQ.run();
	return(0);
}
