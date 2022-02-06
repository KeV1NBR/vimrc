Vim�UnDo� >�K,7w��}�p����`�_��¤���
����x   #       FSM_GRAB_DEPTH_PRIDICTl            +       +   +   +    _X�.    _�                             ����                                                                                                                                                                                                                                                                                                                                                             _E�     �                #include "object_degree.hpp"5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _E�    �               A   #ifndef FSM_DEF_H   #define FSM_DEF_H       #include "SPAData.h"       enum class MasterState {   	    INIT,       PICK_POS,   	    GRAB,       PUT_PAPER,       PUT_METAL,       PUT_PLASTIC,   
    FINISH   };       enum FSM_PICK_POS {       FSM_PICK_POS_INIT,       FSM_PICK_POS_DO,       FSM_PICK_POS_FINISH   };       enum FSM_GRAB{       FSM_GRAB_INIT,       FSM_GRAB_GET_IMAGE,       FSM_GRAB_GOTO_DEST,       FSM_GRAB_ROTATE,       FSM_GRAB_GO_DOWN,       FSM_GRAB_SUCK,       FSM_GRAB_GO_UP,       FSM_GRAB_GO_TO_PRIDICT,       FSM_GRAB_YOLO,       FSM_GRAB_FINISH   };   enum FSM_METAL {           FSM_METAL_INIT,       FSM_METAL_GOTO_DEST,       FSM_METAL_PUT,       FSM_METAL_FINISH   };       enum FSM_PAPER {           FSM_PAPER_INIT,       FSM_PAPER_GOTO_DEST,       FSM_PAPER_PUT,       FSM_PAPER_FINISH   };        enum FSM_PLASTIC {           FSM_PLASTIC_INIT,       FSM_PLASTIC_GOTO_DEST,       FSM_PLASTIC_PUT,       FSM_PLASTIC_FINISH   };       2Actions findPose(Poses poses, std::string target);       struct bbox_t;   void drawYolo(           PlanData& planData,            std::vector<bbox_t> det,           int camId,   &        std::vector<std::string> names   
        );       #endif5�_�                    	       ����                                                                                                                                                                                                                                                                                                                                                             _M�     �      
   9      	    GRAB,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _M�     �                    PUT_PLASTIC,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _M�     �   
                 PUT_METAL,5�_�      	              
       ����                                                                                                                                                                                                                                                                                                                                                             _M�     �   	      7          PUT_PAPER,5�_�      
          	           ����                                                                                                                                                                                                                                                                                                                                                             _M2    �               7   #ifndef FSM_DEF_H   #define FSM_DEF_H       #include "SPAData.h"       enum class MasterState {   	    INIT,       PICK_POS,       PREPROCESS,       PUT,   
    FINISH   };       Nenum FSM_PICK_POS { FSM_PICK_POS_INIT, FSM_PICK_POS_DO, FSM_PICK_POS_FINISH };       enum FSM_GRAB {       FSM_GRAB_INIT,       FSM_GRAB_GET_IMAGE,       FSM_GRAB_GOTO_DEST,       FSM_GRAB_ROTATE,       FSM_GRAB_GO_DOWN,       FSM_GRAB_SUCK,       FSM_GRAB_GO_UP,       FSM_GRAB_GO_TO_PRIDICT,       FSM_GRAB_YOLO,       FSM_GRAB_FINISH   };   enum FSM_METAL {       FSM_METAL_INIT,       FSM_METAL_GOTO_DEST,       FSM_METAL_PUT,       FSM_METAL_FINISH   };       enum FSM_PAPER {       FSM_PAPER_INIT,       FSM_PAPER_GOTO_DEST,       FSM_PAPER_PUT,       FSM_PAPER_FINISH   };       enum FSM_PLASTIC {       FSM_PLASTIC_INIT,       FSM_PLASTIC_GOTO_DEST,       FSM_PLASTIC_PUT,       FSM_PLASTIC_FINISH   };       2Actions findPose(Poses poses, std::string target);       struct bbox_t;   Evoid drawYolo(PlanData& planData, std::vector<bbox_t> det, int camId,   .              std::vector<std::string> names);       #endif5�_�   	              
      3    ����                                                                                                                                                                                                                                                                                                                                                             _MJ    �         1      Cenum class MasterState { INIT, PICK_POS, PREPROCESS, PUT, FINISH };5�_�   
                        ����                                                                                                                                                                                                                                                                                                                                                             _M^     �                    FSM_GRAB_GET_IMAGE,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _Mi     �                    FSM_GRAB_GO_TO_PRIDICT,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _Mj    �                    FSM_GRAB_YOLO,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _M�     �   
      .          FSM_GRAB_INIT,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _M�     �         /          FSM_GRAB_YOLO5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _M�     �   
      /          FSM_GRAB_INIT,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _M�    �                    FSM_GRAB_ROTATE,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _M�     �         /      enum FSM_METAL {5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _M�    �         /      enum FSM_PAPER {       FSM_PAPER_INIT,       FSM_PAPER_GOTO_DEST,       FSM_PAPER_PUT,       FSM_PAPER_FINISH   };       enum FSM_PLASTIC {       FSM_PLASTIC_INIT,       FSM_PLASTIC_GOTO_DEST,       FSM_PLASTIC_PUT,       FSM_PLASTIC_FINISH   };       2Actions findPose(Poses poses, std::string target);5�_�                          ����                                                                                                                                                                                                                                                                                                                                                       _Mb     �         !          FSM_METAL_INIT,       FSM_METAL_GOTO_DEST,       FSM_METAL_PUT,       FSM_METAL_FINISH5�_�                            ����                                                                                                                                                                                                                                                                                                                                                       _Mh     �         !          FSM__GOTO_DEST,       FSM__PUT,       FSM__FINISH�         !          FSM__INIT,5�_�      !                       ����                                                                                                                                                                                                                                                                                                                                                       _Mj    �               !   #ifndef FSM_DEF_H   #define FSM_DEF_H       #include "SPAData.h"       =enum class MasterState { INIT, PICK_POS, GRAB, PUT, FINISH };       Nenum FSM_PICK_POS { FSM_PICK_POS_INIT, FSM_PICK_POS_DO, FSM_PICK_POS_FINISH };       enum FSM_GRAB {       FSM_GRAB_INIT,       FSM_GRAB_PRE,       FSM_GRAB_YOLO,       FSM_GRAB_GOTO_DEST,       FSM_GRAB_GO_DOWN,       FSM_GRAB_SUCK,       FSM_GRAB_GO_UP,       FSM_GRAB_FINISH   };   enum FSM_PUT {       FSM_PUT_INIT,       FSM_PUT_GOTO_DEST,       FSM_PUT_PUT,       FSM_PUT_FINISH   };       2Actions findPose(Poses poses, std::string target);       struct bbox_t;   Evoid drawYolo(PlanData& planData, std::vector<bbox_t> det, int camId,   .              std::vector<std::string> names);       #endif5�_�       #           !           ����                                                                                                                                                                                                                                                                                                                                                             _O��    �                    FSM_GRAB_PRE,5�_�   !   $   "       #      -    ����                                                                                                                                                                                                                                                                                                                                                             _WQ�     �               =enum class MasterState { INIT, PICK_POS, GRAB, PUT, FINISH };5�_�   #   %           $          ����                                                                                                                                                                                                                                                                                                                                                             _WQ�     �               };5�_�   $   &           %          ����                                                                                                                                                                                                                                                                                                                                                             _WQ�     �               enum FSM_CLASSIFIED{}5�_�   %   '           &          ����                                                                                                                                                                                                                                                                                                                                                             _WQ�     �               enum FSM_CLASSIFY{}5�_�   &   (           '      ,    ����                                                                                                                                                                                                                                                                                                                                                             _WQ�     �               .enum FSM_CLASSIFY{ FSM_CLASSIFY_INIT, FSM_CL }5�_�   '   )           (      d    ����                                                                                                                                                                                                                                                                                                                                                             _WR     �               denum FSM_CLASSIFY{ FSM_CLASSIFY_INIT, FSM_CLASSIFY_POS, FSM_CLASSIFY_CLASSIFY, FSM_CLASSIFY_FINISH }5�_�   (   *           )           ����                                                                                                                                                                                                                                                                                                                                                             _WR!    �                  #ifndef FSM_DEF_H   #define FSM_DEF_H       #include "SPAData.h"       Genum class MasterState { INIT, PICK_POS, GRAB, CLASSIFY, PUT, FINISH };       Nenum FSM_PICK_POS { FSM_PICK_POS_INIT, FSM_PICK_POS_DO, FSM_PICK_POS_FINISH };       enum FSM_GRAB {       FSM_GRAB_INIT,       FSM_GRAB_YOLO,       FSM_GRAB_GOTO_DEST,       FSM_GRAB_GO_DOWN,       FSM_GRAB_SUCK,       FSM_GRAB_GO_UP,       FSM_GRAB_FINISH   };       eenum FSM_CLASSIFY{ FSM_CLASSIFY_INIT, FSM_CLASSIFY_POS, FSM_CLASSIFY_CLASSIFY, FSM_CLASSIFY_FINISH };   Nenum FSM_PUT { FSM_PUT_INIT, FSM_PUT_GOTO_DEST, FSM_PUT_PUT, FSM_PUT_FINISH };       2Actions findPose(Poses poses, std::string target);       struct bbox_t;   Evoid drawYolo(PlanData& planData, std::vector<bbox_t> det, int camId,   .              std::vector<std::string> names);       #endif5�_�   )   +           *          ����                                                                                                                                                                                                                                                                                                                                                             _X�     �         "          FSM_GRAB_YOLO,5�_�   *               +          ����                                                                                                                                                                                                                                                                                                                                                             _X�-    �         #          FSM_GRAB_DEPTH_PRIDICTl5�_�   !           #   "          ����                                                                                                                                                                                                                                                                                                                                                             _O�f    �              5�_�                          ����                                                                                                                                                                                                                                                                                                                                                       _M]     �         !          FSM_�                   FSM_5�_�                          ����                                                                                                                                                                                                                                                                                                                                                             _M2     �         !          FSM_INIT,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _M6     �         !          FSM_GOTO_DEST,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _M:     �         !          FSM_PUT,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _M?     �         !          FSM_PUT_FINISH5�_�                             ����                                                                                                                                                                                                                                                                                                                                                             _MC    �       "          #ifndef FSM_DEF_H   #define FSM_DEF_H       #include "SPAData.h"       =enum class MasterState { INIT, PICK_POS, GRAB, PUT, FINISH };       Nenum FSM_PICK_POS { FSM_PICK_POS_INIT, FSM_PICK_POS_DO, FSM_PICK_POS_FINISH };       enum FSM_GRAB {       FSM_GRAB_INIT,       FSM_GRAB_PRE,       FSM_GRAB_YOLO,       FSM_GRAB_GOTO_DEST,       FSM_GRAB_GO_DOWN,       FSM_GRAB_SUCK,       FSM_GRAB_GO_UP,       FSM_GRAB_FINISH   };   Benum FSM_PUT { FSM_INIT, FSM_GOTO_DEST, FSM_PUT, FSM_PUT_FINISH };       2Actions findPose(Poses poses, std::string target);       struct bbox_t;   Evoid drawYolo(PlanData& planData, std::vector<bbox_t> det, int camId,   .              std::vector<std::string> names);       #endif5�_�                          ����                                                                                                                                                                                                                                                                                                                                                             _M�     �         /       �         0      M:w    5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _M�     �         1      ddenum FSM_PAPER {5�_�                            ����                                                                                                                                                                                                                                                                                                                                                  v        _M�     �      ,   1      2Actions findPose(Poses poses, std::string target);5�_�                             ����                                                                                                                                                                                                                                                                                                                                                  v        _M�   	 �       $       #   #ifndef FSM_DEF_H   #define FSM_DEF_H       #include "SPAData.h"       =enum class MasterState { INIT, PICK_POS, GRAB, PUT, FINISH };       Nenum FSM_PICK_POS { FSM_PICK_POS_INIT, FSM_PICK_POS_DO, FSM_PICK_POS_FINISH };       enum FSM_GRAB {       FSM_GRAB_INIT,       FSM_GRAB_PRE,       FSM_GRAB_YOLO,       FSM_GRAB_GOTO_DEST,       FSM_GRAB_GO_DOWN,       FSM_GRAB_SUCK,       FSM_GRAB_GO_UP,       FSM_GRAB_FINISH   };   M : w           enum FSM_PUT {           FSM_METAL_INIT,           FSM_METAL_GOTO_DEST,           FSM_METAL_PUT,           FSM_METAL_FINISH       };       2Actions findPose(Poses poses, std::string target);       struct bbox_t;   Evoid drawYolo(PlanData& planData, std::vector<bbox_t> det, int camId,   .              std::vector<std::string> names);       #endif5�_�             	      	       ����                                                                                                                                                                                                                                                                                                                                                             _M     �      
   7      	    GRAB,5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _M
     �      	   7          u,5��