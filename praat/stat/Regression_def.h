/* Regression_def.h
 *
 * Copyright (C) 2005-2007,2015 Paul Boersma
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#define ooSTRUCT RegressionParameter
oo_DEFINE_CLASS (RegressionParameter, Daata)

	oo_STRING (label)
	oo_DOUBLE (minimum)
	oo_DOUBLE (maximum)
	oo_DOUBLE (value)
	#if oo_DECLARING || oo_COPYING
		oo_LONG (tableColumnIndex)
	#endif

oo_END_CLASS (RegressionParameter)
#undef ooSTRUCT


#define ooSTRUCT Regression
oo_DEFINE_CLASS (Regression, Daata)

	oo_DOUBLE (intercept)
	oo_AUTO_COLLECTION (Ordered, parameters, RegressionParameter, 0)

	#if oo_DECLARING
		void v_info ()
			override;
	#endif

oo_END_CLASS (Regression)
#undef ooSTRUCT


/* End of file Regression_def.h */