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

#include "charset.h"

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

char callsign_to_ascii(uint8_t c)
{
	if (c >= 0x00 && c <= 0x09) {
		return c + 0x30;
	} else if (c >= 0x0A && c <= 0x23) {
		return c + 0x37;
	} else if (c == 0x24) {
		return ' ';
	} else if (c == 0x25) {
		return '/';
	} else {
		//Invalid char
		return '\0';
	}
}

bool ascii_to_callsign(uint8_t* dest, char src)
{
	if (src >= '0' && src <= '9') {
		*dest = src - 0x30;
	} else if (src >= 'A' && src <= 'Z') {
		*dest = src - 0x37;
	} else if (src >= 'a' && src <= 'z') {
		*dest = src - 0x57;
	} else if (src == ' ') {
		*dest = 0x24;
	} else if (src == '/') {
		*dest = 0x25;
	} else {
		//Invalid char
		return false;
	}
	return true;
}

char beacon_to_ascii(uint8_t c)
{
	if (c >= 0x00 && c <= 0x09) {
		return c + 0x30;
	} else if (c >= 0x0A && c <= 0x23) {
		return c + 0x37;
	} else if (c == 0x24) {
		return ' ';
	} else if (c == 0x25) {
		return '/';
	} else if (c == 0x26) {
		return '\n'; // enter symbol
	} else if (c == 0x27) {
		return '\t'; // -> symbol
	} else {
		//Invalid char
		return '\0';
	}
}

bool ascii_to_beacon(uint8_t* dest, char src)
{
	if (src >= '0' && src <= '9') {
		*dest = src - 0x30;
	} else if (src >= 'A' && src <= 'Z') {
		*dest = src - 0x37;
	} else if (src >= 'a' && src <= 'z') {
		*dest = src - 0x57;
	} else if (src == ' ') {
		*dest = 0x24;
	} else if (src == '/') {
		*dest = 0x25;
	} else if (src == '\n') {
		*dest = 0x26; // enter symbol
	} else if (src == '\t') {
		*dest = 0x27; // -> symbol
	} else {
		//Invalid char
		return false;
	}
	return true;
}

char (*const filter_name_to_ascii)(uint8_t c) = &callsign_to_ascii;
bool (*const ascii_to_filter_name)(uint8_t* dest, char src) = &ascii_to_callsign;