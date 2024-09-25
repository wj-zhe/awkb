/*
Copyright 2023 Jz_Wong <@wj-zhe>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Pointing Device */
#ifdef POINTING_DEVICE_ENABLE
#   define SPLIT_POINTING_ENABLE
#   define POINTING_DEVICE_RIGHT
#   define SPI_SCK_PIN GP2
#   define SPI_MOSI_PIN GP3
#   define SPI_MISO_PIN GP4
#   define PMW33XX_CS_PIN GP1
#endif

/* Encoder config */
#ifdef ENCODER_ENABLE
#   define ENCODERS_PAD_A { GP3 }
#   define ENCODERS_PAD_B { GP2 }
#   define ENCODER_RESOLUTIONS { 2 }

// #   define ENCODERS_PAD_A_RIGHT { }
// #   define ENCODERS_PAD_B_RIGHT { }
// #   define ENCODER_RESOLUTIONS_RIGHT { }

/* For 4x encoders you also can assign default position if encoder skips pulses
   when it changes direction. For example, if your encoder send high level on
   both pins by default, define this: */
// #   define ENCODER_DEFAULT_POS 0x3

#endif

