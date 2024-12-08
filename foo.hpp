#pragma once

#include "Human.hpp"

#include <algorithm>
#include <list>
#include <vector>

std::vector< char > foo(std::list< Human >& people)
{
    std::vector< char > retval(people.size());
    // Inkrementacja pola `age` za pomoc¹ metody `birthday`
    std::for_each(people.begin(), people.end(), [](Human& person) { person.birthday(); });

    // Wype³nienie wektora znakami 'y' lub 'n' w odwrotnej kolejnoœci
    std::transform(people.rbegin(), people.rend(), retval.begin(), [](const Human& person) {
        return person.isMonster() ? 'n' : 'y';
    });
    return retval;
}
