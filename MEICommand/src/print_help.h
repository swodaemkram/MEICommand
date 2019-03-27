/*
 * print_help.h
 *
 *  Created on: Mar 27, 2019
 *      Author: mark
 */

#ifndef PRINT_HELP_H_
#define PRINT_HELP_H_



#endif /* PRINT_HELP_H_ */
print_help(){

	printf("\n                    MEICommand is a CLI interface\n");
	printf("               For the MEI scnx16627RUS Bill Validator\n");
	printf("                       Written By Mark Meadows\n");
	printf("     (c) Copyright 2019 FireKing Security Group All rights reserved\n");
	printf("\n");
	printf(" Available Commands are as follows\n\n");
	printf(" enable - Places acceptor in acceptance mode (so bills can be inserted)\n");
	printf(" disable - Terminates acceptance mode (so no bills can be inserted)\n");
	printf(" reset - Resets device (to try to clear jams and such - takes over 10 seconds)\n");
	printf(" accept - Defines denominations to be accepted (format is: CUR_VALUE,CUR_VALUE,...)\n");
	printf(" direction - Defines direction of acceptance as provided in direction.in input\n");
	printf(" download - Starts firmware download process using file path in download.in\n");
	printf(" enablebmk - Places acceptor in book mark mode (so one book mark can be inserted)\n");
	printf(" disabletime - Sets inactivity time to disable acceptance basedon disabletime.in\n");
	printf("----------------------------------------------------------------------------------\n");
	printf(" The Following queries are also accepted\n");
    printf(" MEI_ACCEPTING\n");
    printf(" MEI_ESCROW\n");
    printf(" MEI_STACKING\n");
    printf(" MEI_RETURNING\n");
    printf(" MEI_RETURNED\n");
    printf(" MEI_CHEATED\n");
    printf(" MEI_REJECTED\n");
    printf(" MEI_JAM\n");
    printf(" MEI_FULL\n");
    printf(" MEI_CASSETTE\n");
    printf(" MEI_POWERUP\n");
    printf(" MEI_FAILURE\n");
    printf(" MEI_POLL\n");
    printf(" MEI_GETMODEL\n");
    printf(" MEI_GETSERIAL\n");
    printf(" MEI_GETBOOTVER\n");
    printf(" MEI_GETAPPVER\n");
    printf(" MEI_GETVARNAME\n");
    printf(" MEI_GETQP\n");
    printf(" MEI_GETPERF\n");
    printf(" MEI_GETBNF\n");
    printf("\n");
	printf(" [Usage]: MEICommand enable\n");
	printf(" [Usage]: MEICommand MEI_GETSERIAL\n\n");
	exit(1);
}
