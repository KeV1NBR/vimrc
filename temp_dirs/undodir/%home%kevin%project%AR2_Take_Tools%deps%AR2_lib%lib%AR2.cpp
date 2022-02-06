Vim�UnDo� î��#�-Z���$a^��L�����X�5dV�   �               return -1;   �                          _���    _�                           ����                                                                                                                                                                                                                                                                                                                                                     _ؽ�     �      	          {   ,        printf("gripper readline error!\n");           return -1;       }�       	      *    if(ser->serialReadline(100)!="Done\n")5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _ؽ�    �       �      	   #include <cstdio>   #include <cstdlib>   #include <iostream>   #include <string>   #include "AR2.hpp"   #include "libserialport.h"       using namespace std;   using namespace Eigen;               4AR2::AR2(string portname, int baudrate, double Tool)   V   :deg(6), pos(6), DegPerStep(6), PosAngLim(6), NegAngLim(6), StepLim(6), motorDir(6)   , test(12)    {       e    test <<  0.0001, -90, 90, 0.0001, 90, 0.0001, 286.83, 0.0004373, 438.52, 0.0001, 179.999, 0.0001;   //serial setting       )    ser = new SERIAL(baudrate, portname);           if(ser == nullptr)   .        cout << "serial pointer fail" << endl;       ser -> setting();       //kinimatics setting           VectorXd inALPHA(6);   !    inALPHA  <<-90,0,90,-90,90,0;       VectorXd inD(6);   (    inD  << 169.77,0,0,-222.63,0,-36.25;       VectorXd inA(6);        inA << 64.2,305,0,0,0,0;       VectorXd inBASE(4);       inBASE <<0,0,0,0;       VectorXd inTOOL(4);        inTOOL << 0,0,Tool,0;         3    km = new KM(inBASE, inTOOL, inALPHA, inD, inA);   //other setting       9    this -> PosAngLim <<  172, -3, 151,  266,  148,  180;   8    this -> NegAngLim << -168, -135, 31, -74, -62, -180;   >    this -> StepLim   << 15200, 7300, 7850, 15200, 4575, 6625;       &    this ->DegPerStep(0) = 0.02236842;   &    this ->DegPerStep(1) = 0.01808219;   &    this ->DegPerStep(2) = 0.01783439;   '    this ->DegPerStep(3) = 0.021710526;   '    this ->DegPerStep(4) = 0.045901639;   '    this ->DegPerStep(5) = 0.046792453;       I    this-> pos << test(6), test(7), test(8), test(9), test(10), test(11);   G    this-> deg << test(0), test(1), test(2), test(3), test(4), test(5);       !    motorDir << 1, 1, 1, 1, 1, 1;       }       ,int AR2::moveByDeg(int motor, double degree)   {       VectorXd dir(6);       double calDeg;       int i = motor;       string motorString;       string msg;       :    if(degree > PosAngLim(i-1) || degree < NegAngLim(i-1))       {   2        printf("J%d out of motor limit\n", motor);           return -1;       }       calDeg = degree - deg(i-1);       if(calDeg*motorDir(i-1)<0)           dir(i-1)= 0;       else           dir(i-1)= 1;           if(motor == 1)           motorString = "A";       else if(motor == 2)           motorString = "B";       else if(motor == 3)           motorString = "C";       else if(motor == 4)           motorString = "D";       else if(motor == 5)           motorString = "E";       else if(motor == 6)           motorString = "F";       �    msg = "MJ" + motorString +  to_string((int) dir(i-1)) + to_string(abs( (int) (calDeg / DegPerStep(i-1)))) + "S30G10H10I10K10\n";             ser->serialPrint(msg);       //ser->waitTime(10);          0    if(ser->serialReadline(1000)!="Move Done\n")       {           printf("read error\n");           return -1;       }              this-> deg(i-1) = degree;       :    this-> pos = this-> km->forwardKinematics(this-> deg);       +    cout << "pos\n" << pos << endl << endl;       .    cout << "deg\n"<< deg << endl << endl;               return 0;   }       �int AR2::moveXYZ(double newX, double newY, double newZ, double newy, double newp, double newr, int speed, int accStart, int accDur, int decDur, int decFinal)   {       string msg;       VectorXd newPos(6);   1    newPos << newX, newY, newZ, newy, newp, newr;       VectorXd calDeg(6);       VectorXd dir(6);              VectorXd newDeg;   4    newDeg = this-> km -> inverseKinematics(newPos);       2    cout << "///////pos\n" << pos << endl << endl;   0    cout << "newPos\n" << newPos << endl <<endl;       5    cout << "///////deg\n"<< deg << endl << endl;       /    cout << "newDeg\n"<<newDeg << endl << endl;                   for(int i=0; i<6;i++)       {   <        if(newDeg(i)>PosAngLim(i) || newDeg(i)<NegAngLim(i))   	        {   �            printf("J%d out of motor limit\n   newDeg = %lf     PosLim = %lf     NegDeg = %lf\n", i+1, newDeg(i), PosAngLim(i), NegAngLim(i));               return -1;   	        }       }                      cout <<endl;           for(int i=0;i<6;i++)       {   '        calDeg(i) = newDeg(i) - deg(i);   #        if(calDeg(i)*motorDir(i)<0)               dir(i)= 0;           else                dir(i)= 1;           }         _    msg = "MJA" + to_string((int)dir(0)) + to_string(abs( (int) (calDeg(0) / DegPerStep(0))))+    ^          "B" + to_string((int)dir(1)) + to_string(abs( (int) (calDeg(1) / DegPerStep(1)))) +    ^          "C" + to_string((int)dir(2)) + to_string(abs( (int) (calDeg(2) / DegPerStep(2)))) +    ^          "D" + to_string((int)dir(3)) + to_string(abs( (int) (calDeg(3) / DegPerStep(3)))) +    ^          "E" + to_string((int)dir(4)) + to_string(abs( (int) (calDeg(4) / DegPerStep(4)))) +    ^          "F" + to_string((int)dir(5)) + to_string(abs( (int) (calDeg(5) / DegPerStep(5)))) +    #          "S" + to_string(speed) +    $          "G" + to_string(accDur) +    &          "H" + to_string(accStart) +    $          "I" + to_string(decDur) +    +          "K" + to_string(decFinal) + "\n";                   ser->serialPrint(msg);       //ser->waitTime(10);   0    if(ser->serialReadline(1000)!="Move Done\n")       {           printf("read error");           return -1;       }           this->deg = newDeg;       this->pos = newPos;       return 0;   }       int AR2::goHome()   {       int iResult = 0;       i    iResult = this-> moveXYZ(test(6), test(7), test(8), test(9), test(10), test(11), 30, 10, 10, 10, 10);       //ser->waitTime(10);       if(iResult != 0)       {           printf("read error");           return -1;       }   F    this-> pos <<  286.83, 0.0004373, 438.52, 0.0001, 179.999, 0.0001;   8    this-> deg <<  0.0001, -90, 90, 0.0001, 90, 0.0001 ;           return 0;   }       int AR2::calibration()     {   ?    string msg="LLA015200B07300C17850D015200E04575F16625S50\n";       ser->serialPrint(msg);          ,    if(ser->serialReadline(10000)!="pass\n")       {   #        printf("1readline  error");           return -1;       }       ser->waitTime(10);   <    msg="MJA1500B1500C0500D1500E1500F0500S15G10H10I10K10\n";       ser->serialPrint(msg);   1    if(ser->serialReadline(10000)!="Move Done\n")       {           printf("Read error");           return -1;       }       ser->waitTime(10);   7    msg="LLA015200B07300C17850D015200E04575F16625S8\n";       ser->serialPrint(msg);   ,    if(ser->serialReadline(10000)!="pass\n")       {   #        printf("2readline error!");           return -1;       }              ser->waitTime(10);   D    msg="MJA17643B12495C03427D13305E13309F03334T10S25G15H10I20K5\n";       ser->serialPrint(msg);   1    if(ser->serialReadline(10000)!="Move Done\n")       {   #        printf("2readline error!");           return -1;       }       I    this-> pos << test(6), test(7), test(8), test(9), test(10), test(11);   G    this-> deg << test(0), test(1), test(2), test(3), test(4), test(5);       /    cout << "pos" << endl << pos<<endl << endl;   /    cout << "deg" << endl << deg<<endl << endl;       return 0;   }       int AR2::gripper(string input)   {       string msg;           if(input == "ON")           msg = "ONX41\n";              else if(input == "OFF")           msg = "OFX41\n";           ser->serialPrint(msg);       ,    //if(ser->serialReadline(100)!="Done\n")       //{   .    //    printf("gripper readline error!\n");       //    return -1;       //}              return 0;       }5�_�                    �       ����                                                                                                                                                                                                                                                                                                                                                             _��     �   �   �   �              msg = "ONX41\n";5�_�                    �       ����                                                                                                                                                                                                                                                                                                                                                             _��    �   �   �   �              msg = "OFX41\n";5�_�                   �       ����                                                                                                                                                                                                                                                                                                                                                             _���     �   �   �   �                  return -1;5�_�                             ����                                                                                                                                                                                                                                                                                                                                                             _���    �               �   #include "AR2.hpp"   #include "libserialport.h"   #include <cstdio>   #include <cstdlib>   #include <iostream>   #include <string>       using namespace std;   using namespace Eigen;       4AR2::AR2(string portname, int baudrate, double Tool)       : deg(6)       , pos(6)       , DegPerStep(6)       , PosAngLim(6)       , NegAngLim(6)       , StepLim(6)       , motorDir(6)       , test(12)   {       d    test << 0.0001, -90, 90, 0.0001, 90, 0.0001, 286.83, 0.0004373, 438.52, 0.0001, 179.999, 0.0001;       // serial setting       )    ser = new SERIAL(baudrate, portname);           if (ser == nullptr)   .        cout << "serial pointer fail" << endl;       ser->setting();           // kinimatics setting           VectorXd inALPHA(6);   &    inALPHA << -90, 0, 90, -90, 90, 0;       VectorXd inD(6);   ,    inD << 169.77, 0, 0, -222.63, 0, -36.25;       VectorXd inA(6);   !    inA << 64.2, 305, 0, 0, 0, 0;       VectorXd inBASE(4);       inBASE << 0, 0, 0, 0;       VectorXd inTOOL(4);       inTOOL << 0, 0, Tool, 0;       3    km = new KM(inBASE, inTOOL, inALPHA, inD, inA);       // other setting       3    this->PosAngLim << 172, -3, 151, 266, 148, 180;   6    this->NegAngLim << -168, -135, 31, -74, -62, -180;   :    this->StepLim << 15200, 7300, 7850, 15200, 4575, 6625;       %    this->DegPerStep(0) = 0.02236842;   %    this->DegPerStep(1) = 0.01808219;   %    this->DegPerStep(2) = 0.01783439;   &    this->DegPerStep(3) = 0.021710526;   &    this->DegPerStep(4) = 0.045901639;   &    this->DegPerStep(5) = 0.046792453;       H    this->pos << test(6), test(7), test(8), test(9), test(10), test(11);   F    this->deg << test(0), test(1), test(2), test(3), test(4), test(5);       !    motorDir << 1, 1, 1, 1, 1, 1;   }       ,int AR2::moveByDeg(int motor, double degree)   {       VectorXd dir(6);       double calDeg;       int i = motor;       string motorString;       string msg;       A    if (degree > PosAngLim(i - 1) || degree < NegAngLim(i - 1)) {   2        printf("J%d out of motor limit\n", motor);           return -1;       }   !    calDeg = degree - deg(i - 1);   %    if (calDeg * motorDir(i - 1) < 0)           dir(i - 1) = 0;       else           dir(i - 1) = 1;           if (motor == 1)           motorString = "A";       else if (motor == 2)           motorString = "B";       else if (motor == 3)           motorString = "C";       else if (motor == 4)           motorString = "D";       else if (motor == 5)           motorString = "E";       else if (motor == 6)           motorString = "F";       �    msg = "MJ" + motorString + to_string((int)dir(i - 1)) + to_string(abs((int)(calDeg / DegPerStep(i - 1)))) + "S30G10H10I10K10\n";           ser->serialPrint(msg);       // ser->waitTime(10);       5    if (ser->serialReadline(1000) != "Move Done\n") {           printf("read error\n");           return -1;       }           this->deg(i - 1) = degree;       7    this->pos = this->km->forwardKinematics(this->deg);       +    cout << "pos\n" << pos << endl << endl;       +    cout << "deg\n" << deg << endl << endl;           return 0;   }       �int AR2::moveXYZ(double newX, double newY, double newZ, double newy, double newp, double newr, int speed, int accStart, int accDur, int decDur, int decFinal)   {       string msg;       VectorXd newPos(6);   1    newPos << newX, newY, newZ, newy, newp, newr;       VectorXd calDeg(6);       VectorXd dir(6);           VectorXd newDeg;   1    newDeg = this->km->inverseKinematics(newPos);       2    cout << "///////pos\n" << pos << endl << endl;   1    cout << "newPos\n" << newPos << endl << endl;       2    cout << "///////deg\n" << deg << endl << endl;   1    cout << "newDeg\n" << newDeg << endl << endl;       !    for (int i = 0; i < 6; i++) {   C        if (newDeg(i) > PosAngLim(i) || newDeg(i) < NegAngLim(i)) {   �            printf("J%d out of motor limit\n   newDeg = %lf     PosLim = %lf     NegDeg = %lf\n", i + 1, newDeg(i), PosAngLim(i), NegAngLim(i));               //return -1;   	        }       }           cout << endl;       !    for (int i = 0; i < 6; i++) {   '        calDeg(i) = newDeg(i) - deg(i);   (        if (calDeg(i) * motorDir(i) < 0)               dir(i) = 0;           else               dir(i) = 1;       }      �    msg = "MJA" + to_string((int)dir(0)) + to_string(abs((int)(calDeg(0) / DegPerStep(0)))) + "B" + to_string((int)dir(1)) + to_string(abs((int)(calDeg(1) / DegPerStep(1)))) + "C" + to_string((int)dir(2)) + to_string(abs((int)(calDeg(2) / DegPerStep(2)))) + "D" + to_string((int)dir(3)) + to_string(abs((int)(calDeg(3) / DegPerStep(3)))) + "E" + to_string((int)dir(4)) + to_string(abs((int)(calDeg(4) / DegPerStep(4)))) + "F" + to_string((int)dir(5))   �        + to_string(abs((int)(calDeg(5) / DegPerStep(5)))) + "S" + to_string(speed) + "G" + to_string(accDur) + "H" + to_string(accStart) + "I" + to_string(decDur) + "K" + to_string(decFinal) + "\n";           ser->serialPrint(msg);       // ser->waitTime(10);   5    if (ser->serialReadline(1000) != "Move Done\n") {           printf("read error");           return -1;       }           this->deg = newDeg;       this->pos = newPos;       return 0;   }       int AR2::goHome()   {       int iResult = 0;       h    iResult = this->moveXYZ(test(6), test(7), test(8), test(9), test(10), test(11), 30, 10, 10, 10, 10);       // ser->waitTime(10);       if (iResult != 0) {           printf("read error");           return -1;       }   D    this->pos << 286.83, 0.0004373, 438.52, 0.0001, 179.999, 0.0001;   5    this->deg << 0.0001, -90, 90, 0.0001, 90, 0.0001;           return 0;   }       int AR2::calibration()   {   A    string msg = "LLA015200B07300C17850D015200E04575F16625S50\n";       ser->serialPrint(msg);       1    if (ser->serialReadline(10000) != "pass\n") {   #        printf("1readline  error");           return -1;       }       ser->waitTime(10);   >    msg = "MJA1500B1500C0500D1500E1500F0500S15G10H10I10K10\n";       ser->serialPrint(msg);   6    if (ser->serialReadline(10000) != "Move Done\n") {           printf("Read error");           return -1;       }       ser->waitTime(10);   9    msg = "LLA015200B07300C17850D015200E04575F16625S8\n";       ser->serialPrint(msg);   1    if (ser->serialReadline(10000) != "pass\n") {   #        printf("2readline error!");           return -1;       }           ser->waitTime(10);   F    msg = "MJA17643B12495C03427D13305E13309F03334T10S25G15H10I20K5\n";       ser->serialPrint(msg);   6    if (ser->serialReadline(10000) != "Move Done\n") {   #        printf("2readline error!");           return -1;       }       H    this->pos << test(6), test(7), test(8), test(9), test(10), test(11);   F    this->deg << test(0), test(1), test(2), test(3), test(4), test(5);       1    cout << "pos" << endl << pos << endl << endl;   1    cout << "deg" << endl << deg << endl << endl;       return 0;   }       int AR2::gripper(string input)   {       string msg;           if (input == "ON")           msg = "OFX41\n";           else if (input == "OFF")           msg = "ONX41\n";           ser->serialPrint(msg);       -    // if(ser->serialReadline(100)!="Done\n")       //{   .    //    printf("gripper readline error!\n");       //    return -1;       //}           return 0;   }5�_�                  �       ����                                                                                                                                                                                                                                                                                                                                                             _��&     �   �   �   �                  return -0;5�_�      	              �       ����                                                                                                                                                                                                                                                                                                                                                             _��)   	 �   �   �   �                  return 0;5�_�      
           	   �       ����                                                                                                                                                                                                                                                                                                                                                             _���     �   �   �   �                  //return 0;5�_�   	               
           ����                                                                                                                                                                                                                                                                                                                                                             _���    �       �       �   #include "AR2.hpp"   #include "libserialport.h"   #include <cstdio>   #include <cstdlib>   #include <iostream>   #include <string>       using namespace std;   using namespace Eigen;       4AR2::AR2(string portname, int baudrate, double Tool)       : deg(6)       , pos(6)       , DegPerStep(6)       , PosAngLim(6)       , NegAngLim(6)       , StepLim(6)       , motorDir(6)       , test(12)   {       d    test << 0.0001, -90, 90, 0.0001, 90, 0.0001, 286.83, 0.0004373, 438.52, 0.0001, 179.999, 0.0001;       // serial setting       )    ser = new SERIAL(baudrate, portname);           if (ser == nullptr)   .        cout << "serial pointer fail" << endl;       ser->setting();           // kinimatics setting           VectorXd inALPHA(6);   &    inALPHA << -90, 0, 90, -90, 90, 0;       VectorXd inD(6);   ,    inD << 169.77, 0, 0, -222.63, 0, -36.25;       VectorXd inA(6);   !    inA << 64.2, 305, 0, 0, 0, 0;       VectorXd inBASE(4);       inBASE << 0, 0, 0, 0;       VectorXd inTOOL(4);       inTOOL << 0, 0, Tool, 0;       3    km = new KM(inBASE, inTOOL, inALPHA, inD, inA);       // other setting       3    this->PosAngLim << 172, -3, 151, 266, 148, 180;   6    this->NegAngLim << -168, -135, 31, -74, -62, -180;   :    this->StepLim << 15200, 7300, 7850, 15200, 4575, 6625;       %    this->DegPerStep(0) = 0.02236842;   %    this->DegPerStep(1) = 0.01808219;   %    this->DegPerStep(2) = 0.01783439;   &    this->DegPerStep(3) = 0.021710526;   &    this->DegPerStep(4) = 0.045901639;   &    this->DegPerStep(5) = 0.046792453;       H    this->pos << test(6), test(7), test(8), test(9), test(10), test(11);   F    this->deg << test(0), test(1), test(2), test(3), test(4), test(5);       !    motorDir << 1, 1, 1, 1, 1, 1;   }       ,int AR2::moveByDeg(int motor, double degree)   {       VectorXd dir(6);       double calDeg;       int i = motor;       string motorString;       string msg;       A    if (degree > PosAngLim(i - 1) || degree < NegAngLim(i - 1)) {   2        printf("J%d out of motor limit\n", motor);           return -1;       }   !    calDeg = degree - deg(i - 1);   %    if (calDeg * motorDir(i - 1) < 0)           dir(i - 1) = 0;       else           dir(i - 1) = 1;           if (motor == 1)           motorString = "A";       else if (motor == 2)           motorString = "B";       else if (motor == 3)           motorString = "C";       else if (motor == 4)           motorString = "D";       else if (motor == 5)           motorString = "E";       else if (motor == 6)           motorString = "F";       �    msg = "MJ" + motorString + to_string((int)dir(i - 1)) + to_string(abs((int)(calDeg / DegPerStep(i - 1)))) + "S30G10H10I10K10\n";           ser->serialPrint(msg);       // ser->waitTime(10);       5    if (ser->serialReadline(1000) != "Move Done\n") {           printf("read error\n");           return -1;       }           this->deg(i - 1) = degree;       7    this->pos = this->km->forwardKinematics(this->deg);       +    cout << "pos\n" << pos << endl << endl;       +    cout << "deg\n" << deg << endl << endl;           return 0;   }       �int AR2::moveXYZ(double newX, double newY, double newZ, double newy, double newp, double newr, int speed, int accStart, int accDur, int decDur, int decFinal)   {       string msg;       VectorXd newPos(6);   1    newPos << newX, newY, newZ, newy, newp, newr;       VectorXd calDeg(6);       VectorXd dir(6);           VectorXd newDeg;   1    newDeg = this->km->inverseKinematics(newPos);       2    cout << "///////pos\n" << pos << endl << endl;   1    cout << "newPos\n" << newPos << endl << endl;       2    cout << "///////deg\n" << deg << endl << endl;   1    cout << "newDeg\n" << newDeg << endl << endl;       !    for (int i = 0; i < 6; i++) {   C        if (newDeg(i) > PosAngLim(i) || newDeg(i) < NegAngLim(i)) {   �            printf("J%d out of motor limit\n   newDeg = %lf     PosLim = %lf     NegDeg = %lf\n", i + 1, newDeg(i), PosAngLim(i), NegAngLim(i));               // return 0;   	        }       }           cout << endl;       !    for (int i = 0; i < 6; i++) {   '        calDeg(i) = newDeg(i) - deg(i);   (        if (calDeg(i) * motorDir(i) < 0)               dir(i) = 0;           else               dir(i) = 1;       }      �    msg = "MJA" + to_string((int)dir(0)) + to_string(abs((int)(calDeg(0) / DegPerStep(0)))) + "B" + to_string((int)dir(1)) + to_string(abs((int)(calDeg(1) / DegPerStep(1)))) + "C" + to_string((int)dir(2)) + to_string(abs((int)(calDeg(2) / DegPerStep(2)))) + "D" + to_string((int)dir(3)) + to_string(abs((int)(calDeg(3) / DegPerStep(3)))) + "E" + to_string((int)dir(4)) + to_string(abs((int)(calDeg(4) / DegPerStep(4)))) + "F" + to_string((int)dir(5))   �        + to_string(abs((int)(calDeg(5) / DegPerStep(5)))) + "S" + to_string(speed) + "G" + to_string(accDur) + "H" + to_string(accStart) + "I" + to_string(decDur) + "K" + to_string(decFinal) + "\n";           ser->serialPrint(msg);       // ser->waitTime(10);   5    if (ser->serialReadline(1000) != "Move Done\n") {           printf("read error");           return -1;       }           this->deg = newDeg;       this->pos = newPos;       return 0;   }       int AR2::goHome()   {       int iResult = 0;       h    iResult = this->moveXYZ(test(6), test(7), test(8), test(9), test(10), test(11), 30, 10, 10, 10, 10);       // ser->waitTime(10);       if (iResult != 0) {           printf("read error");           return -1;       }   D    this->pos << 286.83, 0.0004373, 438.52, 0.0001, 179.999, 0.0001;   5    this->deg << 0.0001, -90, 90, 0.0001, 90, 0.0001;           return 0;   }       int AR2::calibration()   {   A    string msg = "LLA015200B07300C17850D015200E04575F16625S50\n";       ser->serialPrint(msg);       1    if (ser->serialReadline(10000) != "pass\n") {   #        printf("1readline  error");           return -1;       }       ser->waitTime(10);   >    msg = "MJA1500B1500C0500D1500E1500F0500S15G10H10I10K10\n";       ser->serialPrint(msg);   6    if (ser->serialReadline(10000) != "Move Done\n") {           printf("Read error");           return -1;       }       ser->waitTime(10);   9    msg = "LLA015200B07300C17850D015200E04575F16625S8\n";       ser->serialPrint(msg);   1    if (ser->serialReadline(10000) != "pass\n") {   #        printf("2readline error!");           return -1;       }           ser->waitTime(10);   F    msg = "MJA17643B12495C03427D13305E13309F03334T10S25G15H10I20K5\n";       ser->serialPrint(msg);   6    if (ser->serialReadline(10000) != "Move Done\n") {   #        printf("2readline error!");           return -1;       }       H    this->pos << test(6), test(7), test(8), test(9), test(10), test(11);   F    this->deg << test(0), test(1), test(2), test(3), test(4), test(5);       1    cout << "pos" << endl << pos << endl << endl;   1    cout << "deg" << endl << deg << endl << endl;       return 0;   }       int AR2::gripper(string input)   {       string msg;           if (input == "ON")           msg = "OFX41\n";           else if (input == "OFF")           msg = "ONX41\n";           ser->serialPrint(msg);       -    // if(ser->serialReadline(100)!="Done\n")       //{   .    //    printf("gripper readline error!\n");       //    return -1;       //}           return 0;   }5�_�                   �       ����                                                                                                                                                                                                                                                                                                                                                             _��!     �   �   �   �                  return 0;5�_�                     �       ����                                                                                                                                                                                                                                                                                                                                                             _��(    �   �   �   �              return 0;5��