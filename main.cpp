/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Main program for the turing´s machine automaton
 * @version 0.1
 * @date 2022-18-12
 * SUBJECT: CC
 * PRACTICE: 2
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "turing_machine.h"

int main(int argc, char *argv[]) {
/*
  if(argc <= 2) {
    std::cout << "Usage: " << argv[0] << " -f <filename inside test directory>"  << std::endl;
    return 1;
  }
  */

  std::string path = TEST_RESOURCE_DIR;
  path += "ej2.txt";
  TuringMachine tm = TuringMachine(path);

  while (true) {
    std::string input;
    std::cout << "If you want to EXIT, type 'exit()'" << std::endl;
    std::cout << "If you want to print the Loaded TM definition, type 'print()'" << std::endl;
    std::cout << "Enter input word or command: ";
    std::cin >> input;

    system("clear");

    if(input == "" || input == " ") {
      std::cout << "Empty input" << std::endl;
      continue;
    } else if (input == "exit()") {
      std::cout << "Exiting..." << std::endl;
      break;
    } else if(input == "print()") {
      tm.print();
      std::cout << std::endl;
    } else {
      tm.loadTape(input);
      if(tm.run()) {
        std::cout << "Word Accepted!" << std::endl << std::endl;
        std::cout << "Tape: ";
        tm.printTape();
      } else {
        std::cout << "Word Rejected!" << std::endl << std::endl;
        std::cout << "Tape: ";
        tm.printTape();
      }
    }
  }
  return 0;
}
