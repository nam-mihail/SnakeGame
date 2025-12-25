#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

namespace Utils {

    inline sf::Vector2f gridToWorld(sf::Vector2i pos) {
        return sf::Vector2f(
            pos.x * Consts::CellSize + Consts::CellSize / 2.f,
            pos.y * Consts::CellSize + Consts::CellSize / 2.f + Consts::OffSetY
        );
    }

    inline sf::Vector2i worldToGrid(sf::Vector2f pos) {
        return sf::Vector2i(
            static_cast<int>(pos.x / Consts::CellSize),
            static_cast<int>((pos.y - Consts::OffSetY) / Consts::CellSize)
        );
    }

    inline std::string toUtf8String(const sf::String& s) {
        auto u = s.toUtf8();
        return std::string(u.begin(), u.end());
    }

} 
