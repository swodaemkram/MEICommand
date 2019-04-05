/*
 * build_packet_ext_cmd.h
 *
 *  Created on: Apr 4, 2019
 *      Author: mark
 */

#ifndef BUILD_PACKET_EXT_CMD_H_
#define BUILD_PACKET_EXT_CMD_H_



#endif /* BUILD_PACKET_EXT_CMD_H_ */

char *build_packet_ext_cmd(unsigned int pkt_command){

	static char pkt[30] = "\x02\x10\x70\x00\x00\x10\x10\x01\x03"; //packet Skeleton

			pkt[3] = pkt_command;						   //Pop command into packet Skeleton
			int pkt_length = 10;	               //Get packet size
			unsigned int crc_val;
			crc_val = do_crc(pkt, pkt_length);             //Lets get crc of the packet

			pkt[9] = crc_val;                 //Tac on crc to the end of the packet

			printf("This is the string I'm sending --> %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\n\n",pkt[0],pkt[1],pkt[2],pkt[3],pkt[4],pkt[5],pkt[6],pkt[7],pkt[8],pkt[9]);

return pkt;


}
