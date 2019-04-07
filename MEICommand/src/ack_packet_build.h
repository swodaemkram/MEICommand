/*
 * ack_packet_build.h
 *
 *  Created on: Mar 28, 2019
 *      Author: mark
 */

#ifndef ACK_PACKET_BUILD_H_
#define ACK_PACKET_BUILD_H_





char * ack_packet_build(unsigned int pkt_command){

	static char ack_pkt[30] = "\x02\x08\x01\x00\x00\x00\x03"; //packet Skeleton for Ack
		ack_pkt[5] = pkt_command;						   //Pop command into packet Skeleton
		int ack_pkt_length = 8;	               //Get packet size
		unsigned int crc_val;
		crc_val = do_crc(ack_pkt, ack_pkt_length);             //Lets get crc of the packet
		ack_pkt[7] = crc_val;                 //Tac on crc to the end of the packet
		//printf("This is the string I'm sending --> %02x%02x%02x%02x%02x%02x%02x%02x\n\n",pkt[0],pkt[1],pkt[2],pkt[3],pkt[4],pkt[5],pkt[6],pkt[7]);
		return ack_pkt;                     //send the packet to be transmitted

}

#endif /* ACK_PACKET_BUILD_H_ */
