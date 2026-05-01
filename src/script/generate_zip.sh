#!/usr/bin/env bash

project_name='prog3_unit2_template_clases_v2026_01'
source_code='
  include/array_wrapper.h
  include/tuple_printer.h
  include/static_matrix.h
  include/type_list.h
  include/serializer.h
  include/fixed_point.h
  include/logger.h
  include/polynomial.h
  include/smart_array.h
  include/unit.h
  '
cd ../.. || exit 1
rm -f ${project_name}.zip
zip -r -S ${project_name} ${source_code}
