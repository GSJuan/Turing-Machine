/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief class definition for automaton alphabet
 * @version 0.1
 * @date 2022-18-12
 * SUBJECT: CC
 * PRACTICE: 2
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "alphabet.h"

Alphabet::Alphabet() {}

Alphabet::~Alphabet() {
  alphabet_.clear();
}

Alphabet::Alphabet(std::set<std::string> alphabet) {
  alphabet_ = alphabet;
}


std::set<std::string> Alphabet::getAlphabet() const {
  return alphabet_;
}

void Alphabet::setAlphabet(std::set<std::string> alphabet) {
  alphabet_ = alphabet;
}

void Alphabet::addSymbol(std::string symbol) {
  alphabet_.insert(symbol);
}

bool Alphabet::isSymbol(std::string symbol) {
  return alphabet_.find(symbol) != alphabet_.end();
}

Alphabet& Alphabet::operator= (const Alphabet& newAlphabet) {
  alphabet_ = newAlphabet.getAlphabet();
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  os << "Alphabet: {";
  for (auto it = alphabet.alphabet_.begin(); it != alphabet.alphabet_.end(); ++it) {
    os << *it;
    if (it != --alphabet.alphabet_.end()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}
