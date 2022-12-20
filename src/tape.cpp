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
  white_ = ".";
  head_position_ = 0;
}

Tape::Tape(std::vector<std::string> tape) {
  tape_ = tape;
}

Tape::Tape(std::vector<std::string> tape, std::string white) {
  tape_ = tape;
  white_ = white;
}

Tape::Tape(std::string tape) {
  for (int i = 0; i < tape.size(); i++) {
    tape_.push_back(tape.substr(i, 1));
  }
}

Tape::Tape(std::string tape , std::string white) {
  for (int i = 0; i < tape.size(); i++) {
    tape_.push_back(tape.substr(i, 1));
  }
  white_ = white;
}

Tape::~Tape() {}

std::vector<std::string> Tape::getTape() const {
  return tape_;
}

void Tape::setTape(std::vector<std::string> tape) {
  tape_ = tape;
}

std::ostream& operator<<(std::ostream& os, const Tape& tape) {
  os << "|";
  for (int i = 0; i < tape.tape_.size(); i++) {
    os << tape.tape_[i] << "|";
  }
  return os;
}

void Tape::write(std::string symbol) {
  if(head_position_ >= tape_.size()) {
    padRight(head_position_ );
  }
  //ojo no poner if else, por algun motivo si head_position es -1
  // entra en el primer condicional y explota
  if(head_position_  < 0) {
    padLeft(head_position_);
    head_position_ = 0;
  }  

  tape_[head_position_ ] = symbol;
}

std::string Tape::read() {
  
  if (this->head_position_ >= this->tape_.size()) {
    padRight(this->head_position_);
  } 
  //ojo no poner if else, por algun motivo si head_position es -1
  // entra en el primer condicional y explota
  if(this->head_position_ < 0) {
    padLeft(this->head_position_);
    this->head_position_ = 0;
  }

  return this->tape_[this->head_position_];
}

void Tape::padRight(int position) {
  for (int i = tape_.size(); i <= position; i++) {
    tape_.push_back(white_);
  }
}

void Tape::padLeft(int position) {
  for (int i = position; i < 0; i++) {
    tape_.insert(tape_.begin(), white_);
  }
}

void Tape::moveRight() {
  head_position_++;
}

void Tape::moveLeft() {
  head_position_--;
}

void Tape::setHeadPosition(int position) {
  head_position_ = position;
}

int Tape::getHeadPosition() {
  return head_position_;
}