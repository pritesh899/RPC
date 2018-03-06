/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "Assignment2.h"


void example_prog_1(char *host)
{
	CLIENT *clnt;
	char * *result_1;
	pwdd  pwd_1_arg;
	char * *result_2;
	strings  echo_1_arg;
	char * *result_3;
	FileExists  strconc_1_arg;
	sort_request  *result_4;
	sort_request  sorting_1_arg;
	matrix_request  *result_5;
	matrix_input  matrix_multi_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, EXAMPLE_PROG, EXAMPLE_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

    int ex = 0;
    int ch;
    int y;
    while(ex==0)
    {
        printf("\n");
        printf("---------------------------------------------------------");
        printf("\n");
        
        //Printing the options to take the user input
        printf("Select the option :\n1.Path(pwd command) \n2.Echo \n3.File Check \n4.Sort \n5.Matrix Multiplication \n6.Exit \n");
        printf("\n");
        
        //input the user choice in varaible ch
        printf("Enter your choice :\t");
        scanf("%d",&ch);
        
        //switch case
        switch (ch)
        {
            case 1:
                /* pwd command */
                result_1 = pwd_1(&pwd_1_arg, clnt);
                if (result_1 == (char **) NULL) {
                    clnt_perror (clnt, "call failed");
                }
                else
                {
                    //here result comes if everything is fine
                    printf("\n");
                    printf("Path of the current directory at remote server : \t %s \n",*result_1);
                }
                break;
                
            case 2:
                /* echo */
                printf("\n");
                
                //Taking the input from the user and storing it
                printf("Enter String for echo : \t");
                scanf("%s",&echo_1_arg.src);
                result_2 = echo_1(&echo_1_arg, clnt);
                if (result_2 == (char **) NULL) {
                    clnt_perror (clnt, "call failed");
                }
                else
                {
                    //here result comes if everything is fine
                    printf("\n");
                    printf("String from server :\t %s \n",*result_2);
                }
                break;
                
                
            case 3:
                /* file exists */
                printf("\n");
                
                //Taking the filename as input from the user and storing it
                printf("Enter File name :\t");
                scanf("%s",&strconc_1_arg.p);
                result_3 = strconc_1(&strconc_1_arg, clnt);
                if (result_3 == (char **) NULL) {
                    clnt_perror (clnt, "call failed");
                }
                else
                {
                    //here result comes if everything is fine
                    printf("\n");
                    printf("Result : %s \n",*result_3);
                }
                break;
            case 4:
                printf("\n");
                
                //Taking the number of elements as input from the user and storing it
                printf("Enter the number of elements : \t");
                scanf("%d",&sorting_1_arg.p);
                printf("\n");
                
                //Taking the elements as input from the user and storing it in an array
                printf("Enter the elements : \t");
                int z;
                for (z=0; z<sorting_1_arg.p; z++)
                {
                    scanf("%d",&sorting_1_arg.arr[z]);
                }
                result_4 = sorting_1(&sorting_1_arg, clnt);
                if (result_4 == (sort_request *) NULL) {
                    clnt_perror (clnt, "call failed");
                }
                else
                {
                    //here result comes if everything is fine
                    printf("\n");
                    int i;
                    //printing the result came from server
                    printf("Sorted in Ascending order : \t");
                    printf("\n");
                    for(i=0;i<sorting_1_arg.p;i++)
                    {
                        printf(" %d\t",result_4->arr[i]);
                    }
                }
                break;
            case 5:
                //Taking the elements of matrix1 as input from the user and storing it in a 1-D array
                printf("\n");
                printf("Enter the elements in Matrix 1 :");
                printf("\n");
                for(y=0;y<4;y++)
                {
                    scanf("%d",&matrix_multi_1_arg.arr1.arr[y]);
                }
                int j;
                printf("\n");
                
                //Taking the elements of matrix2 as input from the user and storing it in a 1-D array
                printf("Enter the elements in Matrix 2 :");
                printf("\n");
                for(j=0;j<4;j++)
                {
                    scanf("%d",&matrix_multi_1_arg.arr2.arr[j]);
                }
            
                result_5 = matrix_multi_1(&matrix_multi_1_arg, clnt);
                if (result_5 == (matrix_request *) NULL) {
                    clnt_perror (clnt, "call failed");
                }
                else
                {
                    //here result comes if everything is fine
                    int result[2][2];
                    //storing the result in the 2-D array
                    result[0][0]=result_5->arr[0];
                    result[0][1]=result_5->arr[1];
                    result[1][0]=result_5->arr[2];
                    result[1][1]=result_5->arr[3];
                    printf("\n");
                    printf("Resulting matrix after multiplication : \n");
                    int c,d;
                    
                    //printing the result
                    for (c = 0; c < 2; c++)
                    {
                        for (d = 0; d < 2; d++)
                            printf("%d ", result[c][d]);
                        printf("\n");
                    }
                }
                break;
    
            case 6:
                //Exit condition
                ex=1;
                break;
                
            default:
                //provides the error message when user user inputs invalid choice
                printf("\n");
                printf("Invalid choice..Please enter again");
                break;
        }//switch case
    }//while
	
	
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	example_prog_1 (host);
exit (0);
}