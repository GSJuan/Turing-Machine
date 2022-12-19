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
#include "alphabet.h"
#include "state.h"
#include "transition.h"
#include "tape.h"

class TuringMachine {
  private:
    Alphabet alphabet_;
    Alphabet tape_alphabet_;
    std::vector<State> states_;
    std::vector<Transition> transitions_;
    Tape tape_;
    State initial_stat_;
    std::vector<State> final_states_;
    State current_state_;
    int head_position_;
    bool halt_;
    bool accept_;

  public:
    TuringMachine();
    TuringMachine(std::ifstream &file);
    TuringMachine(std::string filename);
    ~TuringMachine();

    void loadMachineFromFile(std::ifstream &in);
    void checkMachine();
    void run();
    void print();

    void setAlphabet(Alphabet alphabet);
    void setStates(std::vector<State> states);
    void setTransitions(std::vector<Transition> transitions);
    void setTape(Tape tape);
    void setInitialState(State initial_state);
    void setFinalStates(std::vector<State> final_states);
    void setCurrentState(State current_state);
    void setCurrentPosition(int current_position);
    void setHalt(bool halt);
    void setAccept(bool accept);
  
    Alphabet getAlphabet();
    std::vector<State> getStates();
    std::vector<Transition> getTransitions();
    Tape getTape();
    State getInitialState();
    std::vector<State> getFinalStates();
    State getCurrentState();
    int getCurrentPosition();
    bool getHalt();
    bool getAccept();
};



#endif