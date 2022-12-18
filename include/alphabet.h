/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief class declaration for automaton alphabet
 * @version 0.1
 * @date 2022-18-12
 * SUBJECT: CC
 * PRACTICE: 2
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <set>

class Alphabet {

  private: 
    std::set<std::string> alphabet_;

  public:
    Alphabet();
    Alphabet(std::set<std::string> alphabet);
    ~Alphabet();

    std::set<std::string> getAlphabet() const;
    void setAlphabet(std::set<std::string> alphabet);
    void addSymbol(std::string symbol);
    bool isSymbol(std::string symbol);

    Alphabet& operator= (const Alphabet& newAlphabet);

    friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);
};

#endif