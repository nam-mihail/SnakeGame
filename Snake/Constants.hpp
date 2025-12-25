#pragma once

namespace Consts {

    constexpr int CellSize = 32;

    constexpr int GridWidth = 19;
    constexpr int GridHeight = 19;

    constexpr int OffSetY = 64;
    constexpr int WindowWidth = GridWidth * CellSize;
    constexpr int WindowHeight = GridHeight * CellSize + OffSetY;

    const float CenterX = Consts::WindowWidth / 2.0f;
    const float CenterY = Consts::WindowHeight / 2.0f;
}