/*
 * build_packet.h
 *
 *  Created on: Mar 27, 2019
 *      Author: markm
 */

#ifndef BUILD_PACKET_H_
#define BUILD_PACKET_H_

#endif /* BUILD_PACKET_H_ */

char * build_packet(unsigned int pkt_command){

	static char pkt[30] = "\x02\x08\x60\x00\x00\x00\x03"; //packet Skeleton
	pkt[5] = pkt_command;						   //Pop command into packet Skeleton
	int pkt_length = 8;	               //Get packet size
	unsigned int crc_val;
	crc_val = do_crc(pkt, pkt_length);             //Lets get crc of the packet
	pkt[7] = crc_val;                 //Tac on crc to the end of the packet
	//printf("This is the string I'm sending --> %02x%02x%02x%02x%02x%02x%02x%02x\n\n",pkt[0],pkt[1],pkt[2],pkt[3],pkt[4],pkt[5],pkt[6],pkt[7]);
	return pkt;                     //send the packet to be transmitted
}
