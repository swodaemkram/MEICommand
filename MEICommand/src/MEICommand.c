/*
 ============================================================================
 Name        : MEICommand.c
 Author      : Mark Meadows
 Version     :
 Copyright   : Fireking Security Group
 Description : MEICommand in C, Ansi-style
 ============================================================================
 */

#include "mei_header.h"

int main(int argc, char *argv[]) {

//system("clear"); //Clear the screen
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
Figure out what the command byte should be (this is C so no switch statement with string
compare so we have to do if statements !)
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
		pkt_command = MEI_GETQP;
	}

	if (strcmp(command,"MEI_GETPERF" )== 0 ){
		pkt_command = MEI_GETPERF;
	}

	if (strcmp(command,"MEI_GETBNF" )== 0 ){
		pkt_command = MEI_GETBNF;
	}

	if (strcmp(command,"MEI_POLL" )== 0 ){
		pkt_command = MEI_POLL;
	}

	if (strcmp(command,"MEI_GETBILLS")== 0){
		pkt_command = MEI_GETBILLS;
	}

	if (strcmp(command,"MEI_STACK") == 0){
		pkt_command = MEI_STACK;
	}

	if (strcmp(command,"MEI_RETURN")== 0 ){
		pkt_command = MEI_RETURN;
	}

	if (strcmp(command,"MEI_RETRIEVE") == 0){
		pkt_command = MEI_RETRIEVE;
	}

	if (strcmp(command, "MEI_Number_Of_Resets") == 0){
		pkt_command = '\xb2';
	}





/*
===============================================================================================
        End of Auxiliary Commands
================================================================================================
		Start of Commands
(this is C so no switch statement with string
compare so we have to do if statements !)
================================================================================================
*/

	//if (strcmp(command,"enable" )== 0 ){
	//		pkt_command = MEI_RETRIEVE;

	//}

	if (strcmp(command,"disable" )== 0 ){
			printf("\nThis Feature not Implemented Yet...\n");
			exit(0);
	}

	if (strcmp(command,"MEI_RESET" )== 0 ){
			pkt_command = MEI_RESET;

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
		pkt_command = MEI_BOOKMARK;
			//printf("\nThis Feature not Implemented Yet...\n");
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
//	setup_serial_port(comm_port);
/*
=====================================================================================
Serial Port is Setup
=====================================================================================
Lets Build The Packet to be transmitted
=====================================================================================
 */
 char * pkt;

 if ( pkt_command == MEI_ACCEPTING) {			   //MEI_ACCEPTING Command
	 pkt = build_packet_cmd(pkt_command);
 }

 if(pkt_command == MEI_RESET){					   //MEI_RESET
	 pkt = build_packet_reset(pkt_command);
 }

if(pkt_command == MEI_POLL){					    //MEI_POLL
	pkt = build_packet_cmd(pkt_command);
}

if(pkt_command == MEI_BOOKMARK){					//MEI_BOOKMARK
	pkt = build_packet_ext_cmd(pkt_command);
}

if (pkt_command == MEI_GETBILLS){					       //MEI_GETBILLS
	pkt_command = MEI_GETBILLS;
	pkt = build_packet_ext_cmd(pkt_command);
}

if (pkt_command == MEI_RETRIEVE){					//MEI_RETRIEVE
	pkt = build_packet_ext_cmd(pkt_command);
}

if(pkt_command == '\xb2'){
	pkt_command = '\x02';
	pkt = build_packet(pkt_command);
}


//All other MEI_GET commands

if(pkt_command >= 4 && pkt_command != MEI_RESET){
   pkt = build_packet(pkt_command);
 }




/*
=====================================================================================
Finished Building Packet
=====================================================================================
Send Packet to MEI unit
=====================================================================================
 */
 send_pkt(comm_port,pkt,pkt_command); //send the bloody packet
 /*
=====================================================================================
Packet Sent now we need to ACK the packet
=====================================================================================
Send ACK
======================================================================================
  */
// ack_message_send(comm_port,ack_pkt);

ack_message_send(comm_port,pkt);

 /*
=====================================================================================
Finished Sending ACK
=====================================================================================
 */
	exit(0);

}
