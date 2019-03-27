/*
 ============================================================================
 Name        : MEICommand.c
 Author      : Mark Meadows
 Version     :
 Copyright   : Fireking Security Group
 Description : MEICommand in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print_help.h"
#include "mei_Constants.h"
#include "do_crc.h"

int main(int argc, char *argv[]) {

char pkt_command[1];
char comm_port[250] = {0}; //Define comm port variable
char command[15] = {0};     //Define command variable

/*
=====================================================================================
Parse Command Line Arguments
=====================================================================================
Check Command Line arguments we need at least two
if incorrect show them the help file
*/
	if (argv[1] == NULL || argv[2] == NULL){
		printf("Command line Error! .....\n\n");
		print_help();
	}

	strncpy(comm_port,argv[1],strlen(argv[1]));
	strncpy(command,argv[2],strlen(argv[2]));
/*
====================================================================================
Finished Parsing Command Line Arguments
====================================================================================
Figure out what the command byte should be
====================================================================================
*/
	if (strcmp(command,"MEI_GETMODEL" )== 0 ){
		   pkt_command[1] = MEI_GETMODEL;
	}

	if (strcmp(command,"MEI_GETSERIAL" )== 0 ){
			pkt_command[1] = MEI_GETSERIAL;
	}

	if (strcmp(command,"MEI_GETBOOTVER" )== 0 ){
			pkt_command[1] = MEI_GETBOOTVER;
	}

	if (strcmp(command,"MEI_GETAPPVER" )== 0 ){
			pkt_command[1] = MEI_GETAPPVER;
	}

	if (strcmp(command,"MEI_GETVARNAME" )== 0 ){
			pkt_command[1] = MEI_GETVARNAME;
	}

	if (strcmp(command,"MEI_GETQP" )== 0 ){
			pkt_command[1] = MEI_GETQP;
	}

	if (strcmp(command,"MEI_GETPERF" )== 0 ){
			pkt_command[1] = MEI_GETPERF;
	}

	if (strcmp(command,"MEI_GETBNF" )== 0 ){
			pkt_command[1] = MEI_GETBNF;
	}

	if (strcmp(command,"MEI_POLL" )== 0 ){
			printf("\nThis Feature not Implemented Yet...\n");
			exit(0);
	}

	if (strcmp(command,"enable" )== 0 ){
			printf("\nThis Feature not Implemented Yet...\n");
			exit(0);
	}

	if (strcmp(command,"disable" )== 0 ){
			printf("\nThis Feature not Implemented Yet...\n");
			exit(0);
	}

	if (strcmp(command,"reset" )== 0 ){
			printf("\nThis Feature not Implemented Yet...\n");
			exit(0);
	}

	if (strcmp(command,"accept" )== 0 ){
			printf("\nThis Feature not Implemented Yet...\n");
			exit(0);
	}

	if (strcmp(command,"direction" )== 0 ){
			printf("\nThis Feature not Implemented Yet...\n");
			exit(0);
	}

	if (strcmp(command,"download" )== 0 ){
			printf("\nThis Feature not Implemented Yet...\n");
			exit(0);
	}

	if (strcmp(command,"enablebmk" )== 0 ){
			printf("\nThis Feature not Implemented Yet...\n");
			exit(0);
	}

	if (strcmp(command,"disabletime" )== 0 ){
			printf("\nThis Feature not Implemented Yet...\n");
			exit(0);
	}

/*
=====================================================================================
Finished getting the command Byte
=====================================================================================
 */



	printf("\n%s\n",comm_port);
	printf("\n%s\n",command);
	printf("\n\%02x\n",pkt_command[1]);
	exit(0);










	print_help();
	exit(0);

}
