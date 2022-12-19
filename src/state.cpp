/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief class definition for the turing´s machine state
 * @version 0.1
 * @date 2022-18-12
 * SUBJECT: CC
 * PRACTICE: 2
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "state.h"

State::State() {}

State::State(std::string state) {
  state_ = state;
}

State::~State() {}

std::string State::getState() const {
  return state_;
}

void State::setState(std::string state) {
  state_ = state;
}

State& State::operator= (const State& newState) {
  state_ = newState.getState();
  return *this;
}

bool State::operator<(const State& newState) const {
  if (getState() < newState.getState())
    return true;
  else
    return false;
}

bool State::operator==(const State& newState) const {
  if (getState() == newState.getState())
    return true;
  else
    return false;
}

bool State::operator!=(const State& newState) const {
  if (getState() != newState.getState())
    return true;
  else
    return false;
}

std::ostream& operator<<(std::ostream& os, const State& state) {
  os << state.state_;
  return os;
}