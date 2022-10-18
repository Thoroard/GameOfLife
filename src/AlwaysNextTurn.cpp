//
// Created by Xardav on 18.05.2022.
//
#include "GOF.hpp"

#include <chrono> // dostarcza literał ms
#include <thread> // dostarcza sleep_for


std::string AlwaysNextTurn::next_command() {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(300ms);

    if (turns_played++ > 50)
        return "quit";
        
    return "next";
}

