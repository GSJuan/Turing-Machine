/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief class definition for the turing´s machine automaton
 * @version 0.1
 * @date 2022-18-12
 * SUBJECT: CC
 * PRACTICE: 2
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "turingMachine.h"

// Helper
// Given a string, return a vector of strings with the symbols of the string separated by the given delimiter
std::vector<State> stateVectorSplit(std::string str, char delimiter) {
  std::vector<std::string> internal;
  std::istringstream iss(str); // Turn the string into a stream.
  std::string tok;
  
  while(std::getline(iss, tok, delimiter)) {
    internal.push_back(new State(tok));
  }
  return internal;
}

// Helper
// Given a string, return a vector of strings with the symbols of the string separated by the given delimiter
std::vector<std::string> vectorSplit(std::string str, char delimiter) {
  std::vector<std::string> internal;
  std::istringstream iss(str); // Turn the string into a stream.
  std::string tok;
  
  while(std::getline(iss, tok, delimiter)) {
    internal.push_back(tok);
  }
  return internal;
}

// Helper
// Given a string, return a set with the symbols of the string separated by the given delimiter
std::set<std::string> setSplit(std::string str, char delimiter) {
  std::unordered_set<std::string> internal;
  std::istringstream iss(str); // Turn the string into a stream.
  std::string tok;
  
  while(std::getline(iss, tok, delimiter)) {
    internal.insert(tok);
  }
  return internal;
}

TuringMachine::TuringMachine() {
  alphabet_ = Alphabet();
  states_ = std::vector<State>();
  transitions_ = std::vector<Transition>();
  tape_ = Tape();
  initial_stat_ = State();
  final_states_ = std::vector<State>();
  current_state_ = State();
  head_position_ = 0;
  halt_ = false;
  accept_ = false;
}

TuringMachine::TuringMachine(std::string filename) {
  std::ifstream file(filename, std::ios::in);
  if(!file.is_open()) {
    std::cerr << "Error opening file " << filename << std::endl;
    exit(1);
  }
  loadMachineFromFile(file);
  file.close();
  checkMachine();
}
TuringMachine::TuringMachine(std::ifstream file) {
  if(!file.is_open()) {
    std::cerr << "Error opening file " << filename << std::endl;
    exit(1);
  }
  loadMachineFromFile(file);
  file.close();
  checkMachine();
}

TuringMachine::~TuringMachine() {}

void TuringMachine::loadMachineFromFile(std::ifstream &in) {
  std::string line;

  // Reading the comments
  do {
    std::getline(in, line);
    line = line.substr(0, line.find('#'));
  } while(line == "");

  // Reading the states
  states_ = stateVectorSplit(line, ' ');

  // Reading the alphabet
  std::getline(in, line);
  alphabet_ = new Alphabet(setSplit(line, ' '));


}