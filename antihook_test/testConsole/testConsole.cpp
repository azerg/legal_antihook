// testConsole.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{
  auto hDLL = ::GetModuleHandle("SampleDLL.dll");
  std::cout << "SampleDLL.dll " << (hDLL == NULL ? "is not loaded " : "is loaded ") << "in testConsole" << std::endl;
  system("pause");
}