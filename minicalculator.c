/*Pablo Velazquez
 * This program is my work and not the work of others.
 * This program works as a mini calculator. Using getopt, it allows the user
 * to input a value and do different operations to that value with command line
 * arguments.
 */

#include <stdio.h>
#include <stdlib.h>

void checknum(int num, char usage[]){//check if num values are between 1 and 20
	if((num > 20) || (num < 1)){
	    printf("Error: all num values must be between 1 and 20\n");
	    fprintf(stderr, usage);
	    exit(1);
	}
}

int main(int argc, char **argv)
{
	extern char *optarg;
	extern int optind;
	int c, err = 0; 
	int aflag=0, dflag=0, mflag = 0, sflag=0, xflag=0;
	int addn=0, divn=0, multn=0, subn=0, value=0; 
	float result = 0.00;
	static char usage[] = "usage: minicalc [-a num] [-d num] [-m num] [-s num] [-x] value\n";

	while ((c = getopt(argc, argv, "a:d:m:s:x")) != -1)
	    switch (c) {
		case 'a':
			aflag = 1;
			addn = atoi(optarg); //convert optarg to int, save to corresponding variable
			break;
		case 'd':
			dflag = 1;
			divn = atoi(optarg); //same as addn
			break;
		case 'm':
			mflag = 1;
			multn = atoi(optarg); //same as addn
			break;
		case 's':
			sflag = 1;
			subn = atoi(optarg); //same as addn
			break;
		case 'x':
			xflag = 1;
			break;
		case '?':
			err = 1;
			break;
	}
		
	if ((optind+1) > argc) {//check to see if at least one argument was entered	
	    //printf("optind = %d, argc=%d\n", optind, argc);
	    fprintf(stderr, "%s: missing value\n", argv[0]);//let the user know value needs to be entered
	    fprintf(stderr, usage, argv[0]);//print usage
	    exit(1);
	}else if(err){
	    fprintf(stderr, usage, argv[0]);
	} 	

	if (optind < argc){//get the arguments at the end of the command line
	    for (; optind < argc; optind++){
	    sscanf(argv[optind], "%i", &value);//store the argument in value
	    }
	}
	else {
		printf("no arguments left to process\n");
	}

	if((value > 99) || (value < 1)){//check if value is between 1 and 99
	    printf("Error: value must be between 1 and 99\n");
	    fprintf(stderr, usage, argv[0]);
	    exit(1);//exit if value is not between 1 and 99
	}

	result = (float)value;//copy value as a float into result

	if(xflag == 1){//square result
	    result = result * result;
	}
	if(mflag == 1){//multiply result by userinput multn
	    checknum(multn, usage);//check userinput	 
	    result = result * multn;
	}
	if(dflag == 1){//divide result by divn
	    checknum(divn, usage);//check userinput	    
	    result = result / divn;
	}
	if(aflag == 1){//add addn to result
	    checknum(addn, usage);
	    result = result + addn;
	}
	if(sflag ==1){//subtract subn from result
	    checknum(subn, usage);
	    result = result - subn;
	}

	printf("result = %.2f\n", result);//print result with 2 decimals of precision
	exit(0);
}
