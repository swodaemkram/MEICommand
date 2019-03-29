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
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

#include "ack_message_send.h"
#include "print_help.h"
#include "mei_Constants.h"
#include "do_crc.h"
#include "setup_serial_port.h"
#include "build_packet.h"
#include "send_pkt.h"
#include "ack_packet_build.h"

int main(int argc, char *argv[]) {

//char pkt_command[1];
unsigned int pkt_command = 0;
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
	   pkt_command = MEI_GETMODEL;
	}

	if (strcmp(command,"MEI_GETSERIAL" )== 0 ){
		pkt_command = MEI_GETSERIAL;
	}

	if (strcmp(command,"MEI_GETBOOTVER" )== 0 ){
		pkt_command = MEI_GETBOOTVER;
	}

	if (strcmp(command,"MEI_GETAPPVER" )== 0 ){
		pkt_command = MEI_GETAPPVER;
	}

	if (strcmp(command,"MEI_GETVARNAME" )== 0 ){
		pkt_command = MEI_GETVARNAME;
	}

	if (strcmp(command,"MEI_GETQP" )== 0 ){
		//pkt_command = MEI_GETQP;
		printf("\nThis Feature not Implemented Yet...\n");
		exit(0);
	}

	if (strcmp(command,"MEI_GETPERF" )== 0 ){
		pkt_command = MEI_GETPERF;
	}

	if (strcmp(command,"MEI_GETBNF" )== 0 ){
		pkt_command = MEI_GETBNF;
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


if (pkt_command == 0) {
	printf("\nCommand line variable error ! ...\n");
	print_help();
}


/*
=====================================================================================
Finished getting the command Byte
=====================================================================================
Setup Serial Port
=====================================================================================
*/
	setup_serial_port(comm_port);
/*
=====================================================================================
Serial Port is Setup
=====================================================================================
Lets Build The Packet to be transmitted
=====================================================================================
 */
 char * pkt;
 pkt = build_packet(pkt_command);
 //printf("This is the string I'm sending --> %02x%02x%02x%02x%02x%02x%02x%02x\n\n",pkt[0],pkt[1],pkt[2],pkt[3],pkt[4],pkt[5],pkt[6],pkt[7]);
/*
=====================================================================================
Finished Building Packet
=====================================================================================
Send Packet to MEI unit
=====================================================================================
 */
 send_pkt(comm_port,pkt); //send the bloody packet
/*
=====================================================================================
Packet Sent now we need to ACK the packet
=====================================================================================
We Need to Build and ACK Packet
=====================================================================================
*/
 char * ack_pkt;
 ack_pkt = ack_packet_build(pkt_command);

 /*
======================================================================================
Finished Building ACK Packet
======================================================================================
Now lets send it
======================================================================================
  */

 ack_message_send(comm_port,ack_pkt);

/*
=====================================================================================
Finished Sending ACK
=====================================================================================
 */
	exit(0);
	print_help();
	exit(0);

}
