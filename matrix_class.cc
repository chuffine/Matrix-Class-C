/* 
	Trey (Carroll) Huffine
	Project 2 - Final Project
	OOP - Matrix Class Functions
	CE 595 - Dr. Dodds
	4/2/13 Born
	5/2/13 Due
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <cstdlib>

using namespace std;

#include "matrix_class.h"


///////////////////////////////////////////////////////////////
// 		Constructors, Destructors, and Copy Constructors     //
///////////////////////////////////////////////////////////////

//		
//		All standard constructors call the "create" function
//		See this for more detail on the construction
//
template <class T>
matrix<T> :: matrix(void)
{		
		//
		//
		//		construct a void matrix will a null point
		//
		//
		
		//
		// set_debug();
		//
		if( debug == true ) trace_message(1);
		//
		// construct fcn
		num_rows = 0; num_cols = 0;
		mptr = NULL;
		id.reserve(80); // initialize id
		id = " "; 
		//
		if( debug == true ) trace_message(2);
		return;
}
template <class T>
matrix<T> :: matrix (int nr)
{		
		//
		//
		//		take the number of rows to construct a vector
		//		will take the name as " "
		//
		//
		
		//
		// set_debug();
		//
		if( debug == true ) trace_message(3);
		//
		//	error test
		if( nr <= 0){ err(7); return; }
		//
		//	construct fcn
		string blank = " ";
		create(blank, nr);
		//
		if( debug == true ) trace_message(4);
		return;
}
template <class T>
matrix<T> :: matrix(int nr, int nc)
{
		//
		//
		//		construct a matrix of nr x nc
		//		pass the id as " "
		//
		//
		
		//
		// set_debug();
		//
		if( debug == true ) trace_message(5);
		//
		// 	error test
		if( nr<= 0){ err(7); return; }
		if( nc<= 0){ err(8); return; }
		//
		//	construct fcn
		string blank = " ";
		create(blank, nr, nc);
		//
		if( debug == true ) trace_message(6);
		return;
}
template <class T>
matrix<T> :: matrix (string id, int nr)
{
		//
		//
		//		construct a vector of nr with a string id
		//
		//
		
		//
		// set_debug();
		//
		if( debug == true ) trace_message(7);
		//
		// error test
		if( nr <= 0){ err(7); return; }
		//
		// construct fcn
		create(id, nr);
		//
		if( debug == true ) trace_message(8);
		return;
}
template <class T>
matrix<T> :: matrix(string id, int nr, int nc)
{
		//
		//
		//		construct an nr x nc matrix  with a string id
		//
		//
		
		//
		// set_debug();
		//
		if( debug == true ) trace_message(9);
		//
		//	error test
		if( nr<= 0){ err(7); return; }
		if( nc<= 0){ err(8); return; }
		//
		// construct fcn
		create(id, nr, nc);
		//
		if( debug == true ) trace_message(10);
		return;
}
template <class T>
matrix<T> :: matrix(const matrix <T> & a )
{
		//
		//
		//		copy constructor for a matrix (nr x nc) or vector (nr)
		//		will copy the values directly from a matrix passed by reference
		//
		//
		
		//
		// set_debug();
		//
		if( debug == true ) trace_message(11);
		//
		// copy constructor fcn
		create(a.id, a.num_rows, a.num_cols);
		for( int j=1; j<=num_rows*num_cols; j++)
			{  (*this)(j) = a(j);  }
		//
		if( debug == true ) trace_message(12);		
		return;
}
template <class T>
matrix<T> :: ~matrix(void)
{
		//
		//
		//		donconstructs the object of matrixx class
		//		sets rows and columns to zero and NULLs the 
		//		pointer by calling "free" function
		//
		//
		
		if( debug == true ) trace_message(13);
		//
		// locals
		num_rows = 0; num_cols = 0;
		//
		// destructor fcn
		if(mptr != NULL) 
			{ free(); } ;
		//
		if( debug == true ) trace_message(14);
		return;
}
// template <class T>
// void matrix<T> :: set_debug()
// {
		//
		//		Called by constructors to set debug on or off
		//		This is done at compile time
		//
		
		// debug = true;
// }
//////////////////////////////////////////////////////////
//		Creation and freeing mechanisms for matrices    //
//////////////////////////////////////////////////////////

//
//		**  Method used for vector and matrix creation **
//
//		All created functions use a pointer of type <T>
//		to create a dynamically allocated array using the "new" operator
//		For a vector, it is an array of nr.  For a matrix, it is an
//		array of nr x nc stored contiguously on the heap
//
//
template <class T>
void matrix<T> :: create (string matrix_id, int nr)
{
		//
		//		creates a vector of nr by taking nc = 1
		//		passes in an id for the vector
		//
		
		if( debug == true ) trace_message(15);
		//
		//	error test
		if( nr <= 0){ err(7); return; }
		//
		// local variables
		num_rows = nr; num_cols = 1;
		//
		//	create function
		mptr = new T[nr];
		id = matrix_id;
		//
		if( debug == true ) trace_message(16);
		return;
}
template <class T>
void matrix<T> :: create(string matrix_id, int nr, int nc)
{
		//
		//		creates a nr x nc matrix with a string id
		//
		
		if( debug == true ) trace_message(17);
		//
		//	error test
		if( nr<= 0){ err(7); return; }
		if( nc<= 0){ err(8); return; }
		//
		//	local variables
		num_rows = nr; num_cols = nc;
		//
		//	create fcn
		mptr = new T[nr*nc];
		id = matrix_id;
		//
		if( debug == true ) trace_message(18);
		return;
}
template <class T>
void matrix<T> :: create( int nr )
{
		//
		//		creates a vector of nr with no string id
		//
		
		if( debug == true ) trace_message(19);
		//
		//	error test
		if( nr <= 0){ err(7); return; }
		//
		// local variables
		num_rows = nr; num_cols = 1;
		//
		//	create fcn
		mptr = new T[nr];
		id = " ";
		//
		if( debug == true ) trace_message(20);
		return;
}
template <class T>
void matrix<T> :: create( int nr, int nc)
{
		//
		//		creates a vector of nr x nc with no matrix id
		//
		
		if( debug == true ) trace_message(21);
		//
		//	error test
		if( nr<= 0){ err(7); return; }
		if( nc<= 0){ err(8); return; }
		//
		//	local variables
		num_rows = nr; num_cols = nc;
		//
		//	create fcn
		mptr = new T[nr*nc];
		id = " ";
		//
		if( debug == true ) trace_message(22);
		return;
}
template <class T>
void matrix<T> :: free( void )
{		
		//
		//		frees the array by setting nr = 0 and nc = 0
		//		"delete" operator on the the pointer and set it to NULL
		//
		if( debug == true ) trace_message(23);
		//
		//	local variables
		num_rows = 0; num_cols = 0;
		//
		//	free fcn
		delete [] mptr;
		mptr = NULL;
		//
		if( debug == true ) trace_message(24);
		return;
}
/////////////////////////////////////////////////////
//		Overloaded Operators for  matrix class	   // ~ debug message returned error in overloads ~ omitted
/////////////////////////////////////////////////////
template <class T>
T& matrix<T> :: operator() (int row) const
{
		//
		//		allows user to use () to access the values of a vector
		//

		return( mptr[row - 1] );

}
template <class T>
T& matrix<T> :: operator() (int row, int col) const
{
		//
		//		allows the user to use the () to access the values of a vector
		//		allows them use (i,j) notation to access the contiguously stored matrix
		//
		
		return( mptr[num_cols*(row-1)+col-1] );

}
template <class T>
matrix<T>& matrix<T> :: operator = ( const matrix<T> & rhs )
{
		//
		//		overloads the equals operator to set a matrix equal to another
		//		the new matrix will have all matching values of (i,j)
		//		the new matrix will use free and create to be
		//		set to the same size of the new matrix
		//
		
		//	local string for " "
		string blank = " ";
		//
		if( mptr == rhs.mptr ) return(*this); // if you put x = x
		//
		//	free and create new matrix for =
		free( );
		create(blank, rhs.num_rows, rhs.num_cols);
		//
		//	set values for =
		for(int j=1; j<=num_rows*num_cols; j++)
			{  (*this)(j) = rhs(j); }
		return( *this );
}
template <class T>
matrix<T> matrix<T> :: operator * (matrix<T>& b)
{
		//
		//		the overload * allows for standard
		//		matrix multiplication of two matrices
		//
		
		//	error testing in "multiply" function

		//
		//	local variables
		int nrow, ncol;
		nrow = get_num_rows(); ncol = b.get_num_cols();
		//
		//	create temp matrix to return for *
		matrix<T> temp;
		temp.multiply( *this, b );
		//
		return temp;
}
template <class T>
matrix<T> matrix<T> :: operator + (matrix<T>& b) 
{
		//
		//		adds each (i,j) term of two equal size matrices
		//		by calling "add" function
		//

		//
		//	error testing in "add" function

		//
		//	local variables
		int nrow, ncol;
		nrow = b.get_num_rows(); ncol = b.get_num_cols();
		//
		//	create temp matrix to return for +
		matrix<T> temp;
		temp.add( *this, b );
		//
		return temp;
}
template <class T>
matrix<T> matrix<T> :: operator - (matrix<T>& b) 
{
		//
		//		subtracts each (i,j) term of two equal size matrices
		//		by calling "subtract" function
		//
		
		//
		//	error testing in "subtract" function

		//
		//	local variables
		int nrow, ncol;
		nrow = b.get_num_rows(); ncol = b.get_num_cols();
		//
		// create temp matrix to return for -
		matrix<T> temp;
		temp.subtract( *this, b );
		//
		return temp;
}
//////////////////////////////////////
//		Data Access of Matrices		//
//////////////////////////////////////
template <class T>
int matrix<T> :: get_num_rows(void)
{
		//
		//		returns the private variable num_rows of an array
		//
		
		if( debug == true ) trace_message(37);
		//
		return(num_rows);
}
template <class T>
int matrix<T> :: get_num_cols(void)
{
		//
		//		returns the private variable num_cols of an array
		//
		
		if( debug == true ) trace_message(38);
		//
		return(num_cols);
}
template <class T>
string matrix<T> :: get_name(void)
{
		//
		//		returns the private variable id of an array
		//
		
		if( debug == true ) trace_message(39);
		//
		return(id);
}
template <class T>
void matrix<T> :: set_name( string mat_id )
{
		//
		//		sets the private variable id of an array
		//
		
		if( debug == true ) trace_message(40);
		//
		id = mat_id;
		//
		if( debug == true ) trace_message(41);
}
template <class T>
void matrix<T> :: set_value( T value )
{
		//
		//		sets all the values of a matrix<T> to the inputted value
		//
		
		if( debug == true ) {trace_message(42); cout << value << endl << endl;}
		//
		//	error checking
		if( num_rows <= 0 ) { err(11); return; }
		if( num_cols <= 0 ) { err(12); return; }
		//
		//	set all values in matrix to value
		for(int j=1; j<=num_rows*num_cols; j++)
		{  (*this)(j) = value;  }
		//
		if( debug == true ) trace_message(43);
}
template <class T>
void matrix<T> :: set_value( int row, T value )
{
		//
		//		sets the value of a vector<T> to the inputted value
		//		in the appropriate row
		//
		
		if( debug == true ) trace_message(44); cout << value << endl << endl;
		//
		//	error test
		if( num_cols > 1 ) { err(1); return;  }
		if( row > num_rows ) { err(9); return; }
		if( row <= 0) { err(11); return; }
		//
		//	set value in vector to value
		(*this)(row) = value;
		//
		if( debug == true ) trace_message(45);
}
template <class T>
void matrix<T> :: set_value(int row, int col, T value)
{
		//
		//		sets the (row,col) of a matrix<T> to the inputted value
		//
		
		if( debug == true ) trace_message(46); cout << value << endl << endl;
		//
		//	error test
		if( row > num_rows ) { err(9); return; }
		if( col > num_cols ) { err(10); return; }
		if( row <= 0 ) { err(11); return; }
		if( col <= 0 ) { err(12); return; }
		//
		//	set (i,j) in matrix to value
		(*this)(row,col) = value;
		//
		if( debug == true ) trace_message(47);
}
template <class T>
T matrix<T> :: get_value( int row )
{
		//
		//		returns the desired value of a vector
		//
		
		if( debug == true ) trace_message(48);
		//
		//	error test
		if( num_cols > 1 ) { err(14); return(0);}
		if( row > num_rows ) { err(9); return(0);}
		if( row <= 0) { err(11);  return(0);}
		//
		return( (*this)(row) );
}
template <class T>
T matrix<T> :: get_value( int row, int col)
{
		//
		//		returns the (i,j) value of a matrix
		//
		
		if( debug == true ) trace_message(49);
		//
		//	error test
		if( row > num_rows ) { err(9); return(0);}
		if( col > num_cols ) { err(10); return(0);}
		if( row <= 0 ) { err(11); return(0);}
		if( col <= 0 ) { err(12); return(0);}
		//
		//
		return( (*this)(row,col) );
}
/////////////////////////////////
//		Matrix Operations	   //
/////////////////////////////////
template <class T>
void matrix<T> :: add( matrix<T>& a, matrix<T>& b)
{
		//
		//		adds each (i,j) term of two equal size matrices
		//		frees and creates matrix to correct size of a and b
		//
		
		if( debug == true ) trace_message(50);
		//
		//	error test
		if( a.get_num_rows() != b.get_num_rows()) { err(2); return; }
		if( a.get_num_cols() != b.get_num_cols()) { err(3); return; }
		if(a.num_rows <= 0) {err(11); return;}
		if(a.num_cols <= 0) {err(12); return;}
		if(b.num_rows <= 0) {err(11); return;}
		if(b.num_cols <= 0) {err(12); return;}
		//
		//	local variables
		int nrow, ncol, nterms, i, j, k;
		string blank = " ";
		//
		//	free and create new matrix for addition
		free( );
		nrow = a.get_num_rows(); ncol = b.get_num_cols();
		create(blank,nrow,ncol);
		//
		//	addition function
		for(i=1; i<=nrow; i++)
		{
			for(j=1; j<=ncol; j++)
			{  (*this)(i,j) = a(i,j) + b(i,j);  }
		}
		//
		if( debug == true ) trace_message(51);
		return;
}
template <class T>
void matrix<T> :: subtract( matrix<T>& a, matrix<T>& b)
{
		//
		//		subtracts each (i,j) term of two equal size matrices
		//		frees and creates matrix to correct size of a and b
		//
		
		if( debug == true ) trace_message(52);
		//
		//	error test
		if( a.get_num_rows() != b.get_num_rows()) { err(4); return; }
		if( a.get_num_cols() != b.get_num_cols()) { err(5); return; }
		if(a.num_rows <= 0) {err(11); return;}
		if(a.num_cols <= 0) {err(12); return;}
		if(b.num_rows <= 0) {err(11); return;}
		if(b.num_cols <= 0) {err(12); return;}
		
		//
		//	local variables
		int nrow, ncol, nterms, i, j, k;
		string blank = " ";
		//
		//	free and create new matrix for subtraction
		free( );
		nrow = a.get_num_rows(); ncol = b.get_num_cols();
		create(blank,nrow,ncol);
		//
		//	subtraction fcn
		for(i=1; i<=nrow; i++)
		{
			for(j=1; j<=ncol; j++)
			{  (*this)(i,j) = a(i,j) - b(i,j);  }
		}
		//
		if( debug == true ) trace_message(53);
		return;
}
template <class T>
void matrix<T> :: multiply( matrix<T>& a, matrix<T>& b )
{
	//
	//		does standard matrix multiplication on a and b
	//		if the num_cols of a == num_rows of b
	//
	
	if( debug == true ) trace_message(54);
	//
	//	local variables
	int nrow, ncol, nterms, i, j, k;
	T zero = static_cast<T> (0);
	T sum;
	string blank = " ";
	//
	//	error test
		if(a.num_cols != b.num_rows) 
			{err(6); return;}
		if(a.num_rows <= 0) {err(11); return;}
		if(a.num_cols <= 0) {err(12); return;}
		if(b.num_rows <= 0) {err(11); return;}
		if(b.num_cols <= 0) {err(12); return;}
	//
	//	create and free matrices to multiply
		free( );
		nrow = a.get_num_rows(); ncol = b.get_num_cols();
		create(blank,nrow,ncol);
	//
	//	multiply fcn
		for(i=1; i<=nrow; i++)
		{
			for( j=1; j<=ncol; j++ )
			{
				sum = zero;
				for( k=1; k<=a.get_num_cols(); k++ )
					{sum += a(i,k)*b(k,j);}
			(*this)(i,j) = sum;
			}
		}
	//
	if( debug == true ) trace_message(55);
	return;
}
template <class T>
void matrix<T> :: identity( void )
{
	//
	//		If the input matrix is square, the function will
	//		create an identity matrix. (all 0's w/ diagonal of 1's)
	//
	
	if( debug == true ) trace_message(56);
	//
	//	error checking
	if( num_rows != num_cols) {err(13); return;}
	if(num_rows <= 0) {err(11); return;}
	if(num_cols <= 0) {err(12); return;}
	//
	//	local variables
	int i, j; T T_zero = static_cast<T> (0), T_one = static_cast<T> (1);
	//
	//	identity fcn
	for( i=1; i<=num_rows; i++)
		{
		  for( j=1; j<=num_cols; j++)
		   {  (*this)(i,j) = T_zero;  }		  
		  (*this)(i,i) = T_one;
		}
	//	
	if( debug == true ) trace_message(57);
	return;
}
template <class T>
void matrix<T> :: diagonal( T value )
{ 
	//
	//		If the input matrix is square, the function will
	//		create an diagonal matrix of value. 
	//		(all 0's w/ diagonal of value)
	//
	
	if( debug == true ) trace_message(58);
	//
	//	error checking
	if( num_rows != num_cols) {err(13); return;}
	if(num_rows <= 0) {err(11); return;}
	if(num_cols <= 0) {err(12); return;}
		
	//
	//	local variables
	int i, j; T T_zero = static_cast<T> (0);
	//
	//	diagonal fcn
	for( i=1; i<=num_rows; i++)
		{
		  for( j=1; j<=num_cols; j++)
		   {  (*this)(i,j) = T_zero;  }		  
		      (*this)(i,i) = value;
		}
	//
	if( debug == true ) trace_message(59);
	return;
}
template <class T>
void matrix<T> :: transpose( matrix<T> & a)
{		
		//
		//		transposes a matrix by setting a temp
		//		matrix's (i,j) to the (j,i) of the 
		//		input matrix
		//
		
		if( debug == true ) trace_message(60);
		//
		//	error checking	
		if(a.num_rows <= 0) {err(11); return;}
		if(a.num_cols <= 0) {err(12); return;}
		if(num_rows <= 0) {err(11); return;}
		if(num_cols <= 0) {err(12); return;}
		
		//
		//	local varables
		matrix<T> temp1;
		string tempid, transid;
		transid = tempid.append( " - Transpose " );
		//
		//	free and create new matrix for transose
		free();
		create(transid,a.get_num_cols(),a.get_num_rows());
		//
		//	transpose fcn
		for(int i=1; i<=get_num_rows(); i++)
		{
		  for(int j=1; j<=get_num_cols(); j++)
		  {  (*this)(i,j) = a(j,i);  }
		}
		//
		if( debug == true ) trace_message(61);
}
///////////////////////////
//		Data Output		 //
///////////////////////////
template <class T>
void matrix<T> :: print()
{		
		//
		//		Print nicely formatted matrix output.
		//		Will distinguish int, float, double.
		//		Find the spacing of each matrix cell
		//		by dividing the largest number by 10
		//		until it is less than 1.  The number of
		//		of times this is done is the spacing 
		//		used for the matrix.  Floats and doubles
		//		will be assumed to have 2 decimal place
		//		precision until an update is installed.
		//		typeid() is used to distinguish the type
		//		associated with the template <T>.
		//
		
		
		if( debug == true ) trace_message(62);
		//
		//	locak varaibles
		int spacer = 0, user_precision;
		T n = (*this)(1);
		T test1, test2;
		
		//-----------------------------
		//	Double precision outut
		//-----------------------------
		if( typeid( T ) == typeid( double ) )
		{
			// cout << "Decimal Place Precision: ";
			// cin >> user_precision;
			// cout.precision(user_precision);
			cout.precision(2);
			//
			//	test for largest value
			for(int i = 2; i <= num_rows*num_cols; i++)
				{	test1 = (*this)(i); test2 = (*this)(i-1);
					if( test1 > test2 )
					{  n = (*this)(i);  }
				}
			//
			//	Find number of values (assuming 2 decimals places of precision added later)
			while( n >= 1 ) { n = n/10; spacer++; }
			//
			//	set ios to allight
			cout << setiosflags( ios::fixed | ios::right );
			//
			//	output id if it is not "blank"
			if( id != " ")
			{  cout << id << endl;  }
			//	
			//	output matrix for double precisdions
			for(int i = 1; i <= get_num_rows(); i++)
			{
				for( int j = 1; j<= get_num_cols(); j++)
				{cout << setw(spacer + 2) <<(*this)(i,j) << "  ";}
				 cout << endl;
			}
			cout << endl;
		}
		//-----------------
		//	Float output
		//-----------------
		if( typeid( T ) == typeid( float ) )
		{
			//cout << "Decimal Place Precision: ";
			// cin >> user_precision;
			// cout.precision(user_precision);
			cout.precision(2);
			//
			//	Find largest number
			for(int i = 2; i <= num_rows*num_cols; i++)
				{	test1 = (*this)(i); test2 = (*this)(i-1);
					if( test1 > test2 )
					{  n = (*this)(i);  }
				}
			//
			//	Find length of number (2 decimal precision added later)
			while( n >= 1 ) { n = n/10; spacer++; }
			//
			//	set formatting
			cout << setiosflags( ios::fixed | ios::right );
			//
			//	output name if not "blank"
			if( id != " ")
			{  cout << id << endl;  }
			//
			//	output formatted matrix
			for(int i = 1; i <= get_num_rows(); i++)
			{
				for( int j = 1; j<= get_num_cols(); j++)
				{cout << setw(spacer + 2) <<(*this)(i,j) << "  ";}
				 cout << endl;
			}
			cout << endl;
		}
		//-------------------
		//  Integer output
		//-------------------
		if( typeid( T ) == typeid( int ) )
		{
			//
			//	find largest value
			for(int i = 2; i <= num_rows*num_cols; i++)
				{	test1 = (*this)(i); test2 = (*this)(i-1);
					if( test1 > test2 )
					{  n = (*this)(i);  }
				}
			//
			//	Find length of largest value
			while( n >= 1 ) { n = n/10; spacer++; }
			//
			//	Set formatting
			cout << setiosflags( ios::fixed | ios::right );
			//
			//	Output ID if not blank
			if( id != " ")
			{  cout << id << endl;  }
			//
			//	Output formatted matrix
			for(int i = 1; i <= get_num_rows(); i++)
			{
				for( int j = 1; j<= get_num_cols(); j++)
				{cout << setw(spacer) <<(*this)(i,j) << "  ";}
				 cout << endl;
			}
			cout << endl;
		}
		//
		if( debug == true ) trace_message(63);
		
}
template <class T>
void matrix<T> :: write_to_file( fstream& file ) 
{
		//
		//		Writes matrix information (id, num_rows, num_cols, vlues)
		//		to a binary file.
		//
		
		if( debug == true ) trace_message(64);
		//
		if( num_rows == 0 ) return;
		file.write(reinterpret_cast<char *> (&num_rows), sizeof( int ) );
		file.write(reinterpret_cast<char *> (&num_cols), sizeof( int ) );
		file.write( id.c_str(), max_name_len);
		file.write(reinterpret_cast<char *> (&mptr[0]), num_rows*num_cols*sizeof( T ) );
		//
		if( debug == true ) trace_message(65);
}
template <class T>
void matrix<T> :: read_from_file( fstream& file )
{
		//
		//		Reads matrix information (id, num_rows, num_cols, vlues)
		//		from a binary file.
		//
		
		if( debug == true ) trace_message(66);
		//
		file.read(reinterpret_cast<char *> (&num_rows), sizeof( int ) );
		if( file.eof() ) return;
		file.read(reinterpret_cast<char *> (&num_cols), sizeof( int ) );
		char temp_name[80];
		file.read( temp_name, max_name_len); id = temp_name;
		create( id, num_rows, num_cols );
		file.read(reinterpret_cast<char *> (&mptr[0]), num_rows*num_cols*sizeof( T ) );
		//
		if( debug == true ) trace_message(67);
}
//////////////////////////////
//		Debug settings      //
//////////////////////////////

//
//		Debug on,off for each object of matrix
//		Allows acces to private debug bool
//

template <class T>
void matrix<T> :: set_debug_on()
{
		debug = true;
}
template <class T>
void matrix<T> :: set_debug_off()
{
		debug = false;
}




//***************************************************************************
//
//               matrix class:  equals
//
//***************************************************************************
//
//
template <class T>
bool matrix <T> :: equals( matrix<T>& a )
{
if( debug == true ) trace_message(68);
//
// Local variables
//
  bool use_dequals;
  int i,j;
  double epsilon;
//
  if( a.num_rows != num_rows || a.num_cols != num_cols );// message(5);
//
//     Switch on datatype to detect doubles/floats.  If not, just blindly use ==
//
   if( typeid(T) == typeid(double) )
     {
      use_dequals = false;
      epsilon = (double) DEPSILON;
     }
   else if( typeid(T) == typeid(float) )
     {
      use_dequals = false;
      epsilon = (double) FEPSILON;
     }
   else
     {
      use_dequals = true;
     }
//
//       Now either compare with floating point or with ==
//
  if( use_dequals )
    {
      for (i=1; i<= num_rows; i++)
        for (j=1; j<=num_cols; j++)
          if ( (*this)(i,j) != a.get_value(i,j) ) return false;
    }
  else
    {
      for (i=1; i<=num_rows; i++)
        for (j=1; j<=num_cols; j++)
        if ( (double) fabs((*this)(i,j)-a.get_value(i,j)) > epsilon) return false;
    }
//
  return true;
}


//***************************************************************************
//
//               matrix class:  nequals
//
//***************************************************************************
//
//
template <class T>
bool matrix <T> :: nequals( matrix<T>& a)
{
  return !( (*this).equals(a) );
}

//***************************************************************************
//
//               matrix class:  operator==
//
//***************************************************************************
//
//
template <class T>
bool matrix<T> :: operator==(matrix<T>&b)
{
  return (*this).equals(b);
}
//***************************************************************************
//
//               matrix class:  operator!=
//
//***************************************************************************
//
//
template <class T>
bool matrix<T> :: operator!=(matrix<T>&b)
{
  return (*this).nequals(b);
}




//*****************************************************
//
//    invert service (method) of matrix class
//
//*****************************************************
//
//
template <class T>
void matrix <T> :: invert( matrix<T>& a, T& det )
{
if( debug == true ) trace_message(69);
//
  int  k, j, i, nrow, ncol;
//
//   inverts a matrix by gauss-jordan elimination.
//   also computes the determinant. check for singular matrix.
//
//   use of temporary enables non-modification of left-side
//   if matrix is singular.
//
  T zero = static_cast<T> (0.0);
  T one  = static_cast<T> (1.0);
  det  = one;
  nrow = a.num_rows;
  ncol = nrow;
  assert( nrow > 0 && ncol > 0 );
  matrix <T> temp( a );
//
  for( k=1; k<=nrow; k++ )
   {
     if( temp(k,k) == zero ) { det = zero; return; }
     det = det * temp(k,k);
     for( j=1; j<=ncol; j++ )
       if( j!=k ) temp(k,j) = temp(k,j) / temp(k,k);
     temp(k,k) = one / temp(k,k);
     for( i=1; i<=nrow; i++ )
       {
         if( i==k ) continue;
         for( j=1; j<=ncol; j++ )
           if( j!=k ) temp(i,j) = temp(i,j) -
                      temp(i,k) * temp(k,j);
         temp(i,k) = -temp(i,k) * temp(k,k);
       }
   }
//
 (*this) = temp;
  return;
}

//////////////////////////////////
//		Message Functions   	//
//////////////////////////////////
//
//////////////////////
//	Debug outputs	//
//////////////////////
template <class T>
void matrix<T> :: trace_message( int mess_num )
{
//
//		Private debug messages
//

switch (mess_num)
{
	case 1:
		cout << "***Debug: Entering void constructor." << endl << endl;
	break;
	case 2:
		cout << "***Debug: Exiting void constructor."   << endl << endl;
	break;
	case 3:
		cout << "***Debug: Entering vector constructor."   << endl << endl;
	break;
	case 4:
		cout <<  "***Debug: Exiting vector constructor."  << endl << endl;
	break;
	case 5:
		cout << "***Debug: Entering matrix constructor."  << endl << endl;
	break;
	case 6:
		cout << "***Debug: Exiting constructor."  << endl << endl;
	break;
	case 7:
		cout << "***Debug: Entering vector constructor with ID."  << endl << endl;
	break;
	case 8:
		cout <<  "***Debug: Exiting vector constructor with ID." << endl << endl;
	break;
	case 9:
		cout << "***Debug: Entering matrix constructor with ID."  << endl << endl;
	break;
	case 10:
		cout << "***Debug: Exiting matrix constructor with ID."  << endl << endl;
	break;
	case 11:
		cout <<  "***Debug: Entering copy constructor." << endl << endl;
	break;
	case 12:
		cout <<  "***Debug: Exiting copy constructor." << endl << endl;
	break;
	case 13:
		cout << "***Debug: Entering destructor."  << endl << endl;
	break;
	case 14:
		cout << "***Debug: Exiting destructor."  << endl << endl;
	break;
	case 15:
		cout << "***Debug: Entering create vector function with id."  << endl << endl;
	break;
	case 16:
		cout <<  "***Debug: Exiting create vector function with id." << endl << endl;
	break;
	case 17:
		cout <<  "***Debug: Entering create matrix function with id." << endl << endl;
	break;
	case 18:
		cout <<  "***Debug: Exiting create matrix function with id." << endl << endl;
	break;
	case 19:
		cout << "***Debug: Entering create vector function."  << endl << endl;
	break;
	case 20:
		cout <<  "***Debug: Exiting create vector." << endl << endl;
	break;
	case 21:
		cout << "***Debug: Entering create matrix function with id."  << endl << endl;
	break;
	case 22:
		cout << "***Debug: Exiting create matrix function."  << endl << endl;
	break;
	case 23:
		cout <<  "***Debug: Entering free function." << endl << endl;
	break;
	case 24:
		cout << "***Debug: Exiting free function."  << endl << endl;
	break;
	case 25:
		cout << "***Debug: Entering overloaded () for vector."  << endl << endl;
	break;
	case 26:
		cout <<  "***Debug: Exiting overloaded () for vector." << endl << endl;
	break;
	case 27:
		cout << "***Debug: Entering overloaded () for matrix."  << endl << endl;
	break;
	case 28:
		cout <<  "***Debug: Exiting overloaded () for matrix." << endl << endl;
	break;
	case 29:
		cout <<  "***Debug: Entering overloaded = ." << endl << endl;
	break;
	case 30:
		cout <<  "***Debug: Exiting overloaded = ." << endl << endl;
	break;
	case 31:
		cout <<  "***Debug: Entering overloaded * ." << endl << endl;
	break;
	case 32:
		cout << "***Debug: Exiting overloaded * ."  << endl << endl;
	break;
	case 33:
		cout << "***Debug: Entering overloaded + ."  << endl << endl;
	break;
	case 34:
		cout <<  "***Debug: Exiting overloaded + ." << endl << endl;
	break;
	case 35:
		cout <<  "***Debug: Entering overloaded - ." << endl << endl;
	break;
	case 36:
		cout <<  "***Debug: Exiting overloaded - ." << endl << endl;
	break;
	case 37:
		cout <<  "***Debug: get_num_rows test: " << num_rows << endl << endl;
	break;
	case 38:
		cout << "***Debug: get_num_cols test: "  << num_cols << endl << endl;
	break;
	case 39:
		cout << "***Debug: get_name test: "  << id << endl << endl;
	break;
	case 40:
		cout << "***Debug: set_name test."  << endl << endl;
	break;
	case 41:
		cout << "***Debug: get_name test."  << endl << endl;
	break;
	case 42:
		cout <<  "***Debug: Entering set_value for whole matrixx test: " ;
	break;
	case 43:
		cout << "***Debug: Exiting set_value for whole matrix test."  << endl << endl;
	break;
	case 44:
		cout <<  "***Debug: Entering set_value vector test: " ;
	break;
	case 45:
		cout <<  "***Debug: Exiting set_value vector test."  << endl << endl;
	break;
	case 46:
		cout <<   "***Debug: Entering set_value matrix(i,j) test: " ;
	break;
	case 47:
		cout << "***Debug: Exiting set_value matrix(i,j) test."  << endl << endl;
	break;
	case 48:
		cout <<  "***Debug: Entering get_value vector test." << endl << endl;
	break;
	case 49:
		cout << "***Debug: Entering get_value matrix test."  << endl << endl;
	break;
	case 50:
		cout <<  "***Debug: Entering additing function." << endl << endl;
	break;
	case 51:
		cout <<  "***Debug: Exiting additing function." << endl << endl;
	break;
	case 52:
		cout << "***Debug: Entering subtract function."  << endl << endl;
	break;
	case 53:
		cout << "***Debug: Exiting subtract function."  << endl << endl;
	break;
	case 54:
		cout <<  "***Debug: Entering multiply function." << endl << endl;
	break;
	case 55:
		cout <<  "***Debug: Exiting multiply function." << endl << endl;
	break;
	case 56:
		cout << "***Debug: Entering identity function."  << endl << endl;
	break;
	case 57:
		cout << "***Debug: Exiting identity function."  << endl << endl;
	break;
	case 58:
		cout <<  "***Debug: Entering diagonal function." << endl << endl;
	break;
	case 59:
		cout << "***Debug: Exiting diagonal function."  << endl << endl;
	break;
	case 60:
		cout << "***Debug: Entering transpose function."  << endl << endl;
	break;
	case 61:
		cout << "***Debug: Exiting transpose function."  << endl << endl;
	break;
	case 62:
		cout << "***Debug: Entering data output."  << endl << endl;
	break;
	case 63:
		cout <<  "***Debug: Exiting data output." << endl << endl;
	break;
	case 64:
		cout << "***Debug: Entering write_to_file."  << endl << endl;
	break;
	case 65:
		cout <<  "***Debug: Exiting write_to_file." << endl << endl;
	break;
	case 66:
		cout << "***Debug: Entering read_from_file."  << endl << endl;
	break;
	case 67:
		cout << "***Debug: Exiting read_from_file."  << endl << endl;
	break;
	case 68:
		cout <<  "***Debug: Entering equality." << endl << endl;
	break;
	case 69:
		cout << "***Debug: Entering inversion."  << endl << endl;
	break;
	}
}

/////////////////////
//	Error Outputs  //
/////////////////////
template <class T>
void matrix<T> :: err( int mess_num )
{
//
//		Output error messages for invalid matrices
//

switch (mess_num)
{
	case 1:
		cout << ">>>error: Input is not a vector - cannot set value." << endl << endl;
	break;
	case 2:
		cout << ">>>error: Rows length does not match - cannot add." << endl << endl;
	break;
	case 3:
		cout << ">>>error: Colum length does not match - cannot add." << endl << endl;
	break;
	case 4:
		cout << ">>>error: Colum length does not match - cannot subtract." << endl << endl;
	break;
	case 5:
		cout << ">>>error: Colum length does not match - cannot subtract." << endl << endl;
	break;
	case 6:
		cout << ">>>error: Vectors dimensions do not match to allow for multiplication" << endl << endl;
	break;
	case 7:
		cout << ">>>error: Rows must be greator or equal to 1 - cannot create." << endl << endl;
	break;
	case 8:
		cout << ">>>error: Columns must be greater or equal to 1 - cannot create." << endl << endl;
	break;
	case 9:
		cout << ">>>error: Row larger than dimension of matrix." << endl << endl;
	break;
	case 10:
		cout << ">>>error: Column larger than dimension of matrix." << endl << endl;
	break;
	case 11:
		cout << ">>>error: Rows must be greater or equal to 1." << endl << endl;
	break;
	case 12:
		cout << ">>>error: Columns must be greater or equal to 1." << endl << endl;
	break;
	case 13:
		cout << ">>>error: Not a square matrix." << endl << endl;
	break;
	case 14:
		cout << ">>>error: Input is not a vector - cannot get value." << endl << endl;
	break;
}
}

/////////////////
//	Templates  //
/////////////////
template class matrix <int>;
template class matrix <float>;
template class matrix <double>;