/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief class declaration for the turing´s machine state
 * @version 0.1
 * @date 2022-18-12
 * SUBJECT: CC
 * PRACTICE: 2
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STATE_H
#define STATE_H

#include <string>
#include <iostream>

class State {

  private: 
    std::string state_;

  public:
    State();
    State(std::string state);
    ~State();

    std::string getState() const;
    void setState(std::string state);

    State& operator=(const State& newState);
    bool operator<(const State& newState) const;
    bool operator==(const State& newState) const;
    bool operator!=(const State& newState) const;

    friend std::ostream& operator<<(std::ostream& os, const State& state);
};

#endif
