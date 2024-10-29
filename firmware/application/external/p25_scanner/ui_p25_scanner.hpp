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

#ifndef __UI_P25_SCANNER_H__
#define __UI_P25_SCANNER_H__

#include "ui.hpp"
#include "ui_freq_field.hpp"
#include "ui_navigation.hpp"
#include "ui_receiver.hpp"

using namespace ui;

namespace ui::external_app::p25_scanner {

class P25ScannerView : public View {
   public:
    P25ScannerView(NavigationView& nav);
    ~P25ScannerView();

    std::string title() const override { return "P25 Scanner"; };
    void focus() override;

   private:
    NavigationView& nav_;
    Labels labels{
        {{0 * 8, 0 * 8}, "LNA:   VGA:   AMP:", Theme::getInstance()->fg_light->foreground}};

    LNAGainField field_lna{
        {4 * 8, 0 * 16}};

    VGAGainField field_vga{
        {11 * 8, 0 * 16}};

    RFAmpField field_rf_amp{
        {18 * 8, 0 * 16}};

    RSSI rssi{
        {20 * 8, 4, 7 * 8, 8},
    };

    AudioVolumeField field_volume{
        {28 * 8, 0 * 16}};

    RxFrequencyField field_frequency{
        {0 * 8, 1 * 16},
        nav_};
};

}  // namespace ui::external_app::p25_scanner

#endif /*__UI_P25_SCANNER_H__*/
