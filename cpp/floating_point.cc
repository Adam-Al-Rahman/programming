/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Floaint Point Approximation
 * @brief: How floating point works
 * @source:
 * @tags: ["topics/floating_point", "algorithms/", "methods/"]
 * @status: solved
 */

#include <cfloat>
#include <cfloat>  // FLT_DIG,..
#include <iostream>

float max_float = FLT_MAX;          // Maximum finite value of a float
float min_float = FLT_MIN;          // Minimum positive value of a float
float epsilon_float = FLT_EPSILON;  // Smallest difference between 1 and the next representable float

int float_digits = FLT_DIG;         // Decimal digits of precision for float
int double_digits = DBL_DIG;        // Decimal digits of precision for double
int long_double_digits = LDBL_DIG;  // Decimal digits of precision for long double

int float_mantissa_bits = FLT_MANT_DIG;         // Mantissa bits for float
int double_mantissa_bits = DBL_MANT_DIG;        // Mantissa bits for double
int long_double_mantissa_bits = LDBL_MANT_DIG;  // Mantissa bits for long double

double max_double = DBL_MAX;          // Maximum finite value of a double
double min_double = DBL_MIN;          // Minimum positive value of a double
double epsilon_double = DBL_EPSILON;  // Smallest difference between 1 and the next representable double

int main() {
  float x1 = 1.3;
  if (x1 == 1.3)
    std::cout << "True";
  else
    std::cout << "false";
}
