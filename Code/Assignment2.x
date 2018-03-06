const BUFFER_SIZE = 1024;


struct pwdd 
{
    char p[BUFFER_SIZE];
};

struct strings 
{
    char src[BUFFER_SIZE];
};

struct FileExists 
{
     char p[BUFFER_SIZE];
};
struct sort_request
{
	int p;
	int arr[100];
};

struct matrix_request
{
	int arr[4];
};

struct matrix_input
{
	matrix_request arr1;
	matrix_request arr2;
	
};

program EXAMPLE_PROG 
{
    version EXAMPLE_VERS 
    {
           string pwd( pwdd ) = 1; 
           string ECHO( strings ) = 2; 
           string STRCONC( FileExists ) = 3;
           sort_request SORTING(sort_request) = 4;
           matrix_request Matrix_Multi(matrix_input) = 5; /* procedure number = 3 */
   } = 1;                                /* version number = 1 */
} = 0x31234567; 
