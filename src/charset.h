/*
 * Copyright (C) 2019 Joan Planella Costa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CHARSET_H
#define CHARSET_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h> 

	/*******************************
	 * CALLSIGN / BEACON CHARSET   *
	 *******************************
	 * '0' = 0x00 [...] '9' = 0x09 *
	 * 'A' = 0x0A [...] 'Z' = 0x23 *
	 * ' ' = 0x24                  *
	 * '/' = 0x25                  *
	 * Only beacon *****************
	 * enter = 0x26                *
	 * '->' = 0x27                 *
	 *******************************
	 * FILTERNAME SAME AS CALLSIGN *
	 ******************************/

	char callsign_to_ascii(uint8_t c);
	bool ascii_to_callsign(uint8_t* dest, char src);
	char beacon_to_ascii(uint8_t c);
	bool ascii_to_beacon(uint8_t* dest, char src);
	extern char (*const filter_name_to_ascii) (uint8_t c);
	extern bool (*const ascii_to_filter_name) (uint8_t* dest, char src);


#ifdef __cplusplus
}
#endif

#endif /* CHARSET_H */

