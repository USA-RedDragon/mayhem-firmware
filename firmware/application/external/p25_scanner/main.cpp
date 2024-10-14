/*
 * Copyright (C) 2024 Jacob McSwain
 *
 * This file is part of PortaPack.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#include "ui.hpp"
#include "ui_p25_scanner.hpp"
#include "ui_navigation.hpp"
#include "external_app.hpp"

namespace ui::external_app::p25_scanner {
void initialize_app(ui::NavigationView& nav) {
    nav.push<P25ScannerView>();
}
}  // namespace ui::external_app::p25_scanner

extern "C" {

__attribute__((section(".external_app.app_p25_scanner.application_information"), used)) application_information_t _application_information_p25_scanner = {
    /*.memory_location = */ (uint8_t*)0x00000000,
    /*.externalAppEntry = */ ui::external_app::p25_scanner::initialize_app,
    /*.header_version = */ CURRENT_HEADER_VERSION,
    /*.app_version = */ VERSION_MD5,

    /*.app_name = */ "P25Scanner",
    /*.bitmap_data = */ {
        0x00, 0x00,
        0x00, 0x00,
        0x00, 0x00,
        0x00, 0x00,
        0xDE, 0x7B,
        0x12, 0x0A,
        0x12, 0x0A,
        0xDE, 0x7B,
        0x42, 0x40,
        0x42, 0x40,
        0x42, 0x40,
        0xC2, 0x7B,
        0x00, 0x00,
        0x00, 0x00,
        0x00, 0x00,
        0x00, 
    },
    /*.icon_color = */ ui::Color::yellow().v,
    /*.menu_location = */ app_location_t::RX,

    /*.m4_app_tag = portapack::spi_flash::image_tag_4fsk_rx */ {'P', '4', 'K', 'R'},
    /*.m4_app_offset = */ 0x00000000,  // will be filled at compile time
};
}
