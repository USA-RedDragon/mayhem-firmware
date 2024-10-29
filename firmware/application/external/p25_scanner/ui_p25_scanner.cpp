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

#include "ui_p25_scanner.hpp"

#include "baseband_api.hpp"
#include "portapack_persistent_memory.hpp"

using namespace portapack;
using namespace ui;

namespace ui::external_app::p25_scanner {

void P25ScannerView::focus() {
    field_lna.focus();
}

P25ScannerView::P25ScannerView(NavigationView& nav)
    : nav_{nav} {
    // baseband::run_image(portapack::spi_flash::image_tag_4fsk_rx);
    baseband::run_prepared_image(portapack::memory::map::m4_code.base());

    add_children({&labels,
                  &field_lna,
                  &field_vga,
                  &field_rf_amp,
                  &rssi,
                  &field_volume,
                  &field_frequency,
                });

    baseband::set_4fsk();

    receiver_model.enable();
}

P25ScannerView::~P25ScannerView() {
    receiver_model.disable();
    baseband::shutdown();
}

}  // namespace ui::external_app::p25_scanner