Vim�UnDo� �=���<y�k�yX���u��E�T��n�4I   0                 0       0   0   0    \�3m    _�                             ����                                                                                                                                                                                                                                                                                                                                                             \�j�     �                #include "object_degree.hpp"5�_�                    =       ����                                                                                                                                                                                                                                                                                                                                                             \�j�     �   <   >   B      $        std::vector<bbox_t_deg> det,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             \�j�     �         B      #include "SPAData.h"5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             \�j�     �         C    �         C    5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             \�j�    �         D          #include <yolo_v2_class.hpp>�         D      #include <yolo_v2_class.hpp>5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             \��8     �                    PUT_PLASTIC,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             \��9     �                    PUT_METAL,5�_�      	                     ����                                                                                                                                                                                                                                                                                                                                                             \��:     �   
                 PUT_PAPER,5�_�      
           	   
       ����                                                                                                                                                                                                                                                                                                                                                             \��;     �   	   
              TRACING,5�_�   	              
   	       ����                                                                                                                                                                                                                                                                                                                                                             \��K     �      
   ?          PICK_POS,5�_�   
                 	       ����                                                                                                                                                                                                                                                                                                                                                             \��S     �   
      A          TRACING�         ?          WAITING_POS,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             \�ձ     �         A      enum FSM_PICK_POS {5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             \�ջ     �         A          FSM_PICK_POS_INIT,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             \��k     �         A          FSM_PICK_POS_DO,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             \�ׁ     �         A          FSM_PICK_POS_FINISH5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             \�א     �         A      enum FSM_TRACING {5�_�                           ����                                                                                                                                                                                                                                                                                                                                                       \��     �                    FSM_TRACING_INIT,5�_�                            ����                                                                                                                                                                                                                                                                                                                                                       \��     �                    FSM_TRACING_YOLO_DEG,5�_�                            ����                                                                                                                                                                                                                                                                                                                                                       \��     �                    FSM_TRACING_CHOOSING,5�_�                            ����                                                                                                                                                                                                                                                                                                                                                       \��     �                    FSM_TRACING_PID,5�_�                            ����                                                                                                                                                                                                                                                                                                                                                       \��     �                    FSM_TRACING_MOVE,5�_�                            ����                                                                                                                                                                                                                                                                                                                                                       \��     �                    FSM_TRACING_MOVE_DEG,5�_�                            ����                                                                                                                                                                                                                                                                                                                                                       \��     �                    FSM_TRACING_GO_DOWN,5�_�                            ����                                                                                                                                                                                                                                                                                                                                                       \��     �                    FSM_TRACING_PICK,5�_�                            ����                                                                                                                                                                                                                                                                                                                                                       \��     �                    FSM_TRACING_GO_UP,5�_�                            ����                                                                                                                                                                                                                                                                                                                                                       \��     �                     FSM_TRACING_FINISH5�_�                           ����                                                                                                                                                                                                                                                                                                                                                       \��     �   
      A          TRACING5�_�                           ����                                                                                                                                                                                                                                                                                                                                                       \��#     �                    FSM_PREDICT_GO_UP,5�_�                           ����                                                                                                                                                                                                                                                                                                                                                       \��$     �                    FSM_PREDICT_PICK,5�_�                            ����                                                                                                                                                                                                                                                                                                                                                       \��%     �                    FSM_PREDICT_GO_DOWN,5�_�      !                      ����                                                                                                                                                                                                                                                                                                                                                       \��&     �                    FSM_PREDICT_MOVE_DEG,5�_�       #           !          ����                                                                                                                                                                                                                                                                                                                                                       \��&     �                    FSM_PREDICT_MOVE,5�_�   !   $   "       #          ����                                                                                                                                                                                                                                                                                                                                                       \��)     �                    FSM_PREDICT_PID,5�_�   #   %           $          ����                                                                                                                                                                                                                                                                                                                                                       \��*     �                    FSM_PREDICT_CHOOSING,5�_�   $   &           %          ����                                                                                                                                                                                                                                                                                                                                                       \��,     �                    FSM_PREDICT_YOLO_DEG,5�_�   %   '           &          ����                                                                                                                                                                                                                                                                                                                                                       \��2     �         9          FSM_PREDICT_INIT,5�_�   &   (           '          ����                                                                                                                                                                                                                                                                                                                                                       \��d     �         :          FSM_PREDICT_INIT,5�_�   '   )           (          ����                                                                                                                                                                                                                                                                                                                                                       \���     �         ;      };5�_�   (   *           )          ����                                                                                                                                                                                                                                                                                                                                                       \���     �         <      enum FSM_METAL {    5�_�   )   +           *          ����                                                                                                                                                                                                                                                                                                                                                       \��     �         <          FSM_METAL_INIT,5�_�   *   ,           +          ����                                                                                                                                                                                                                                                                                                                                                       \��     �          <          FSM_METAL_GOTO_DEST,5�_�   +   .           ,           ����                                                                                                                                                                                                                                                                                                                                                       \���     �      !   <          FSM_METAL_PUT,5�_�   ,   /   -       .   $        ����                                                                                                                                                                                                                                                                                                                            $           0          v       \��
    �   #   %   <      enum FSM_PAPER {           FSM_PAPER_INIT,       FSM_PAPER_GOTO_DEST,       FSM_PAPER_PUT,       FSM_PAPER_FINISH   };        enum FSM_PLASTIC {           FSM_PLASTIC_INIT,       FSM_PLASTIC_GOTO_DEST,       FSM_PLASTIC_PUT,       FSM_PLASTIC_FINISH   };    5�_�   .   0           /   !       ����                                                                                                                                                                                                                                                                                                                            $           $          v       \�ߜ    �       "   /          FSM_METAL_FINISH5�_�   /               0          ����                                                                                                                                                                                                                                                                                                                                                             \�3l    �         /          FSM_WAITING_POS_DO,5�_�   ,           .   -   $        ����                                                                                                                                                                                                                                                                                                                            $           $           V        \���     �   #   0        5�_�   !           #   "          ����                                                                                                                                                                                                                                                                                                                                                       \��'     �              5�_�                           ����                                                                                                                                                                                                                                                                                                                                                        \�װ     �          A   
       FSM__INIT,       FSM__YOLO_DEG,       FSM__CHOOSING,       FSM__PID,       FSM__MOVE,       FSM__MOVE_DEG,       FSM__GO_DOWN,       FSM__PICK,       FSM__GO_UP,       FSM__FINISH5��