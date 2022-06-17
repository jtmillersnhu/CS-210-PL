#pragma once

#ifndef __UTILS_H
#define __UTILS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <Python.h>
#include <Windows.h>
#include <fstream>
#include <vector>


std::string nCharString(size_t n, char c);
void printMenu(std::string strings[], unsigned int numStrings, unsigned char width);
unsigned int getMenuChoice(unsigned int maxChoice);
int getInteger();
std::string getString();
void callStringFunc(std::string proc, int param);
int callIntFunc(std::string proc, int param);
void CallProcedure(std::string pName);
double CallDoubleFunc(std::string proc, std::string param);
void DisplayItemFrequency();
void DisplayHistogram();

#endif // __UTILS_H
