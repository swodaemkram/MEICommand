

char *build_packet_ext_cmd(unsigned int pkt_command){






	static char pkt[30] = "\x02\x10\x70\x02\x02\x08\x10\x01\x03"; //packet Skeleton
    //                     STX #BYTS ext cmd        stuff   ETX
			pkt[3] = pkt_command;						   //Pop command into packet Skeleton
			int pkt_length = 10;	               //Get packet size
			unsigned int crc_val;
			crc_val = do_crc(pkt, pkt_length);             //Lets get crc of the packet
			pkt[9] = crc_val;                 //Tac on crc to the end of the packet
			printf("This is the EXT Packet I'm sending --> %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\n\n",pkt[0],pkt[1],pkt[2],pkt[3],pkt[4],pkt[5],pkt[6],pkt[7],pkt[8],pkt[9]);

return pkt;


}
