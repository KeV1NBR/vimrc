Vim�UnDo� )	/=��1�.�=Y��Q(�p?����!�f����   P                 J       J   J   J    ]�    _�                             ����                                                                                                                                                                                                                                                                                                                                                             \�k�     �                #include "object_degree.hpp"5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             \�k�     �         W    �         W    5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             \�k�    �         X          #include <yolo_v2_class.hpp>�         X      #include <yolo_v2_class.hpp>5�_�                    =        ����                                                                                                                                                                                                                                                                                                                                                             \�l     �   <   >          <        std::vector<bbox_t_deg> detectObject(cv::Mat image);5�_�                    I        ����                                                                                                                                                                                                                                                                                                                                                             \�l      �   H   J          (        std::vector<bbox_t_deg> predict;5�_�                    =        ����                                                                                                                                                                                                                                                                                                                                                             \�l.     �   <   >          9        std::vector<bbox__t> detectObject(cv::Mat image);5�_�                    I        ����                                                                                                                                                                                                                                                                                                                                                             \�l/    �   H   J          %        std::vector<bbox__t> predict;5�_�      	                     ����                                                                                                                                                                                                                                                                                                                                                             \�m�     �      	   W      -class Detector_deg;     //Forward declarition5�_�      
           	   F       ����                                                                                                                                                                                                                                                                                                                                                             \�n    �   E   G   W      &        Detector_deg* model = nullptr;5�_�   	              
   =       ����                                                                                                                                                                                                                                                                                                                                                             \�+     �   <   =          8        std::vector<bbox_t> detectObject(cv::Mat image);5�_�   
                 =        ����                                                                                                                                                                                                                                                                                                                                                             \�,     �   <   =           5�_�                    ;        ����                                                                                                                                                                                                                                                                                                                                                             \�-    �   :   ;           5�_�                    $       ����                                                                                                                                                                                                                                                                                                                                                             \�چ     �   #   %   T              void pick_pos(5�_�                   2       ����                                                                                                                                                                                                                                                                                                                            2          ;           v       \�ڻ     �   1   3   T              void put_paper(   +                const SenseData& senseData,   "                PlanData& planData                   );               void put_plastic(   +                const SenseData& senseData,   "                PlanData& planData                   );               bool finished;5�_�                    (       ����                                                                                                                                                                                                                                                                                                                            2          2          v       \��     �   '   )   J              void tracing(5�_�                    -       ����                                                                                                                                                                                                                                                                                                                            2          2          v       \��     �   ,   .   J              void put_metal(5�_�                    E       ����                                                                                                                                                                                                                                                                                                                            2          2          v       \��&    �   D   E                  // 動作們5�_�                    A       ����                                                                                                                                                                                                                                                                                                                            2          2          v       \���     �   @   A                  PID* pid = nullptr;5�_�                    A       ����                                                                                                                                                                                                                                                                                                                            2          2          v       \���     �   @   A                  double* move = nullptr;5�_�                    @        ����                                                                                                                                                                                                                                                                                                                            2          2          v       \���     �   ?   @                  // PID5�_�                    @        ����                                                                                                                                                                                                                                                                                                                            2          2          v       \���     �   ?   @           5�_�                    <   #    ����                                                                                                                                                                                                                                                                                                                            2          2          v       \���     �   ;   =   E      $        std::vector<bbox_t> predict;5�_�                    =       ����                                                                                                                                                                                                                                                                                                                            2          2          v       \��     �   <   =                  int failure_count;5�_�                    =       ����                                                                                                                                                                                                                                                                                                                            2          2          v       \��    �   <   =                  int pick_number;5�_�                    
        ����                                                                                                                                                                                                                                                                                                                            2          2          v       \���     �   	   
          
