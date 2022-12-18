/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief class definition for the turing´s machine movement
 * @version 0.1
 * @date 2022-18-12
 * SUBJECT: CC
 * PRACTICE: 2
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "movement.h"

Movement::Movement() {}

Movement::Movement(std::string movement) {
  movement_ = movement;
}

Movement::~Movement() {}

std::string Movement::getMovement() const {
  return movement_;
}

void Movement::setMovement(std::string movement) {
  movement_ = movement;
}

Movement& Movement::operator= (const Movement& newMovement) {
  movement_ = newMovement.getMovement();
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Movement& movement) {
  os << movement.movement_;
  return os;
}
