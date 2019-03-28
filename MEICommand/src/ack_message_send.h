/*
 * ack_message.h
 *
 *  Created on: Mar 28, 2019
 *      Author: mark
 */

#ifndef ACK_MESSAGE_H_
#define ACK_MESSAGE_H_



#endif /* ACK_MESSAGE_H_ */

void ack_message_send(char *comm_port,char *ack_pkt){

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


	write(fd,ack_pkt,sizeof(ack_pkt));
	tcdrain(fd);    /* delay for output */







	return;
}
