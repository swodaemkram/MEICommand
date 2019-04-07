/*
 * build_packet_cmd.c
 *
 *  Created on: Apr 7, 2019
 *      Author: mark
 */



char *build_packet_cmd(unsigned int pkt_command){

	static char pkt[30] = "\x02\x08\x10\x00\x00\x10\x03"; //packet Skeleton
		pkt[4] = pkt_command;						   //Pop command into packet Skeleton
		int pkt_length = 8;	               //Get packet size
		unsigned int crc_val;
		crc_val = do_crc(pkt, pkt_length);             //Lets get crc of the packet
		pkt[7] = crc_val;                 //Tac on crc to the end of the packet
		printf("This is the cmd packet I'm sending --> %02x%02x%02x%02x%02x%02x%02x%02x\n\n",pkt[0],pkt[1],pkt[2],pkt[3],pkt[4],pkt[5],pkt[6],pkt[7]);


	return pkt;
}
