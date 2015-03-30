#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctype.h>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <cstdlib>
//
//
using namespace std;
//
#include "matrix_class.h"
//
void minimum_tests( bool &, bool & , int &, int &, int & );
void constructor_destructor_tests( bool &, bool & , int &, int &, int & );
void create_tests( bool &, bool & , int &, int &, int & );
void assignment_tests( bool &, bool & , int &, int &, int & );
void equals_equality_tests( bool &, bool & , int &, int &, int & );
void more_gets_sets_tests( bool &, bool & , int &, int &, int & );
void matrix_math_tests( bool &, bool & , int &, int &, int & );
void binary_read_write_tests( bool &, bool & , int &, int &, int & );
void print_cout_tests( bool &, bool & , int &, int &, int & );
void check_fatal( bool );

//***************************************************************************
//
//               main
//
//***************************************************************************
//
//
int main() {
//
   bool error = false;
   bool fatal_error = false;
//
   int count_pass = 0;
   int count_fail_reg = 0;
   int count_fail_fatal = 0;
//
   cout << "\n\n\n";
   cout << "Note: if at any point this program fails with a segfault it means" << endl;
   cout << "you are not initializing your storage properly or you have" << endl;
   cout << "an off by 1 error. " << endl;
//
   cout << "Begin checking your matrix class:\n\n" << endl;
//
   minimum_tests( error, fatal_error, count_pass, count_fail_reg,
                  count_fail_fatal );
   check_fatal( fatal_error );
//
   constructor_destructor_tests( error, fatal_error, count_pass,
                                 count_fail_reg, count_fail_fatal );
   check_fatal( fatal_error );
//
   create_tests( error, fatal_error, count_pass,
                 count_fail_reg, count_fail_fatal );
   check_fatal( fatal_error );
//
   assignment_tests( error, fatal_error, count_pass,
                     count_fail_reg, count_fail_fatal );
   check_fatal( fatal_error );
//
   equals_equality_tests( error, fatal_error, count_pass,
                          count_fail_reg, count_fail_fatal );
   check_fatal( fatal_error );
//
   more_gets_sets_tests( error, fatal_error, count_pass,
                         count_fail_reg, count_fail_fatal );
   check_fatal( fatal_error );
//
   matrix_math_tests( error, fatal_error, count_pass,
                      count_fail_reg, count_fail_fatal );
   check_fatal( fatal_error );
//
   binary_read_write_tests( error, fatal_error, count_pass,
                            count_fail_reg, count_fail_fatal );
                            check_fatal( fatal_error );
   check_fatal( fatal_error );
//
   print_cout_tests( error, fatal_error, count_pass,
                     count_fail_reg, count_fail_fatal );
   check_fatal( fatal_error );
//
//  summary report
//
   cout << endl;
   int total_fail = count_fail_reg + count_fail_fatal;
   cout << count_pass << " tests passed and " << total_fail << " tests failed." << endl;
   cout << "\nAll done...\n\n";
   exit(0);
//
}
//***************************************************************************
//
//               check_fatal
//
//***************************************************************************
//
//
void check_fatal( bool fatal_error )
{
      if (fatal_error)
       {
            cout << "Fatal error: no point continuing" << endl;
            exit(0);
       }
}
//***************************************************************************
//
//               minimum_tests
//
//***************************************************************************
//
//
 void minimum_tests( bool & error, bool & fatal_error, int & count_pass,
                     int & count_fail_reg, int & count_fail_fatal )
{
      cout << "\tBasic Tests:" << endl;
      // Check types
      try {
            matrix <int> A;
            matrix <double> B;
            matrix <float> C;
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tTypes: int, double, and float\t\t";
      if (error) {
            count_fail_fatal++;
            fatal_error = true;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Default constructor and gets
      try {
            matrix <int> A;
            string name;
            int m,n;
            m = A.get_num_rows();
            n = A.get_num_cols();
            name = A.get_name();
            // Of course we really do not know these worked properly.
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tConstructor, get rows, cols, name.\t";
      if (error) {
            count_fail_fatal++;
            fatal_error = true;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;
      return;
}

//***************************************************************************
//
//               constructor_destructor_tests
//
//***************************************************************************
//
//
void  constructor_destructor_tests( bool & error, bool & fatal_error,
                                    int & count_pass, int & count_fail_reg,
                                    int & count_fail_fatal )
{
     	cout << "\tChecking constructors:" << endl;
      // Default
      try {
            matrix <int> A;
            matrix <double> B;
            matrix <float> C;
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tDefault constructor\t\t\t";
      if (error) {
            count_fail_fatal++;
            fatal_error = true;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // One int
      try {
            matrix <int> A(4);
            matrix <double> B(4);
            if (A.get_num_rows()!=4) throw(1);
            if (B.get_num_cols()!=1) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\t(int) argument constructor\t\t";
      if (error) {
            count_fail_fatal++;
            fatal_error = true;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // 2 ints
      try {
            matrix <int> A(4,3);
            matrix <double> B(4,3);
            if (A.get_num_rows()!=4) throw(1);
            if (B.get_num_cols()!=3) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\t(int,int) argument constructor\t\t";
      if (error) {
            count_fail_fatal++;
            fatal_error = true;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

         // String int ........

      try {
            matrix <int> A("vector",3);
            matrix <double> B("vector",3);
            if (A.get_num_rows()!=3) throw(1);
            if (B.get_num_cols()!=1) throw(1);
            if (A.get_name().compare("vector")!=0) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\t(string, int) argument constructor\t";
      if (error) {
            count_fail_fatal++;
            fatal_error = true;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // String int, int
      try {
            matrix <int> A("matrix",3,4);
            matrix <double> B("matrix",3,4);
            if (A.get_num_rows()!=3) throw(1);
            if (B.get_num_cols()!=4) throw(1);
            if (A.get_name().compare("matrix")!=0) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\t(string, int, int) argument constructor\t";
      if (error) {
            count_fail_fatal++;
            fatal_error = true;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;


        // Copy  ........

      try {
            matrix <int> A("matrix",3,4);
            matrix <int> B(A);
            if (A.get_num_rows() != B.get_num_rows()) throw(1);
            if (A.get_num_cols() != B.get_num_cols()) throw(1);
            if (A.get_name().compare(B.get_name())!=0) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tCopy constructor\t\t\t";
      if (error) {
            count_fail_fatal++;
            fatal_error = true;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;
      return;
}
//***************************************************************************
//
//               create_tests
//
//***************************************************************************
//
//
void create_tests( bool & error, bool & fatal_error,
                   int & count_pass, int & count_fail_reg,
                   int & count_fail_fatal )
{
      cout << "\tChecking create methods and free:" << endl;
      // One int
      try {
            matrix <int> A;
            matrix <double> B;
            A.create(4);
            B.create(4);
            if (A.get_num_rows()!=4) throw(1);
            if (B.get_num_cols()!=1) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\t(int) argument create\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

       // Two ints .....

      try {
            matrix <int> A;
            matrix <double> B;
            A.create(4,3);
            B.create(4,3);
            if (A.get_num_rows()!=4) throw(1);
            if (B.get_num_cols()!=3) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\t(int,int) argument create\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

          // String int   ........

      try {
            matrix <int> A;
            matrix <double> B;
            A.create("vector",3);
            B.create("vector",3);
            if (A.get_num_rows()!=3) throw(1);
            if (B.get_num_cols()!=1) throw(1);
            if (A.get_name().compare("vector")!=0) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\t(string,int) argument create\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // String int int
      try {
            matrix <int> A;
            A.create("matrix",3,4);
            matrix <double> B;
            B.create("matrix",3,4);
            if (A.get_num_rows()!=3) throw(1);
            if (B.get_num_cols()!=4) throw(1);
            if (A.get_name().compare("matrix")!=0) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\t(string,int,int) argument create\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // I'm not sure how to check free
      try {
            matrix <int> A("freeme",3,4);
            A.free();
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tFree\t\t\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;
      return;
}

//***************************************************************************
//
//               assignment_tests
//
//***************************************************************************
//
//
void assignment_tests( bool & error, bool & fatal_error,
                   int & count_pass, int & count_fail_reg,
                   int & count_fail_fatal )
{

      cout << "\t Checking various sets and gets:" << endl;
      // Parentheses
      try {
            matrix <int> A(3);
            A(2) = 1;
            if (A(2) != 1) throw(1);
            A(1) = -1;
            if (A(1) != -1) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\toverloaded (int) argument get/set\t";
      if (error) {
            fatal_error = true;
            count_fail_fatal++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Parentheses
      try {
            matrix <int> A(3,3);
            A(2,2) = 1;
            if (A(2,2) != 1) throw(1);
            A(1,1) = -1;
            if (A(1,1) != -1) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\toverloaded (int,int) argument get/set\t";
      if (error) {
            fatal_error = true;
            count_fail_fatal++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // set_value(T)
      try {
            matrix <int> A(3,3);
            A.set_value(1);
            for (int i=1; i<=3; i++)
                  for (int j=1; j<=3; j++)
                        if (A(i,j)!=1) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\t(T) argument set\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // set_value(int, T)
      try {
            matrix <int> A(3);
            A.set_value(3,1);
            if (A(3,1) != 1) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\t(int,T) argument set\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // set_value(int, int, T)
      try {
            matrix <int> A(3,4);
            A.set_value(3,4,1);
            if (A(3,4) != 1) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\t(int, int, T) argument set\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;
      return;
}
//***************************************************************************
//
//               equals_equality_tests
//
//***************************************************************************
//
//
void equals_equality_tests( bool & error, bool & fatal_error,
                   int & count_pass, int & count_fail_reg,
                   int & count_fail_fatal )
{
      cout << "\t Verifying assignment (=) and test for equality (==):" << endl;

      // Equals
      try {
            matrix <int> A(3,5);
            A(3,5)=1;
            A(1,1)=1;
            matrix <int> B(A);
            if ( not (A.equals(B))) throw(1);
            B(2,2) = 8;
            if (A.equals(B)) throw(1);

            matrix <double> C("hi",6,2);
            C(1,1) = 1.5;
            C(6,1) = -0.1;
            matrix <double> D(C);
            if (not (D.equals(C))) throw(1);
            D(2,2) = 0.1;
            if (D.equals(C)) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tEquality test (equals)\t\t\t";
      if (error) {
            fatal_error = true;
            count_fail_fatal++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Not equals (nequals)
      try {
            matrix <int> A(3,5);
            A(3,5)=1;
            A(1,1)=1;
            matrix <int> B(A);
            if ( (A.nequals(B))) throw(1);
            B(2,2) = 8;
            if (not (A.nequals(B))) throw(1);

            matrix <double> C("hi",6,2);
            C(1,1) = 1.5;
            C(6,1) = -0.1;
            matrix <double> D(C);
            if ( (D.nequals(C))) throw(1);
            D(2,2) = 0.1;
            if (not (D.nequals(C))) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tNot equals test (nequals)\t\t";
      if (error) {
            fatal_error = true;
            count_fail_fatal++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Actually do == first
      try {
            matrix <int> A(3,5);
            A(3,5)=1;
            A(1,1)=1;
            matrix <int> B(A);
            if ( not (A==B)) throw(1);
            B(2,2) = 8;
            if (A==B) throw(1);

            matrix <double> C("hi",6,2);
            C(1,1) = 1.5;
            C(6,1) = -0.1;
            matrix <double> D(C);
            if (not (D==C)) throw(1);
            D(2,2) = 0.1;
            if (D==C) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tEquality test (==)\t\t\t";
      if (error) {
            fatal_error = true;
            count_fail_fatal++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Now not equals
      try {
            matrix <int> A(3,5);
            A(3,5)=1;
            A(1,1)=1;
            matrix <int> B(A);
            if ( (A!=B)) throw(1);
            B(2,2) = 8;
            if (not (A!=B)) throw(1);

            matrix <double> C("hi",6,2);
            C(1,1) = 1.5;
            C(6,1) = -0.1;
            matrix <double> D(C);
            if ( (D!=C)) throw(1);
            D(2,2) = 0.1;
            if (not (D!=C)) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tNot equals test (!=)\t\t\t";
      if (error) {
            fatal_error = true;
            count_fail_fatal++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Now assignment
      try {
            matrix <int> A(3,5);
            A(3,5)=1;
            A(1,1)=1;
            matrix <int> C;
            C = A;
            if (not (C==A)) throw(1);
            A = A; // Ha

      }
      catch (...) {
            error = true;
      }
      cout << "\t\tAssignment (=)\t\t\t\t";
      if (error) {
            fatal_error = true;
            count_fail_fatal++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;
      return;
}

//***************************************************************************
//
//               more_gets_sets_tests
//
//***************************************************************************
//
//
void more_gets_sets_tests( bool & error, bool & fatal_error,
                   int & count_pass, int & count_fail_reg,
                   int & count_fail_fatal )
{
      cout << "\t Verifying remaining sets and gets:" << endl;

      // Rows and cols
      try {
            matrix <int> A(3,5);
            if (A.get_num_rows() != 3) throw(1);
            if (A.get_num_cols() != 5) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tget_num_{rows,cols}\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Get and set get_name()
      try {
            matrix <int> A("Test",3,5);
            if (A.get_name().compare("Test") !=0) throw(1);
            A.set_name("Test2");
            if (A.get_name().compare("Test2") != 0) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tGet/set name()\t\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;
      return;
}
//***************************************************************************
//
//               matrix_math_tests
//
//***************************************************************************


void matrix_math_tests( bool & error, bool & fatal_error,
                   int & count_pass, int & count_fail_reg,
                   int & count_fail_fatal )
{
      cout << "\t Verifying mathematical operations:" << endl;

      // Matrices we're going to use
      matrix <double> A_double,B_double,C_double,D_double,E_double,F_double,G_double;
      matrix <int> A_int, B_int, C_int, D_int, E_int, F_int, G_int;

     // Do some setup
      A_double.create(3,3);
      A_double(1,1)=1.0;A_double(1,2)=3.0;A_double(1,3)=3.0;
      A_double(2,1)=1.0;A_double(2,2)=4.0;A_double(2,3)=3.0;
      A_double(3,1)=1.0;A_double(3,2)=3.0;A_double(3,3)=4.0;

      B_double.create(3,3);
      B_double(1,1)=1.0;B_double(1,2)=2.0;B_double(1,3)=3.0;
      B_double(2,1)=4.0;B_double(2,2)=5.0;B_double(2,3)=6.0;
      B_double(3,1)=7.0;B_double(3,2)=8.0;B_double(3,3)=9.0;

      // A+B=C
      C_double.create(3,3);
      C_double(1,1)=2.0;C_double(1,2)=5.0;C_double(1,3)=6.0;
      C_double(2,1)=5.0;C_double(2,2)=9.0;C_double(2,3)=9.0;
      C_double(3,1)=8.0;C_double(3,2)=11.0;C_double(3,3)=13.0;

      // A-B=D
      D_double.create(3,3);
      D_double(1,1)=0.0;D_double(1,2)=1.0;D_double(1,3)=0.0;
      D_double(2,1)=-3.0;D_double(2,2)=-1.0;D_double(2,3)=-3.0;
      D_double(3,1)=-6.0;D_double(3,2)=-5.0;D_double(3,3)=-5.0;

      // A*B=E
      E_double.create(3,3);
      E_double(1,1)=34.0;E_double(1,2)=41.0;E_double(1,3)=48.0;
      E_double(2,1)=38.0;E_double(2,2)=46.0;E_double(2,3)=54.0;
      E_double(3,1)=41.0;E_double(3,2)=49.0;E_double(3,3)=57.0;

      // A^-1=F
      F_double.create(3,3);
      F_double(1,1)=7.0;F_double(1,2)=-3.0;F_double(1,3)=-3.0;
      F_double(2,1)=-1.0;F_double(2,2)=1.0;F_double(2,3)=0.0;
      F_double(3,1)=-1.0;F_double(3,2)=0.0;F_double(3,3)=1.0;

      // A^t=G
      G_double.create(3,3);
      G_double(1,1)=1.0;G_double(1,2)=1.0;G_double(1,3)=1.0;
      G_double(2,1)=3.0;G_double(2,2)=4.0;G_double(2,3)=3.0;
      G_double(3,1)=3.0;G_double(3,2)=3.0;G_double(3,3)=4.0;

      // Now ints
      A_int.create(3,3);
      A_int(1,1)=1.0;A_int(1,2)=3.0;A_int(1,3)=3.0;
      A_int(2,1)=1.0;A_int(2,2)=4.0;A_int(2,3)=3.0;
      A_int(3,1)=1.0;A_int(3,2)=3.0;A_int(3,3)=4.0;

      B_int.create(3,3);
      B_int(1,1)=1.0;B_int(1,2)=2.0;B_int(1,3)=3.0;
      B_int(2,1)=4.0;B_int(2,2)=5.0;B_int(2,3)=6.0;
      B_int(3,1)=7.0;B_int(3,2)=8.0;B_int(3,3)=9.0;

      // A+B=C
      C_int.create(3,3);
      C_int(1,1)=2.0;C_int(1,2)=5.0;C_int(1,3)=6.0;
      C_int(2,1)=5.0;C_int(2,2)=9.0;C_int(2,3)=9.0;
      C_int(3,1)=8.0;C_int(3,2)=11.0;C_int(3,3)=13.0;

      // A-B=D
      D_int.create(3,3);
      D_int(1,1)=0.0;D_int(1,2)=1.0;D_int(1,3)=0.0;
      D_int(2,1)=-3.0;D_int(2,2)=-1.0;D_int(2,3)=-3.0;
      D_int(3,1)=-6.0;D_int(3,2)=-5.0;D_int(3,3)=-5.0;

      // A*B=E
      E_int.create(3,3);
      E_int(1,1)=34.0;E_int(1,2)=41.0;E_int(1,3)=48.0;
      E_int(2,1)=38.0;E_int(2,2)=46.0;E_int(2,3)=54.0;
      E_int(3,1)=41.0;E_int(3,2)=49.0;E_int(3,3)=57.0;

      // A^-1=F
      F_int.create(3,3);
      F_int(1,1)=7.0;F_int(1,2)=-3.0;F_int(1,3)=-3.0;
      F_int(2,1)=-1.0;F_int(2,2)=1.0;F_int(2,3)=0.0;
      F_int(3,1)=-1.0;F_int(3,2)=0.0;F_int(3,3)=1.0;

      // A^t=G
      G_int.create(3,3);
      G_int(1,1)=1.0;G_int(1,2)=1.0;G_int(1,3)=1.0;
      G_int(2,1)=3.0;G_int(2,2)=4.0;G_int(2,3)=3.0;
      G_int(3,1)=3.0;G_int(3,2)=3.0;G_int(3,3)=4.0;

      // Addition method
      try {
            matrix <double> add_double(3,3);
            matrix <int> add_int(3,3);
            add_double.add(A_double,B_double);
            if (add_double!=C_double) throw(1);
            add_int.add(A_int,B_int);
            if (add_int!=C_int) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tAddition method\t\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Adition operator
      try {
            matrix <double> add_double(3,3);
            matrix <int> add_int(3,3);
            add_double=(A_double+B_double);
            if (add_double!=C_double) throw(1);
            add_int=(A_int+B_int);
            if (add_int!=C_int) throw(1);
            add_int = add_int + B_int + B_int; // Bonus test
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tAddition operator (+)\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Subtraction method
      try {
            matrix <double> sub_double(3,3);
            matrix <int> sub_int(3,3);
            sub_double.subtract(A_double,B_double);
            if (sub_double!=D_double) throw(1);
            sub_int.subtract(A_int,B_int);
            if (sub_int!=D_int) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tSubtraction method\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Subtraction operator
      try {
            matrix <double> sub_double(3,3);
            matrix <int> sub_int(3,3);
            sub_double=(A_double-B_double);
            if (sub_double!=D_double) throw(1);
            sub_int=(A_int-B_int);
            if (sub_int!=D_int) throw(1);
            sub_int = sub_int - B_int - B_int; // Bonus test
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tSubtraction operator (-)\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Multiplication method
      try {
            matrix <double> mult_double(3,3);
            matrix <int> mult_int(3,3);
            mult_double.multiply(A_double,B_double);
            if (mult_double!=E_double) throw(1);
            mult_int.multiply(A_int,B_int);
            if (mult_int!=E_int) throw(1);
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tMultiplication method\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Multiplication operator
      try {
            matrix <double> mult_double(3,3);
            matrix <int> mult_int(3,3);
            mult_double=(A_double*B_double);
            if (mult_double!=E_double) throw(1);
            mult_int=(A_int*B_int);
            if (mult_int!=E_int) throw(1);
            mult_int = mult_int * B_int * B_int; // Bonus test
      }
      catch (...) {
            error = true;
      }
      cout << "\t\tMultiplication operator (*)\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Invert
      try {
            matrix <double> inv_double(3,3);
            matrix <int> inv_int(3,3);
            double det_double;
            int det_int;

            inv_double.invert(A_double,det_double);
            if (inv_double !=F_double || fabs(det_double-1.0)>0.000001) throw(1);

            inv_int.invert(A_int,det_int);
            if (inv_int != F_int || det_int!=1) throw(1);

      }
      catch (...) {
            error = true;
      }
      cout << "\t\tInversion operator\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Transpose
      try {
            matrix <double> trans_double(3,3);
            matrix <int> trans_int(3,3);


            trans_double.transpose(A_double);
            if (trans_double !=G_double ) throw(1);

            trans_int.transpose(A_int);
            if (trans_int != G_int) throw(1);

      }
      catch (...) {
            error = true;
      }
      cout << "\t\tTranspose operator\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Various creation operators
      cout << "\t Verifying diagonal and identity:" << endl;
      // Diagonal
      try {
            matrix <int> diag_int(3,3);

            diag_int.diagonal(2);
            for (int i=1; i<=3; i++) {
                  for (int j=1; j<=3; j++) {
                        if ((i==j) && (diag_int(i,j)!=2)) throw(1);
                        if ((i!=j) && (diag_int(i,j) != 0)) throw(1);
                  }
            }

      }
      catch (...) {
            error = true;
      }
      cout << "\t\tDiagonal operator\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      // Identity
      try {
            matrix <int> diag_int(3,3);
            diag_int.diagonal(1);

            matrix <int> I_int(3,3);
            I_int.identity();

            if (diag_int != I_int) throw(1);

      }
      catch (...) {
            error = true;
      }
      cout << "\t\tIdentity operator\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;
      return;
}

//***************************************************************************
//
//               binary_read_write_tests
//
//***************************************************************************
//
//
void binary_read_write_tests( bool & error, bool & fatal_error,
                   int & count_pass, int & count_fail_reg,
                   int & count_fail_fatal )
{


      // Print
      cout << "\t Verifying binary files:" << endl;
      try {
       // We'll just use A
       matrix <int> A_int;A_int.create(3,3);
       A_int(1,1)=1.0;A_int(1,2)=3.0;A_int(1,3)=3.0;
       A_int(2,1)=1.0;A_int(2,2)=4.0;A_int(2,3)=3.0;
       A_int(3,1)=1.0;A_int(3,2)=3.0;A_int(3,3)=4.0;
       matrix <int> A_copy(A_int);
            // Write it to file
       fstream filestream;
       filestream.open("testmat.mat", fstream::out | fstream::binary);
       A_copy.write_to_file(filestream);
       filestream.close();
       A_copy.free();
          // Open it back up
       matrix <int> inmat;
       filestream.open("testmat.mat",fstream::in | fstream::binary);
       inmat.read_from_file(filestream);
       filestream.close();
            // Check
       if (inmat!=A_int) throw(1);

      }
      catch (...) {
            error = true;
      }
      cout << "\t\tBinary file in/out\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;
      return;
}

//***************************************************************************
//
//               print_cout_tests
//
//***************************************************************************
//
//
void print_cout_tests( bool & error, bool & fatal_error,
                   int & count_pass, int & count_fail_reg,
                   int & count_fail_fatal )
{
      cout << "\t Verifying print method:" << endl;
      try {
            matrix <int> P(1,1);
            P(1,1) = 1;
            P.print();

      }
      catch (...) {
            error = true;
      }
      cout << "\t\tPrint 1x1\t\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      try {
            matrix <int> P(10,1);
            for (int i=1; i<=10; i++) P(i,1)=i;
            P.print();

      }
      catch (...) {
            error = true;
      }
      cout << "\t\tPrint 10x1\t\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;

      try {
            matrix <int> P(10,10);
            for (int i=1; i<=10; i++)
            for (int j=1; j<=10; j++)
            P(i,j)=i*j;
            P.print();

      }
      catch (...) {
            error = true;
      }
      cout << "\t\tPrint 10x10\t\t\t\t";
      if (error) {
            count_fail_reg++;
            cout << "failed" << endl;
      }
      else {
            count_pass++;
            cout << "passed" << endl;
      }
      error = false;
      return;
}


