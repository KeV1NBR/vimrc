Vim�UnDo� 5B���۲�	3}��X`��*%ZȾ��E�@��+   1   )    msg = "ONX" + to_string(ping) + "\n";   (          
       
   
   
    _2��    _�                     $       ����                                                                                                                                                                                                                                                                                                                                                             _2��     �   #              }5�_�                    %       ����                                                                                                                                                                                                                                                                                                                                                             _2��     �   $              int SUCKER::cvtr()5�_�                    %       ����                                                                                                                                                                                                                                                                                                                                                             _2��     �   %   '   '          �   %   '   &    �   $              int SUCKER::cvtr(int air)5�_�                   &       ����                                                                                                                                                                                                                                                                                                                                      #          v       _2��     �   %   ,   '          ``�   &   '   '    5�_�                    &       ����                                                                                                                                                                                                                                                                                                                                      #          v       _2��     �   %   '   ,          `string msg;5�_�                    +       ����                                                                                                                                                                                                                                                                                                                                      #          v       _2��     �   *   ,   ,          return 0;`5�_�      	              (        ����                                                                                                                                                                                                                                                                                                                                      #          v       _2��     �   '   )   ,      )    msg = "ONX" + to_string(ping) + "\n";5�_�      
           	   (       ����                                                                                                                                                                                                                                                                                                                                      #          v       _2��     �   '   )   ,      (    msg = "ONX" + to_string(air) + "\n";5�_�   	               
           ����                                                                                                                                                                                                                                                                                                                                      #          v       _2��    �               ,   #include <iostream>   #include <string>       #include "serial.hpp"   #include "sucker.h"       using namespace std;       -SUCKER::SUCKER(string portName, int pingIn) {       this->ping = pingIn;       +    this->ser = new SERIAL(9600, portName);       A    if (ser == nullptr) cout << "serial pointer    fail" << endl;       ser->setting();           // this->close();   }       int SUCKER::open() {       string msg;       )    msg = "OFX" + to_string(ping) + "\n";           ser->serialPrint(msg);       return 0;   }       int SUCKER::close() {       string msg;       )    msg = "ONX" + to_string(ping) + "\n";           ser->serialPrint(msg);       return 0;   }   int SUCKER::cvtr(int air){       string msg;       (    msg = "CVX" + to_string(air) + "\n";           ser->serialPrint(msg);       return 0;   }5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _2��     �         '          vstring msg;5��