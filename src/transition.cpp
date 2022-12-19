/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief class definition for the turing´s machine transition
 * @version 0.1
 * @date 2022-18-12
 * SUBJECT: CC
 * PRACTICE: 2
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "transition.h"

Transition::Transition() {}

Transition::Transition(State state, std::string symbol, State nextState, std::string newSymbol, Movement movement) {
  state_ = state;
  symbol_ = symbol;
  next_state_ = nextState;
  next_symbol_ = newSymbol;
  movement_ = movement;
}

Transition::~Transition() {}

State Transition::getState() const {
  return state_;
}

void Transition::setState(State state) {
  state_ = state;
}

std::string Transition::getSymbol() const {
  return symbol_;
}

void Transition::setSymbol(std::string symbol) {
  symbol_ = symbol;
}

State Transition::getNextState() const {
  return next_state_;
}

void Transition::setNextState(State nextState) {
  next_state_ = nextState;
}

std::string Transition::getNextSymbol() const {
  return next_symbol_;
}

void Transition::setNextSymbol(std::string newSymbol) {
  next_symbol_ = newSymbol;
}

Movement Transition::getMovement() const {
  return movement_;
}

void Transition::setMovement(Movement movement) {
  movement_ = movement;
}

Transition& Transition::operator= (const Transition& newTransition) {
  state_ = newTransition.getState();
  symbol_ = newTransition.getSymbol();
  next_state_ = newTransition.getNextState();
  next_symbol_ = newTransition.getNextSymbol();
  movement_ = newTransition.getMovement();
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Transition& transition) {
  os << "(" << transition.getState() << ", " << transition.getSymbol() << ") ---> (" << transition.getNextState()
  << ", " << transition.getNextSymbol() << ", " << transition.getMovement() << ")";
  return os;
}
