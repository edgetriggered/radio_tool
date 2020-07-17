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

#include <radio_tool/radio/tyt_radio.hpp>

#include <vector>
#include <functional>

namespace radio_tool::radio
{
    /**
     * A list of functions to test each radio handler
     */
    const std::vector<std::pair<std::function<bool(const libusb_device_descriptor &)>, std::function<std::unique_ptr<RadioSupport>()>>> RadioSupports = {
        { TYTRadio::SupportsDevice, []() { return std::make_unique<TYTRadio>(); } }
    };
}