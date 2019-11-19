/**
*File Name: Test.h
*Author: Alfonso Martello
*Assignment: EECS-448 Lab 6
*Description: This file tests the provided Queue to check for bugs.
*Date: November 20, 2019
**/

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <stdexcept>
#include "Queue.h"

class Test
{
  private:
    Queue m_Q;

  public:
    /**
    *  @pre None
    *  @throw None
    *  @param testQ, the Queue to be assigned to m_Q.
    *  @post Creates a Test object.
    *  @return Nothing
    */
    Test(Queue testQ);
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Handles all printing of isEmpty() tests.
    *  @return Nothing
    */
    void testIsEmpty();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if newly created Queue is empty.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string createdIsEmpty();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Enqueing a value makes the Queue not empty.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string oneItemIsNotEmpty();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Dequeing the only value makes the Queue empty.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string removeLastItemIsEmpty();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Enqueing two values and Dequeing one makes the Queue not empty.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string add2Remove1IsNotEmpty();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Enqueing three values and Dequeing one makes the Queue not empty.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string add3Remove1IsNotEmpty();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Enqueing three values and Dequeing all three makes the Queue empty.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string add3Remove3IsEmpty();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Handles all printing of enqueue(const int& newEntry) tests.
    *  @return Nothing
    */
    void testEnqueue();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Enqueing two values makes the Queue not empty.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string enQ2MakesNotEmpty();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Enqueing a value and peeking at it returns the correct value.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string enQ1ValueIsCorrect();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Enqueing two values and peeking at front returns the first value entered.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string enQ2ValuesInCorrectOrder();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Enqueing four values and peeking at front returns the first value entered.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string enQ4ValuesInCorrectOrder();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Enqueing two values, dequeing one, and then peeking at front returns the second value entered.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string enQ2deQ1ValueInCorrectOrder();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Handles all printing of dequeue() tests.
    *  @return Nothing
    */
    void testDequeue();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Dequeing empty Queue results in a runtime_error.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string throwErrorWhenDeQEmpty();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Enqueing 1 value and dequeing it makes the Queue empty.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string enQ1deQ1IsEmpty();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Does not throw error when it shouldn't.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string throwDeQErrorWhenShouldNot();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Enqueing 2 nodes with the same value, then dequeing 1, only removes one node.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string enQ2deQ1WithSameValue();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Enqueing 5 nodes, then dequeing 3, only removes the first 3 nodes.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string removeFront();          //checks if deqeue removes the front value
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Handles all printing of peekFront() tests.
    *  @return Nothing
    */
    void testPeekFront();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Peeking empty Queue results in a runtime_error.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string throwErrorWhenPeekEmpty();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Does not throw error when it shouldn't.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string throwPeekErrorWhenShouldNot();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Peeking the only value in the Queue, 5, returns 5.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string correctValue();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Enqueing 2 values then peeking returns the first item enqueued.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string peekFirstValue();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Peek does not remove items from the Queue.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string peek1ItemNotEmpty();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Peek does not add items to the Queue.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string peek1DeQ1IsEmpty();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Tests if Peek does not change the value of any nodes.
    *  @return Returns a string saying "PASSED" or "FAILED" depending on how the test resulted.
    */
    std::string consistentValues();
    /**
    *  @pre None
    *  @throw None
    *  @param None
    *  @post Runs all the tests.
    *  @return Nothing
    */
    void run();
};

#endif
