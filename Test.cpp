/*
*
*File Name: Test.cpp
*Author: Alfonso Martello
*Assignment: EECS-448 Lab 6
*Description: This file implements all the member variables and member methods in the Test class.
*Date: November 20, 2019
*
*/
#include "Test.h"

Test::Test(Queue testQ)
{
  m_Q = testQ;
}

void Test::testIsEmpty()
{
  std::cout<<"Testing isEmpty():\n";
  std::cout<<"Test 1: Newly created Queue is empty: "<<createdIsEmpty()<<'\n';
  std::cout<<"Test 2: Enqueing a value makes the Queue not empty: "<<oneItemIsNotEmpty()<<'\n';
  std::cout<<"Test 3: Dequeing the only value makes the Queue empty: "<<removeLastItemIsEmpty()<<'\n';
  std::cout<<"Test 4: Enqueing two values and Dequeing one makes the Queue not empty: "<<add2Remove1IsNotEmpty()<<'\n';
  std::cout<<"Test 5: Enqueing three values and Dequeing one makes the Queue not empty: "<<add3Remove1IsNotEmpty()<<'\n';
  std::cout<<"Test 6: Enqueing three values and Dequeing all three makes the Queue empty: "<<add3Remove3IsEmpty()<<'\n';
}

std::string Test::createdIsEmpty()
{
  Queue newQ;
  bool returnVal = newQ.isEmpty();
  if (returnVal == true)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::oneItemIsNotEmpty()
{
  Queue newQ;
  newQ.enqueue(5);
  bool returnVal = newQ.isEmpty();
  if (returnVal == false)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::removeLastItemIsEmpty()
{
  Queue newQ;
  newQ.enqueue(5);
  newQ.dequeue();
  bool returnVal = newQ.isEmpty();
  if (returnVal == true)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::add2Remove1IsNotEmpty()
{
  Queue newQ;
  newQ.enqueue(5);
  newQ.enqueue(6);
  newQ.dequeue();
  bool returnVal = newQ.isEmpty();
  if (returnVal == false)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::add3Remove1IsNotEmpty()
{
  Queue newQ;
  newQ.enqueue(5);
  newQ.enqueue(6);
  newQ.enqueue(7);
  newQ.dequeue();
  bool returnVal = newQ.isEmpty();
  if (returnVal == false)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::add3Remove3IsEmpty()
{
  Queue newQ;
  newQ.enqueue(5);
  newQ.enqueue(6);
  newQ.enqueue(7);
  newQ.dequeue();
  newQ.dequeue();
  newQ.dequeue();
  bool returnVal = newQ.isEmpty();
  if (returnVal == true)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

void Test::testEnqueue()
{
  std::cout<<"Testing enqueue(const int& newEntry):\n";
  std::cout<<"Test 1: Enqueing two values makes the Queue not empty: "<<enQ2MakesNotEmpty()<<'\n';
  std::cout<<"Test 2: Enqueing a value and peeking at it returns the correct value: "<<enQ1ValueIsCorrect()<<'\n';
  std::cout<<"Test 3: Enqueing two values and peeking at front returns the first value entered: "<<enQ2ValuesInCorrectOrder()<<'\n'; //returnVal is 10, implying that enQ does not add nodes to the back of the Queue. It seems to place all valus at the front of the Q which is WRONG
  std::cout<<"Test 4: Enqueing four values and peeking at front returns the first value entered: "<<enQ4ValuesInCorrectOrder()<<'\n';
  std::cout<<"Test 5: Enqueing two values, dequeing one, and then peeking at front returns the second value entered: "<<enQ2deQ1ValueInCorrectOrder()<<'\n';
}

std::string Test::enQ2MakesNotEmpty()
{
  Queue newQ;
  newQ.enqueue(5);
  newQ.enqueue(6);
  bool returnVal = newQ.isEmpty();
  if (returnVal == false)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::enQ1ValueIsCorrect()
{
  Queue newQ;
  newQ.enqueue(5);
  int returnVal = newQ.peekFront();
  if (returnVal == 5)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::enQ2ValuesInCorrectOrder() //returnVal is 10, implying that enQ does not add nodes to the back of the Queue. It seems to place all valus at the front of the Q which is WRONG
{
  Queue newQ;
  newQ.enqueue(5);
  newQ.enqueue(10);
  int returnVal = newQ.peekFront();
  //std::cout<<"\n\n"<<returnVal<<"\n\n";
  if (returnVal == 5)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::enQ4ValuesInCorrectOrder() //returnVal is 20.
{
  Queue newQ;
  newQ.enqueue(5);
  newQ.enqueue(10);
  newQ.enqueue(15);
  newQ.enqueue(20);
  int returnVal = newQ.peekFront();
  //std::cout<<"\n\n"<<returnVal<<"\n\n";
  if (returnVal == 5)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::enQ2deQ1ValueInCorrectOrder() //returnVal is 5, so 5 was added, then 10 was added to the front (not the back like it should be), dequeue removes front value 10, so peekFront gets 5, supports hypo
{
  Queue newQ;
  newQ.enqueue(5);
  newQ.enqueue(10);
  newQ.dequeue();
  int returnVal = newQ.peekFront();
  //std::cout<<"\n\n"<<returnVal<<"\n\n";
  if (returnVal == 10)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

void Test::testDequeue()
{
  std::cout<<"Testing dequeue():\n";
  std::cout<<"Test 1: Dequeing empty Queue results in a runtime_error: "<<throwErrorWhenDeQEmpty()<<'\n';
  std::cout<<"Test 2: Enqueing 1 value and dequeing it makes the Queue empty: "<<enQ1deQ1IsEmpty()<<'\n';
  std::cout<<"Test 3: Does not throw error when it shouldn't: "<<throwDeQErrorWhenShouldNot()<<'\n';
  std::cout<<"Test 4: Enqueing 2 nodes with the same value, then dequeing 1, only removes one node: "<<enQ2deQ1WithSameValue()<<'\n';
  std::cout<<"Test 5: Enqueing 5 nodes, then dequeing 3, only removes the first 3 nodes: "<<removeFront()<<'\n';
}

std::string Test::throwErrorWhenDeQEmpty()
{
  Queue newQ;
  bool returnVal = false;
  try
  {
    newQ.dequeue();
  }
  catch (std::runtime_error& e)
  {
    //std::cout<<"\n\nThrew error!\n\n";
    returnVal = true;
  }
  if (returnVal == true)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::enQ1deQ1IsEmpty()
{
  Queue newQ;
  newQ.enqueue(5);
  newQ.dequeue();
  bool returnVal = newQ.isEmpty();
  if (returnVal == true)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::throwDeQErrorWhenShouldNot()
{
  Queue newQ;
  bool returnVal = false;
  try
  {
    newQ.enqueue(5);
    newQ.dequeue();
  }
  catch (...)
  {
    returnVal = true;
  }
  if (returnVal == false)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::enQ2deQ1WithSameValue()
{
  Queue newQ;
  newQ.enqueue(5);
  newQ.enqueue(5);
  newQ.dequeue();
  int returnVal = newQ.isEmpty();
  if (returnVal == false)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::removeFront() //should have value 4, instead has value 2
{
  Queue newQ;
  newQ.enqueue(1);
  newQ.enqueue(2);
  newQ.enqueue(3);
  newQ.enqueue(4);
  newQ.enqueue(5);
  newQ.dequeue();
  newQ.dequeue();
  newQ.dequeue();
  int returnVal = newQ.peekFront();
  //std::cout<<"\n\n"<<returnVal<<"\n\n";
  if (returnVal == 4)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

void Test::testPeekFront()
{
  std::cout<<"Testing peekFront():\n";
  std::cout<<"Test 1: Peeking empty Queue results in a runtime_error: "<<throwErrorWhenPeekEmpty()<<'\n';
  std::cout<<"Test 2: Does not throw error when it shouldn't: "<<throwPeekErrorWhenShouldNot()<<'\n';
  std::cout<<"Test 3: Peeking the only value in the Queue, 5, returns 5: "<<correctValue()<<'\n';
  std::cout<<"Test 4: Enqueing 2 values then peeking returns the first item enqueued: "<<peekFirstValue()<<'\n';
  std::cout<<"Test 5: Peek does not remove items from the Queue: "<<peek1ItemNotEmpty()<<'\n';
  std::cout<<"Test 6: Peek does not add items to the Queue: "<<peek1DeQ1IsEmpty()<<'\n';
  std::cout<<"Test 7: Peek does not change the value of any nodes: "<<consistentValues()<<'\n';
}

std::string Test::throwErrorWhenPeekEmpty()
{
  Queue newQ;
  bool returnVal = false;
  try
  {
    newQ.peekFront();
  }
  catch (std::runtime_error& e)
  {
    //std::cout<<"\n\nThrew error!\n\n";
    returnVal = true;
  }
  if (returnVal == true)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::throwPeekErrorWhenShouldNot()
{
  Queue newQ;
  bool returnVal = false;
  try
  {
    newQ.enqueue(5);
    newQ.peekFront();
  }
  catch (...)
  {
    returnVal = true;
  }
  if (returnVal == false)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::correctValue()
{
  Queue newQ;
  int returnVal = 0;
  newQ.enqueue(5);
  returnVal = newQ.peekFront();
  if (returnVal == 5)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::peekFirstValue() //returnVal == 10
{
  Queue newQ;
  int returnVal = 0;
  newQ.enqueue(5);
  newQ.enqueue(10);
  returnVal = newQ.peekFront();
  //std::cout<<"\n\n"<<returnVal<<"\n\n";
  if (returnVal == 5)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::peek1ItemNotEmpty()
{
  Queue newQ;
  bool returnVal = false;
  newQ.enqueue(5);
  newQ.peekFront();
  returnVal = newQ.isEmpty();
  if (returnVal == false)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::peek1DeQ1IsEmpty()
{
  Queue newQ;
  bool returnVal = false;
  newQ.enqueue(5);
  newQ.peekFront();
  newQ.dequeue();
  returnVal = newQ.isEmpty();
  if (returnVal == true)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

std::string Test::consistentValues()
{
  Queue newQ;
  int test = 0;
  bool returnVal = true;
  newQ.enqueue(1);
  newQ.enqueue(2);
  newQ.enqueue(3);
  newQ.enqueue(4);
  newQ.enqueue(5);
  for (int i = 5; i > 0; i--)
  {
    test = newQ.peekFront();
    newQ.dequeue();
    if (test < 1 || test > 5)
    {
      returnVal = false;
    }
  }
  if (returnVal == true)
  {
    return("PASSED");
  }
  else
  {
    return("FAILED");
  }
}

void Test::run()
{
  std::cout<<"Starting Test.\n";
  testIsEmpty(); //Conclusion: IsEmpty() works
  testEnqueue(); //Conclusion: testEnqueue() is broke, adds to front not back
  testDequeue(); //Conclusion: testDequeue() works
  testPeekFront();
  //Test ~Queue() by running valgrind on it
}
