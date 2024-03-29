/*
 * print_help.c
 *
 *  Created on: Apr 7, 2019
 *      Author: mark
 */


void print_help(){

	printf("\033[1;31m"); //Set color to Red
	printf("\n                      MEICommand is a CLI interface\n");
	printf("               For the MEI scnx16627RUS Bill Validator\n");
	printf("\033[1;34m"); //Set color to Cyan
	printf("                       Written By Mark Meadows\n");
	printf("\033[0;31m"); //Set color to Red
	printf("     (c)Copyright 2019 FireKing Security Group All rights reserved\n");
	printf("\033[1;33m"); //Set color to Yellow
	printf("                        Ver 00.00.90 (DEBUG VER.)           \n");
	printf("\033[1;31m"); //Set color to Red
	printf("           this program requires root or sudo system access\n");
	printf("\033[0m"); //Set it back to white
	printf("\033[1;34m"); //Set color to Cyan
	printf("===========================================================================\n");
	printf("\033[0m"); //Set it back to white
	printf("                   Available Commands are as follows:\n");
	printf("\033[1;32m"); //Set color to Green
	printf(" MEI_POLL\n");
	printf(" MEI_STACK\n");
	printf(" MEI_RETURN\n");
	printf(" MEI_GETMODEL\n");
    printf(" MEI_GETSERIAL\n");
    printf(" MEI_GETBOOTVER\n");
    printf(" MEI_GETAPPVER\n");
    printf(" MEI_GETVARNAME\n");
    printf(" MEI_GETQP\n");
    printf(" MEI_GETPERF\n");
    printf(" MEI_GETBNF\n");
    printf(" MEI_GETBILLS\n");
    printf(" MEI_RETRIEVE\n");
    printf(" MEI_RESET\n");
    printf(" MEI_Number_Of_Resets\n");

    printf("\033[1;34m"); //Set color to Cyan
    printf("===========================================================================\n");
    printf("\033[0m"); //Set it back to white
    printf("\033[0m"); //Set it back to white
    printf("\n");
	printf(" [Usage]: MEICommand {port} {command}\n");
	printf("\n");
	printf(" [Example]: MEICommand /dev/ttyUSB0 MEI_GETSERIAL\n\n");
	exit(1);
}
