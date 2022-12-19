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

#include "turing_machine.h"

// Helper
// Given a string, return a vector of strings with the symbols of the string separated by the given delimiter
std::set<State> stateSetSplit(std::string str, char delimiter) {
  std::set<State> internal;
  std::istringstream iss(str); // Turn the string into a stream.
  std::string tok;
  
  while(std::getline(iss, tok, delimiter)) {
    internal.insert(State(tok));
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
  std::set<std::string> internal;
  std::istringstream iss(str); // Turn the string into a stream.
  std::string tok;
  
  while(std::getline(iss, tok, delimiter)) {
    internal.insert(tok);
  }
  return internal;
}

TuringMachine::TuringMachine() {
  alphabet_ = Alphabet();
  states_ = std::set<State>();
  final_states_ = std::set<State>();
  transitions_ = std::vector<Transition>();
  tape_ = Tape();
  initial_state_ = State();
  current_state_ = State();
  white_ = ".";
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

TuringMachine::TuringMachine(std::ifstream &file) {
  if(!file.is_open()) {
    std::cerr << "Error opening file " << std::endl;
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
  states_ = stateSetSplit(line, ' ');

  // Reading the alphabet
  std::getline(in, line);
  line = line.substr(0, line.find('#'));
  alphabet_ = Alphabet(setSplit(line, ' '));

  // Reading tape alphabet
  std::getline(in, line);
  line = line.substr(0, line.find('#'));
  tape_alphabet_ = Alphabet(setSplit(line, ' '));

  // Reading initial state 
  std::getline(in, line);
  line = line.substr(0, line.find('#'));
  initial_state_ = State(line);

  // Reading white symbol
  std::getline(in, line);
  line = line.substr(0, line.find('#'));
  white_ = line;

  // Reading final states
  std::getline(in, line);
  line = line.substr(0, line.find('#'));
  final_states_ = stateSetSplit(line, ' ');

  // Reading transitions
  while(std::getline(in, line)) {
    line = line.substr(0, line.find('#'));
    if(line != "") {
      std::vector<std::string> transition = vectorSplit(line, ' ');
      transitions_.push_back(Transition(State(transition[0]), transition[1], State(transition[2]), transition[3], Movement(transition[4])));
    }
  }
}

void TuringMachine::checkMachine() {
  // Checking if the states are in the alphabet
  if(states_.find(initial_state_) == states_.end()) {
    std::cerr << "Error: initial state not in states" << std::endl;
    exit(2);
  }

  for(auto state : final_states_) {
    if(states_.find(state) == states_.end()) {
      std::cerr << "Error: final state " << state << " not in states" << std::endl;
      exit(2);
    }
  }

  // Checking if the transitions are valid
  for(auto transition : transitions_) {
    if(states_.find(transition.getState()) == states_.end()) {
      std::cerr << "Error: transition origin " << transition.getState() << " not in states" << std::endl;
      exit(2);
    }

    if(states_.find(transition.getNextState()) == states_.end()) {
      std::cerr << "Error: transition destination " << transition.getNextState() << " not in states" << std::endl;
      exit(2);
    }

    if(!alphabet_.isSymbol(transition.getSymbol()) && transition.getSymbol() != ".") {
      std::cerr << "Error: transition read " << transition.getSymbol() << " not in alphabet" << std::endl;
      exit(2);
    }

    if(!tape_alphabet_.isSymbol(transition.getNextSymbol())) {
      std::cerr << "Error: transition write " << transition.getNextSymbol() << " not in tape alphabet" << std::endl;
      exit(2);
    }

    if(transition.getMovement().getMovement() != "L" && 
      transition.getMovement().getMovement() != "R" && 
      transition.getMovement().getMovement() != "S") {
        std::cerr << "Error: transition movement " << transition.getMovement() <<
        " not valid" << std::endl << "Valid movement formats are L, R and S" << std::endl;
        exit(2);
    }
  }
}

void TuringMachine::loadTape(std::string tape) {
  tape_ = Tape(tape, white_);
}

bool TuringMachine::run() {
  if(tape_.getTape().size() == 0) {
    std::cerr << "Error: tape not loaded" << std::endl;
    exit(3);
  }
  int infiniteLoop = 0;
  current_state_ = initial_state_;
  head_position_ = 0;
  halt_ = false;
  accept_ = false;

  while(!halt_) {
    infiniteLoop++;
    if(infiniteLoop > 100000) {
      return false;
    }
    std::string current_symbol = tape_.read(head_position_);
    Transition transition = getTransition(current_symbol, current_state_);
    if(transition.getSymbol() == "") {
      halt_ = true;
    } else {
      tape_.write(transition.getNextSymbol(), head_position_);
      updateHead(transition.getMovement());
      current_state_ = transition.getNextState();
    }
  }

  if(final_states_.find(current_state_) != final_states_.end()) {
    accept_ = true;
  }

  return accept_; 
}

void TuringMachine::print() {
  std::cout << "States: ";
  for(auto state : states_) {
    std::cout << state << " ";
  }
  std::cout << std::endl;

  std::cout << "Alphabet: ";
  std::cout << alphabet_;
  std::cout << std::endl;

  std::cout << "Tape alphabet: ";
  std::cout << tape_alphabet_;
  std::cout << std::endl;

  std::cout << "Initial state: " << initial_state_ << std::endl;

  std::cout << "White symbol: " << white_ << std::endl;

  std::cout << "Final states: ";
  for(auto state : final_states_) {
    std::cout << state << " ";
  }
  std::cout << std::endl;

  std::cout << "Transitions: " << std::endl;
  for(auto transition : transitions_) {
    std::cout << transition << std::endl;
  }
}

void TuringMachine::printTape() {
  std::cout << "Tape: " << tape_ << std::endl;
}

void TuringMachine::updateHead(Movement movement) {
  if(movement.getMovement() == "L") {
    head_position_--;
  } else if(movement.getMovement() == "R") {
    head_position_++;
  }
}

std::vector<Transition> TuringMachine::getTransitions(std::string symbol, State state) {
  std::vector<Transition> transitions;
  for(auto transition : transitions_) {
    if(transition.getSymbol() == symbol && transition.getState() == state) {
      transitions.push_back(transition);
    }
  }
  return transitions;
}

Transition TuringMachine::getTransition(std::string symbol, State state) {
  Transition transitions;
  for(auto transition : transitions_) {
    if(transition.getSymbol() == symbol && transition.getState() == state) {
      return transition;
    }
  }
  return Transition();
}