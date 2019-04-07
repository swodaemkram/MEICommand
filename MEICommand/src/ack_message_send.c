/*
 * ack_message_send.c
 *
 *  Created on: Apr 7, 2019
 *      Author: mark
 */
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>


void ack_message_send(char *comm_port,char *pkt){

	int set_interface_attribs(int fd, int speed)
			{
			    struct termios tty;

			    if (tcgetattr(fd, &tty) < 0) {
			        printf("Error from tcgetattr: %s\n", strerror(errno));
			        return -1;
			    }

			    cfsetospeed(&tty, (speed_t)speed);
			    cfsetispeed(&tty, (speed_t)speed);

			    tty.c_cflag |= (CLOCAL | CREAD);    /* ignore modem controls */
			    tty.c_cflag &= ~CSIZE;
			    tty.c_cflag |=  CS7;         /* 7-bit characters  pipes = yes ampersands and Tildes= no */
			    tty.c_cflag |=  PARENB;     /* even parity bit */
			    tty.c_cflag &= ~CSTOPB;     /* only need 1 stop bit */
			    tty.c_cflag &= ~CRTSCTS;    /* no hardware flowcontrol */

			    /* setup for non-canonical mode */

			    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
			    tty.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
			    tty.c_oflag &= ~OPOST;

			    /* fetch bytes as they become available */
			    tty.c_cc[VMIN] = 1;
			    tty.c_cc[VTIME] = 1;

			    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
			        printf("Error from tcsetattr: %s\n", strerror(errno));
			        return -1;
			    }
			    return 0;
			}

			char *portname = comm_port;
			    int fd;
			    //int wlen;

			    fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
			    if (fd < 0) {
			        printf("Error opening %s: %s\n", portname, strerror(errno));
			        exit(1);
			    }
			    /*baudrate 9600, 7 bits, even parity, 1 stop bit */
			    set_interface_attribs(fd, B9600);
	/*
	---------------------------------------------------------------------------------------------------------------------
	Ready to transmit
	---------------------------------------------------------------------------------------------------------------------
	 */
			    // set_mincount(fd, 0);                /* set to pure timed read */
	/*
	======================================================================================================================
	Transmit
	======================================================================================================================
	*/

	pkt[2] = '\x01'; //ACK NUMBER
	unsigned int crc_val;
	int pkt_length = 0;
	pkt_length = sizeof(pkt);                      //How long is the packet
	crc_val = do_crc(pkt, pkt_length);             //Lets get crc of the packet
	pkt[ pkt_length - 1] = crc_val;                 //Tac on crc to the end of the packet
	//printf("This is the string I'm sending --> %02x%02x%02x%02x%02x%02x%02x%02x\n\n",pkt[0],pkt[1],pkt[2],pkt[3],pkt[4],pkt[5],pkt[6],pkt[7]);
    write(fd,pkt,sizeof(pkt));
	tcdrain(fd);    /* delay for output */
	return;

}
