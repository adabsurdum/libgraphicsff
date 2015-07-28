
/**
  * Readers/writers for some (mostly trivial) graphics file formats. 
  * Copyright (C) 2015  Roger Kramer
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

#ifndef _pnm_h_
#define _pnm_h_

int pnm_write( FILE *fp, const uint8_t *rgb, int w, int h, const char *comment );
int pnm_save( const char *name, const uint8_t *buf, int w, int h, const char *comment );

#endif

