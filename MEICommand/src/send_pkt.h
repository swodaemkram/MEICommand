/*
 * send_pkt.h
 *
 *  Created on: Mar 28, 2019
 *      Author: mark
 */

#ifndef SEND_PKT_H_
#define SEND_PKT_H_



#endif /* SEND_PKT_H_ */
 void send_pkt (char *comm_port,char *pkt, unsigned int pkt_command){

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
write(fd,pkt,sizeof(pkt));
tcdrain(fd);    /* delay for output */
/*
======================================================================================================================
Receive
======================================================================================================================
*/

if(pkt_command == '\x7f'){
	 printf("\nRESET normally gets no response from the MEI ....\n");
	 exit(0);
 }




char output[80];
int q = 0;

do {
    unsigned char buf[80];
    int rdlen;

    rdlen = read(fd, buf, sizeof(buf) - 1);
    if (rdlen > 0) {

       //DISPLAY_STRING
       int i = 0;
       while(i <= rdlen){
       //printf("%d",buf[i]); //Debug Code
       if (buf[i] == '\x03'){ //Look for the End of Transmission Character and stop

    	   output[q] = '\0';
    	   printf("\nMEI Returned ---> %s\n\n",output);
    	   return;
       }
       	   	   	   	    if (buf[i] >= 48 && buf[i] <= 122 && buf[i] != 96){ //Block as many non-printable characters as we can
       	   	   	   	    output[q] = buf[i];
           	   		    //printf("%d\n",output[q]); //Debug Code
                        q++;

       	   	   	   	    }

       	  i++;
       }

       //printf("%s",  buf);
       //printf("\n");
       buf[rdlen] = 0;
       i = 0;
        //display hex
        //unsigned char   *p;
        //printf("Read %d:", rdlen);
        //for (p = buf; rdlen-- > 0; p++)
        //    printf(" 0x%x", *p);
        // printf("\n");

    } else if (rdlen < 0) {
        printf("Error from read: %d: %s\n", rdlen, strerror(errno));
    } else {  /* rdlen == 0 */
        printf("Timeout from read\n");
    }


} while (1);

return;

 }

