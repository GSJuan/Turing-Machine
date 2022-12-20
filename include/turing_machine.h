/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief class declaration for the turing´s machine automaton
 * @version 0.1
 * @date 2022-18-12
 * SUBJECT: CC
 * PRACTICE: 2
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "alphabet.h"
#include "state.h"
#include "transition.h"
#include "tape.h"

class TuringMachine {
  private:
    Alphabet alphabet_;
    Alphabet tape_alphabet_;

    std::set<State> states_;
    std::set<State> final_states_;

    std::vector<Transition> transitions_;
    std::string white_; 
    Tape tape_;
    State initial_state_;
    State current_state_;
    bool halt_;
    bool accept_;

  public:
    TuringMachine();
    TuringMachine(std::ifstream &file);
    TuringMachine(std::string filename);
    ~TuringMachine();

    void loadMachineFromFile(std::ifstream &in);
    void checkMachine();
    void loadTape(std::string tape);
    bool run();
    void print();
    void printTape();

    void updateHead (Movement);

    std::vector<Transition> getTransitions(std::string symbol, State);
    Transition getTransition(std::string symbol, State);
};

#endif