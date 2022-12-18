/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief class declaration for the turing´s machine movement
 * @version 0.1
 * @date 2022-18-12
 * SUBJECT: CC
 * PRACTICE: 2
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <string>
#include <iostream>

class Movement {

  private:
    std::string movement_;

  public:
    Movement();
    Movement(std::string movement);
    ~Movement();

    std::string getMovement() const;
    void setMovement(std::string movement);

    Movement& operator= (const Movement& newMovement);

    friend std::ostream& operator<<(std::ostream& os, const Movement& movement);
};

#endif