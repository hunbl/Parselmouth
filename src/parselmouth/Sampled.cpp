/*
 * Copyright (C) 2017  Yannick Jadoul
 *
 * This file is part of Parselmouth.
 *
 * Parselmouth is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Parselmouth is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Parselmouth.  If not, see <http://www.gnu.org/licenses/>
 */

#include "Parselmouth.h"

#include "utils/SignatureCast.h"
#include "utils/pybind11/NumericPredicates.h"

#include <pybind11/numpy.h>

namespace py = pybind11;
using namespace py::literals;

namespace parselmouth {

void Binding<Sampled>::init()
{
	using signature_cast_placeholder::_;

	// TODO Unit handling

	// TODO What about setting these properties? Any desired effect
	def_readonly("nx", &structSampled::nx);

	def_readonly("x1", &structSampled::x1);

	def_readonly("dx", &structSampled::dx);

	def("xs",
		[](Sampled self) {
			py::array_t<double> xs(self->nx);
			auto unchecked = xs.mutable_unchecked<1>();
			for (auto i = 0; i < self->nx; ++i) {
				unchecked(i) = self->x1 + i * self->dx;
			}
			return xs;
		});
}

} // namespace parselmouth
