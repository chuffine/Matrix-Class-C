#ifndef MATRIX_PROTOTYPES
#define MATRIX_PROTOTYPES 1

#include <typeinfo>

#define FEPSILON 0.000001
#define DEPSILON 0.0000000000001

template < class T >
class matrix
{

public:

	//		Constructors
	matrix( void );
	matrix( int );
	matrix(int, int);
	matrix(string, int);
	matrix(string, int, int);
	matrix(const matrix<T> & );
	~matrix( void );
	
	//		Operator Overloads
	T& operator() ( int ) const; 
	T& operator() (int , int ) const;
	matrix<T>& operator= (const matrix<T> &);
	matrix<T> operator* (matrix<T>& );
	matrix<T> operator+ ( matrix<T>& );
	matrix<T> operator- ( matrix<T>& );
	
	//		Create and Free Matrix
	void create( int );
	void create( int , int);
	void create(string, int );
	void create( string matrix_id, int, int);
	void free( void );
	
	//		Data Access
	int get_num_rows(void);
	int get_num_cols(void);	
	string get_name( );
	void set_name( string mat_id );
	void set_value( T );
	void set_value( int, T );
	void set_value(int, int, T);
	T get_value( int );
	T get_value( int, int );

	//		Special Matrix Types
	void invert( matrix<T>& , T& );
	void transpose( matrix<T> & );	
	void identity( void );
	void diagonal( T value );
	
	//		Matrix Operations
	void multiply( matrix<T>& , matrix<T>&); 
	void add( matrix<T>& , matrix<T>& );
	void subtract( matrix<T>& , matrix<T>& );
	
	//		Equality == / !=  Overloads
	bool operator==(matrix<T> &);
    bool operator!=(matrix<T> &);
    bool equals( matrix& );
    bool nequals( matrix& );
	
	//		Data Output
	void print( );
	void write_to_file( fstream& );
	void read_from_file( fstream& );
	
	//		Debugging and Errors
	void set_debug_on();
	void set_debug_off();
	void trace_messge( int );
	void error( int );
	
private:

	int num_rows, num_cols;
	T *mptr;
	string id;
	int max_name_len = 80;
	// void set_debug();
	bool debug = false;
	void trace_message( int );
	void err( int );
};

#endif