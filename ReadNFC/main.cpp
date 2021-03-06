#include<stdio.h>
#include<ctacs/ct_api.h>
#include<iostream>

 int main(int argc, char *argv[])
 {
     char ret;

      unsigned short ctn;
      unsigned short pn;
      unsigned short sad;
      unsigned short dad;
 
      // REQUEST ICC
      unsigned char command[] = { 0x20, 0x12, 0x01, 0x00, 0x00 };
      unsigned short lenc = sizeof(command);
 
      unsigned char response[300];
      unsigned short lenr = sizeof(response);
 
       ctn = 1;
       pn = 3500;
 
      // Initialize card terminal
      ret = CT_init(ctn, pn);
      std::cout<<std::hex<<ret<<std::endl;
      if (ret != OK)
      {
          printf("Error: CT_init failed with error %d\n", ret);
          return 1;
      }
 
      sad = 2; // Source = Host
      dad = 1; // Destination = Card Terminal
 
     
 
      // Close card terminal
      ret = CT_close(ctn);
      if (ret != OK)
          printf("Error: CT_close failed with error %d\n", ret);
 
      return 0;
  }

