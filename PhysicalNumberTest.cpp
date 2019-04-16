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
      .setname("*********our test")
      
      
      .setname("input and output testing")
      .CHECK_OK(istringstream("1000[kg]") >> a)
      .CHECK_OK(istringstream("1000[g]") >> b)
      .CHECK_OK(istringstream("60[sec]") >> c)
      .CHECK_OK(istringstream("60[min]") >> d)
      .CHECK_OUTPUT(c,"60[sec]")
      .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)),"2000[kg]")
      .CHECK_OUTPUT((b += PhysicalNumber(9, Unit::KG)),"10000[g]")
      .CHECK_OUTPUT((c += PhysicalNumber(9, Unit::MIN)),"600[sec]")
      .CHECK_OUTPUT((d += PhysicalNumber(1, Unit::HOUR)),"120[min]")
      .CHECK_OK(istringstream("700") >> a)
      .CHECK_OK(istringstream("[kg]700") >> a)
      .CHECK_OK(istringstream("50[TON][TON]") >> a)
      .CHECK_OK(istringstream("[TON]") >> a)
      
      .setname("operator testing")
      .CHECK_OUTPUT(a+PhysicalNumber(1000, Unit::G), "2001[kg]")
      .CHECK_OUTPUT(b-PhysicalNumber(0.010, Unit::TON), "0[g]")
      .CHECK_OUTPUT(c+d, "7800[sec]")
      .CHECK_OUTPUT(d-c, "110[min]")
      .CHECK_OUTPUT((a+=b), "2010[kg]")
      .CHECK_OUTPUT((a-=b), "2000[kg]")
      // .CHECK_OUTPUT(d++c, "130[min]")
      // .CHECK_OUTPUT(d--c, "120[min]")
      .CHECK_OUTPUT(b++, "10000[g]")
      .CHECK_OUTPUT(b--, "10001[g]")

      .setname("different dimensions")
      .CHECK_THROWS(a+c)
      .CHECK_THROWS(a-d)
      .CHECK_THROWS(b+=c)
      .CHECK_THROWS(b-=d)
      .CHECK_THROWS(a+PhysicalNumber(1, Unit::CM))
      .CHECK_THROWS(b-PhysicalNumber(2, Unit::M))
      .CHECK_THROWS(c-PhysicalNumber(2, Unit::KM))
     




      

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
