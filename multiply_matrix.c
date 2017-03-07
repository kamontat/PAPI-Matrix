#include <stdio.h>
#include <stdlib.h>
#include "papi.h"

#define NUM_EVENTS 2
#define ERROR_RETURN(retval) { fprintf(stderr, "Error %d %s:line %d: \n", retval,__FILE__,__LINE__);  exit(retval); }

int MATRIX_SIZE;

// file-format:
//      first line contain n which is matrix size (assume the matrix is square matrix)
//      next n line is matrix in format "1 2 3 ... n"
int **readMatrix(char *fileName) {
	// read file
	FILE *fp;
	fp = fopen(fileName, "r");
	int count = fscanf(fp, "%d", &MATRIX_SIZE);

	// check memory
    	int **matrix;
    	matrix = malloc(sizeof(int *) * MATRIX_SIZE);
    	int i = 0, j = 0;
    	for (i = 0; i < MATRIX_SIZE; i++) {
        	//Allocate actual integer pointers
        	matrix[i] = malloc(sizeof(int) * MATRIX_SIZE);
        	if (matrix[i] == NULL) {
            		fprintf(stderr, "out of memory\n");
            		exit(0);
        	}
	}

	// storing matrix
	for (int k = 0; k < MATRIX_SIZE; k++)
		for (j = 0; j < MATRIX_SIZE; j++) {
		    	int test;
		    	int count = fscanf(fp, "%d", &test);
		    	matrix[k][j] = test;
		}

	fclose(fp);
	return matrix;
}

int **matrixMultiply(int **matrix)
{
    int **result;
    result = malloc(sizeof(int *) * MATRIX_SIZE);
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        result[i] = malloc(sizeof(int) * MATRIX_SIZE);
    }

    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            int sum = 0;
            for (int k = 0; k < MATRIX_SIZE; k++)
                sum += matrix[i][k] * matrix[k][j];
            result[i][j] = sum;
        }

    return result;
}

void print(int **result)
{
    for (int k = 0; k < MATRIX_SIZE; k++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%d ", result[k][j]);
        }
        printf("\n");
    }
}

// 2 argument - first is file name, second is [0 | 1] which meaning:
//                                                      0 - no print
//                                                      1 - print the result
void run(char *fileName, int to_print)
{
    int **matrix;
    int **result;

    matrix = readMatrix(fileName);
    result = matrixMultiply(matrix);

    if (to_print != 0)
        print(result);

    free(matrix);
    free(result);
}

int main(int argc, char *argv[])
{
    char *c_file_name = *argv++;
    argc--;

    if (argc != 1)
    {
        printf("invalid argument (too many argument)\n");
        while (argc--)
        {
            printf("%s", *argv++);
        }
        return 1;
    }

    /******************* Declaring and Initializing *********************/
    int Events[2] = {PAPI_TOT_INS, PAPI_TOT_CYC};
    /*declaring place holder for no of hardware counters */
    int num_hwcntrs = 0;
    char errstring[PAPI_MAX_STR_LEN];
    /*This is going to store our list of results*/
    long long values[NUM_EVENTS];
    // FLOPS calculate
    float real_time, proc_time,mflops;
    long long flpops;
    float ireal_time, iproc_time, imflops;
    long long iflpops;

    int retval;

    if((retval = PAPI_library_init(PAPI_VER_CURRENT)) != PAPI_VER_CURRENT )
    {
        fprintf(stderr, "Error: %d %s\n",retval, errstring);
        exit(1);
    }

    if ((num_hwcntrs = PAPI_num_counters()) < PAPI_OK) {
        printf("There are no counters available. \n");
        exit(1);
    }

    printf("\nfile: %s\n", *argv);
    printf("There are %d counters in this system\n",num_hwcntrs);

    if ( (retval = PAPI_start_counters(Events, NUM_EVENTS)) != PAPI_OK)
        ERROR_RETURN(retval);

    printf("Counter Started: \n");

    /* code to execute */
    run(*argv, 0);
	
    if ( (retval=PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK)
        ERROR_RETURN(retval);

    printf("\nRead successfully\n");
    printf("The total instructions executed multiply matrix are %lld \n",values[0]);
    printf("The total cycles used are %lld \n", values[1] );
    printf("CPI = %lf \n", (double) values[1]/values[0] );

    /******************* PAPI_stop_counters **********************************/
    if ((retval=PAPI_stop_counters(values, NUM_EVENTS)) != PAPI_OK)
        ERROR_RETURN(retval);

    /******************* Starting FLOPS *************************************/
    if((retval=PAPI_flops(&ireal_time,&iproc_time,&iflpops,&imflops)) < PAPI_OK) { 
        printf("Could not initialise PAPI_flops \n");
        printf("Your platform may not support floating point operation event.\n"); 
        printf("retval: %d\n", retval);
        exit(1);
    }

    /* code to execute */
    run(*argv, 0);

    /******************* Stopping FLOPS *************************************/
    if((retval=PAPI_flops(&real_time,&proc_time,&flpops,&mflops)) < PAPI_OK) {
        printf("retval: %d\n", retval);
        exit(1);
    }

    /******************* Printing FLOPS *************************************/
    printf("Real_time %f \nProc_time: %f \nTotal flpops: %lld \nMFLOPS: %f\n",
        real_time, proc_time,flpops,mflops);

    /******************* GETTING INFORMATION *************************************/
    const PAPI_hw_info_t *hwinfo = NULL;
     
    /* Get hardware info*/      
    if ((hwinfo = PAPI_get_hardware_info()) == NULL) {
        printf("PAPI_get_hardware_info error! \n");
        exit(1);
    }

    printf("%d CPU  at %f Mhz.\n",hwinfo->totalcpus,hwinfo->mhz);
    printf(" model string is %s \n", hwinfo->model_string);
    /* clean up */ 
    PAPI_shutdown();

    exit(0);	
}
