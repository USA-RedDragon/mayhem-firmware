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

#include "proc_4fsk_rx.hpp"

#include "event_m4.hpp"

FourFSKRxProcessor::FourFSKRxProcessor() {
}

void FourFSKRxProcessor::execute(const buffer_c8_t& buffer) {
    (void)buffer;
    if (!configured) {
        return;
    }
}

void FourFSKRxProcessor::configure() {
}

void FourFSKRxProcessor::on_message(const Message* const message) {
    switch (message->id) {
        case Message::ID::FourFSKConfigure:
            configured = true;
            break;
        default:
            break;
    }
}

int main() {
    EventDispatcher event_dispatcher{std::make_unique<FourFSKRxProcessor>()};
    event_dispatcher.run();
    return 0;
}
