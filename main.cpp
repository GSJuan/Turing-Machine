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
  std::string path = TEST_RESOURCE_DIR;
  path += "Ejemplo_MT.txt";
  TuringMachine tm = TuringMachine(path);
  tm.print();
  tm.loadTape("10010010");
  tm.printTape();
  if(tm.run())
    std::cout << "Cadena aceptada" << std::endl;
  else
    std::cout << "Cadena rechazada" << std::endl;
  return 0;
}
