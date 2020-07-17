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
#include <radio_tool/fw/fw_factory.hpp>
#include <radio_tool/fw/all_firmware_support.hpp>

using namespace radio_tool::fw;

auto FirmwareFactory::GetFirmwareHandler(const std::string& file) const -> std::unique_ptr<FirmwareSupport>
{
    for(const auto& fn : FirmwareSupports) {
        if(fn.first(file)) {
            return fn.second();
        }
    }
}