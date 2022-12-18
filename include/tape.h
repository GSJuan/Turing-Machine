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

class Tape {

  private: 
  std::vector<std::string> tape_;

  public:
    Tape();
    Tape(std::vector<std::string> tape);
    ~Tape();

    std::vector<std::string> getTape() const;
    void setTape(std::vector<std::string> tape);

    friend std::ostream& operator<<(std::ostream& os, const Tape& tape);

    void write(std::string symbol, int position);
    std::string read(int position);
    void padRight(int position);

};

#endif