Vim�UnDo� /�����{E+{,��)���Bv|�
{�Db               cerr()            (       (   (   (    _�5�   	 _�                             ����                                                                                                                                                                                                                                                                                                                                                             _�3�     �                   5�_�                       
    ����                                                                                                                                                                                                                                                                                                                                                             _�3�     �                  #include ""5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _�3�     �                  #include "realsense.h"5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _�3�     �                5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _�3�    �                5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _�3�     �                 int usb_reset()5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _�3�     �                using namespace rs;5�_�      	                     ����                                                                                                                                                                                                                                                                                                                                                             _�3�     �                 int usb_reset(string )5�_�      
           	          ����                                                                                                                                                                                                                                                                                                                                                             _�3�     �                 int usb_reset(string dev)5�_�   	              
           ����                                                                                                                                                                                                                                                                                                                                                             _�3�    �                  #include "realsense.h"       using namespace std;   int usb_reset(string dev){}5�_�   
                        ����                                                                                                                                                                                                                                                                                                                                                             _�3�     �      
   	              �             �                	        }�                        if (fd < 0) {�                   �             �                 int usb_reset(string dev) {}5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _�3�     �                "    fd = open(filename, O_WRONLY);5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _�4     �                    if (fd < 0) {5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _�4     �                4                perror("Error opening output file");5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _�4     �                !                        return 1;5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _�4     �                                            5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _�4     �                    }5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _�4
     �                 }5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _�4     �                5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _�4A     �                    dev_id = open(dev, O_WRONLY)5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _�4F     �                #include "realsense.h"5�_�                       
    ����                                                                                                                                                                                                                                                                                                                                                             _�4J     �         	      #include <>5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _�4N     �         	      #include <iostream>5�_�                       
    ����                                                                                                                                                                                                                                                                                                                                                             _�4`     �         
      #include <>5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _�4b     �         
      #include <sys/ioctl.h>5�_�                       
    ����                                                                                                                                                                                                                                                                                                                                                             _�4r     �               #include <>5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _�4u    �                  #include "realsense.h"       #include <iostream>   #include <sys/ioctl.h>   #include <linux/usbdevice_fs.h>       using namespace std;   int usb_reset(string dev) {       int dev_id;   !    dev_id = open(dev, O_WRONLY);   }5�_�                    	       ����                                                                                                                                                                                                                                                                                                                                                             _�4�     �      
             int dev_id;5�_�                    
   
    ����                                                                                                                                                                                                                                                                                                                                                             _�4�    �   	            !    dev_id = open(dev, O_WRONLY);5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _�4�     �      	         #include <iostream>5�_�                             ����                                                                                                                                                                                                                                                                                                                                                             _�4�     �                #include <linux/usbdevice_fs.h>5�_�      !                       ����                                                                                                                                                                                                                                                                                                                                                             _�4�    �                  #include "realsense.h"       #include <sys/ioctl.h>   #include <iostream>   #include <sys/types.h>   #include <sys/stat.h>   #include <fcntl.h>       using namespace std;   int usb_reset(string dev) {       int fd;       fd = open(dev, O_WRONLY);   }5�_�       "           !          ����                                                                                                                                                                                                                                                                                                                                                             _�5B    �                   fd = open(dev, O_WRONLY);5�_�   !   #           "      %    ����                                                                                                                                                                                                                                                                                                                                                             _�5N     �                       �             �                      }�                      if (fd < 0) {�               %    fd = open(dev.c_str(), O_WRONLY);5�_�   "   $           #          ����                                                                                                                                                                                                                                                                                                                                                             _�5x     �                4                perror("Error opening output file");5�_�   #   %           $          ����                                                                                                                                                                                                                                                                                                                                                             _�5{     �               !                        return 1;5�_�   $   &           %          ����                                                                                                                                                                                                                                                                                                                                                             _�5|     �                   if (fd < 0) {5�_�   %   '           &          ����                                                                                                                                                                                                                                                                                                                                                             _�5�     �                       cerr()5�_�   &   (           '          ����                                                                                                                                                                                                                                                                                                                                                             _�5�     �                       cerr<<<<endl;5�_�   '               (           ����                                                                                                                                                                                                                                                                                                                                                             _�5�   	 �                  #include "realsense.h"       #include <fcntl.h>   #include <sys/ioctl.h>   #include <sys/stat.h>   #include <sys/types.h>   #include <iostream>       using namespace std;   int usb_reset(string dev) {       int fd;   %    fd = open(dev.c_str(), O_WRONLY);       if (fd < 0) {           cerr<<""<<endl;   "                        return -1;                                      }   }5��