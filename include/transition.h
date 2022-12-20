/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief class declaration for the turing´s machine transition
 * @version 0.1
 * @date 2022-18-12
 * SUBJECT: CC
 * PRACTICE: 2
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TRANSITION_H
#define TRANSITION_H

#include "state.h"
#include "movement.h"

class Transition {

  private:
    State state_;
    std::string symbol_;
    State next_state_;
    std::string next_symbol_;
    Movement movement_;

  public:
    Transition();
    Transition(State state, std::string symbol, State next_state, std::string next_symbol, Movement movement);
    ~Transition();

    State getState() const;
    void setState(State state);

    std::string getSymbol() const;
    void setSymbol(std::string symbol);

    State getNextState() const;
    void setNextState(State next_state);

    std::string getNextSymbol() const;
    void setNextSymbol(std::string next_symbol);
    
    Movement getMovement() const;
    void setMovement(Movement movement);

    Transition& operator= (const Transition& newTransition);

    friend std::ostream& operator<<(std::ostream& os, const Transition& transition);
};

#endif