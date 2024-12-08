#pragma once

#include "Human.hpp"

#include <algorithm>
#include <list>
#include <vector>

std::vector< char > foo(std::list< Human >& people)
{
    std::vector< char > retval(people.size());
    // Inkrementacja pola `age` za pomoc� metody `birthday`
    std::for_each(people.begin(), people.end(), [](Human& person) { person.birthday(); });

    // Wype�nienie wektora znakami 'y' lub 'n' w odwrotnej kolejno�ci
    std::transform(people.rbegin(), people.rend(), retval.begin(), [](const Human& person) {
        return person.isMonster() ? 'n' : 'y';
    });
    return retval;
}
