
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

#include <stdio.h>
//#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
//#include <err.h>
//#include <string.h>

int pnm_write( FILE *fp, const uint8_t *rgb, int w, int h, const char *comment ) {

	int wr;

	if( comment )
		wr = fprintf( fp, "P3\n%d %d\n# %s\n255\n", w, h, comment  );
	else
		wr = fprintf( fp, "P3\n%d %d\n255\n", w, h  );

	if( wr < 0 )
		return -1;

	for(int r = 0; r < h; r++ ) {
		const char *sep = "";
		for(int c = 0; c < w; c++ ) {
			int red = *rgb++;
			int grn = *rgb++;
			int blu = *rgb++;
			fprintf( fp, "%s%d %d %d", sep, red, grn, blu );
			sep = " ";
		}
		fputc( '\n', fp );
	}
	return 0;
}


int pnm_save( const char *name, const uint8_t *buf, int w, int h, const char *comment ) {

	FILE *fp = fopen( name, "w" );
	if( fp ) {
		pnm_write( fp, buf, w, h, comment );
		fclose( fp );
		return 0;
	}
	return -1;
}

