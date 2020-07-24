/**
 * This file is part of radio_tool.
 * Copyright (c) 2020 Kieran Harkin <kieran+git@harkin.me>
 * 
 * radio_tool is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * radio_tool is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with radio_tool. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include <vector>
#include <stdint.h>
#include <iostream>
#include <sstream>

namespace radio_tool
{
    static auto PrintHex(const std::vector<uint8_t> &data) -> void
    {
        auto c = 1u;

        constexpr auto asciiZero = 0x30;
        constexpr auto asciiA = 0x61 - 0x0a;

        constexpr auto wordSize = 4;
        constexpr auto wordCount = 4;

        char eol_ascii[wordSize * wordCount + 1] = {};
        char aV, bV;
        std::stringstream prnt;
        for (const auto &v : data)
        {
            auto a = v & 0x0f;
            auto b = v >> 4;
            aV = (a <= 9 ? asciiZero : asciiA) + a;
            bV = (b <= 9 ? asciiZero : asciiA) + b;
            prnt << bV << aV << " ";

            auto col = c % (wordSize * wordCount);
            eol_ascii[col] = v >= 32 && v <= 127 ? (char)v : '.';
            if (col == 0 && c != data.size())
            {
                prnt << " " << eol_ascii << std::endl;
            }
            else if (c % wordSize == 0)
            {
                prnt << "  ";
            }
            if(c == data.size()) {
                if(col > 0) 
                {
                    eol_ascii[col + 1] = 0;
                }
                prnt << (col != 0 ? " " : "") << eol_ascii;
            }
            c++;
        }

        std::cerr << prnt.str() << std::endl;
    }

    static constexpr auto _bcd(const uint8_t &c)
    {
        return (c & 0x0f) + ((c >> 4) * 10);
    }

    static constexpr auto _dcb(const uint8_t &c)
    {
        return ((int)(c / 10) * 16) + (c % 10);
    }
} // namespace radio_tool