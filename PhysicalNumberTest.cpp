/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    PhysicalNumber e(10, Unit::TON);
    PhysicalNumber f(500, Unit::KG);
    PhysicalNumber g(5000, Unit::G);
    PhysicalNumber h(500, Unit::CM);
    PhysicalNumber i(600, Unit::SEC);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

      .setname("...")
      .setname("Basic input")
      .CHECK_OK(istringstream("5[km]") >> a)
      .CHECK_OUTPUT((a += PhysicalNumber(2, Unit::KM)), "7[km]")

      .setname("Basic output")
      .CHECK_OUTPUT(e, "10[ton]")
      .CHECK_OUTPUT(f, "500[kg]")
      .CHECK_OUTPUT(g, "5000[g]")
      .CHECK_OUTPUT(h, "500[cm]")
      .CHECK_OUTPUT(i, "600[sec]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+h, "305[m]")
    .CHECK_OUTPUT((a+=h), "7.005[km]")
    .CHECK_OUTPUT(a, "7.005[km]")
    .CHECK_OUTPUT(a+a, "14.010[km]")
    .CHECK_OUTPUT(h-h, "0[cm]")
    .CHECK_OUTPUT(i+c, "432600[sec]")
    .CHECK_OUTPUT(d-i, "20[min]")
    .CHECK_OUTPUT(d+c, "150[min]")
    .CHECK_OUTPUT(e+f, "10.5[ton]")
    .CHECK_OUTPUT(f-g, "495[kg]")
    .CHECK_OUTPUT(g-g, "0[g]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+g)
    .CHECK_THROWS(e+c)
    .CHECK_THROWS(f+d)
    .CHECK_THROWS(i+f)

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
