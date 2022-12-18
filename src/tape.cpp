/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief class definition for the turing´s machine tape
 * @version 0.1
 * @date 2022-18-12
 * SUBJECT: CC
 * PRACTICE: 2
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "tape.h"

Tape::Tape() {
  tape_ = {};
}

Tape::Tape(std::vector<std::string> tape) {
  tape_ = tape;
}

Tape::~Tape() {}

std::vector<std::string> Tape::getTape() const {
  return tape_;
}

void Tape::setTape(std::vector<std::string> tape) {
  tape_ = tape;
}

std::ostream& operator<<(std::ostream& os, const Tape& tape) {
  for (int i = 0; i < tape.tape_.size(); i++) {
    os << tape.tape_[i];
  }
  return os;
}

void Tape::write(std::string symbol, int position) {
  if(position >= tape_.size())
    padRight(position);
  tape_[position] = symbol;
}

std::string Tape::read(int position) {
  if(position >= tape_.size())
    padRight(position);
  return tape_[position];
}

void Tape::padRight(int position) {
  for (int i = tape_.size(); i <= position; i++) {
    tape_.push_back(" ");
  }
}