class PID;5�_�                    ;   #    ����                                                                                                                                                                                                                                                                                                                            1          1          v       \��    �   :   =   B      #        std::vector<bbox_t> result;5�_�                    ;   "    ����                                                                                                                                                                                                                                                                                                                                                             \�+p     �   :   <   C      #        std::vector<bbox_t> result;5�_�                    ;   #    ����                                                                                                                                                                                                                                                                                                                                                             \�+w     �   :   <   C      %        std::vector<bbox_t> result_L;5�_�                    ;   '    ����                                                                                                                                                                                                                                                                                                                                                             \�+~     �   :   =   C      '        std::vector<bbox_t> resultLeft;5�_�                     <        ����                                                                                                                                                                                                                                                                                                                                                             \�+�     �   <   >   E              �   <   >   D    5�_�      !               =       ����                                                                                                                                                                                                                                                                                                                                                             \�+�     �   =   ?   E    �   =   >   E    5�_�       "           !   =       ����                                                                                                                                                                                                                                                                                                                                                             \�+�     �   :   <   E      '        std::vector<bbox_t> resultLeft;    �   ;   =   F           �   <   >   F              5�_�   !   #           "   <   &    ����                                                                                                                                                                                                                                                                                                                                                             \�+�   	 �   ;   =   D      '        std::vector<bbox_t> resultLeft;5�_�   "   $           #   <   (    ����                                                                                                                                                                                                                                                                                                                                                             \�3�   
 �   ;   >   D      (        std::vector<bbox_t> resultRight;5�_�   #   %           $   >       ����                                                                                                                                                                                                                                                                                                                                                             \�i�    �   =   A   E              int camNum;5�_�   $   &           %           ����                                                                                                                                                                                                                                                                                                                                                             \�jz     �         G      #include <yolo_v2_class.hpp>5�_�   %   '           &          ����                                                                                                                                                                                                                                                                                                                                                             \�j~     �      	   H      #include <yolo_v2_class.hpp>5�_�   &   (           '          ����                                                                                                                                                                                                                                                                                                                                                             \�j�    �      	   I      struct ann_t5�_�   '   )           (           ����                                                                                                                                                                                                                                                                                                                                                             \�k
     �      	   I      struct ann_t;5�_�   (   +           )           ����                                                                                                                                                                                                                                                                                                                                                             \�k    �      	   I      #include <yolo_v2_class.hpp>    �      	   I       5�_�   )   ,   *       +          ����                                                                                                                                                                                                                                                                                                                                                             \�kK     �      	   I      typedef struct 5�_�   +   -           ,          ����                                                                                                                                                                                                                                                                                                                                                             \�kT    �   
      I      // PID5�_�   ,   .           -          ����                                                                                                                                                                                                                                                                                                                                                             \�k�    �         J      typedef struct 5�_�   -   /           .          ����                                                                                                                                                                                                                                                                                                                                                             \�k�    �         J      !typedef struct ANNSTRUCT* ann_t; 5�_�   .   0           /   B        ����                                                                                                                                                                                                                                                                                                                                                             \�l%     �   A   C   J       5�_�   /   1           0   B       ����                                                                                                                                                                                                                                                                                                                                                             \�l+    �   A   D   J              //ANN5�_�   0   2           1   D       ����                                                                                                                                                                                                                                                                                                                                                             \�t�     �   C   E   K              ann_t ann;5�_�   1   3           2   D       ����                                                                                                                                                                                                                                                                                                                                                             \�t�    �   C   F   K              ann_t annLeft;5�_�   2   4           3   E       ����                                                                                                                                                                                                                                                                                                                                                             \�t�    �   D   F   L              ann_t annRight5�_�   3   5           4   A       ����                                                                                                                                                                                                                                                                                                                                                             ]��     �   @   C   L              int camNum;5�_�   4   6           5   B       ����                                                                                                                                                                                                                                                                                                                                                             ]��    �   A   C   M              int targetNum5�_�   5   7           6   B       ����                                                                                                                                                                                                                                                                                                                                                             ]��     �   A   D   M              int targetNum;5�_�   6   8           7   C        ����                                                                                                                                                                                                                                                                                                                                                             ]��     �   B   D   N       5�_�   7   9           8   C       ����                                                                                                                                                                                                                                                                                                                                                             ]�     �   B   D   N              float output;5�_�   8   :           9   C       ����                                                                                                                                                                                                                                                                                                                                                             ]�
     �   B   D   N              float output[2];5�_�   9   ;           :   C       ����                                                                                                                                                                                                                                                                                                                                                             ]�    �   B   D   N              float output[2]``;5�_�   :   <           ;   C       ����                                                                                                                                                                                                                                                                                                                                                             ]��     �   B   D   N              float output[2];5�_�   ;   =           <   C       ����                                                                                                                                                                                                                                                                                                                                                             ]��    �   B   D   N              float output;5�_�   <   >           =   C       ����                                                                                                                                                                                                                                                                                                                                                             ]��     �   B   D   N              float* output;5�_�   =   ?           >   C       ����                                                                                                                                                                                                                                                                                                                                                             ]��     �   B   D   N              float output;5�_�   >   @           ?   C       ����                                                                                                                                                                                                                                                                                                                                                             ]��     �   B   D   N              float output[0];5�_�   ?   A           @   C       ����                                                                                                                                                                                                                                                                                                                                                             ]��    �   B   D   N              float output[2];5�_�   @   B           A   C       ����                                                                                                                                                                                                                                                                                                                                                             ]�\     �   B   D   N              float output[2] = {0};5�_�   A   C           B   C       ����                                                                                                                                                                                                                                                                                                                                                             ]�a     �   B   D   N              float output = {0};5�_�   B   D           C   C       ����                                                                                                                                                                                                                                                                                                                                                             ]�e     �   B   D   N              float output;5�_�   C   E           D   C       ����                                                                                                                                                                                                                                                                                                                                                             ]�q     �   B   D   N      "        std::vector<>float output;5�_�   D   F           E   C        ����                                                                                                                                                                                                                                                                                                                                                             ]�u    �   B   D   N      '        std::vector<float>float output;5�_�   E   G           F   C       ����                                                                                                                                                                                                                                                                                                                                                             ]�     �   B   D   N      "        std::vector<float> output;5�_�   F   H           G   C       ����                                                                                                                                                                                                                                                                                                                                                             ]�     �   B   D   N              float> output;5�_�   G   I           H   C       ����                                                                                                                                                                                                                                                                                                                                                             ]�     �   B   D   N              float output;5�_�   H   J           I   C       ����                                                                                                                                                                                                                                                                                                                                                             ]�     �   B   E   N              float* output;5�_�   I               J   @       ����                                                                                                                                                                                                                                                                                                                                                             ]�    �   ?   B   O              int inputNum;5�_�   )           +   *          ����                                                                                                                                                                                                                                                                                                                                                             \�k>     �      	   I           5�_�                    :       ����                                                                                                                                                                                                                                                                                                                                                             \�ژ     �   9   ;   T                      5��