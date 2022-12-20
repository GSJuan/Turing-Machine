/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief class declaration for the turing´s machine tape
 * @version 0.1
 * @date 2022-18-12
 * SUBJECT: CC
 * PRACTICE: 2
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TAPE_H
#define TAPE_H

#include <string>
#include <vector>
#include <iostream>

class Tape {

  private: 
  std::vector<std::string> tape_;
  std::string white_;
  int head_position_;

  public:
    Tape();
    Tape(std::vector<std::string> tape);
    Tape(std::vector<std::string> tape, std::string white);
    Tape(std::string tape);
    Tape(std::string tape, std::string white);
    ~Tape();

    std::vector<std::string> getTape() const;
    void setTape(std::vector<std::string> tape);

    int getHeadPosition();
    void setHeadPosition(int position);

    friend std::ostream& operator<<(std::ostream& os, const Tape& tape);

    void write(std::string symbol);
    std::string read();
    void padRight(int position);
    void padLeft(int position);
    void moveRight();
    void moveLeft();



};

#endif