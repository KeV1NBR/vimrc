Vim�UnDo� ބ�՛�=�VO�ӄ��~)h~B 6�-]                                     _E�    _�                             ����                                                                                                                                                                                                                                                                                                                                                             _E�     �                #include "XegGripper.h"5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _E�     �                5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _E�     �                 5�_�                       
    ����                                                                                                                                                                                                                                                                                                                                                             _E�     �                #include ""5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _E�    �                   #ifndef ACTMODELIMPL_H   #define ACTMODELIMPL_H       #include "ActModel.h"   #include "Hiwin.h"   #include "sucker.h"       class ActModel::ActModelImpl{       public:   &        ActModelImpl(ActParm actParm);            virtual ~ActModelImpl();       =        bool run(const PlanData& planData, ActData& actData);               private:   +        void control_arm(Arm::Acting move);   3        void control_gripper(Gripper::Acting move);                   Hiwin arm;           XegGripper gripper;       $        std::vector<double> homePos;       T        // 如果你在執行專案時需轉換工作點tool, 才要存取初始tool           //int toolNum;   *        //std::array<double, 6> toolCoord;   };           #endif5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _E�    �                   XegGripper gripper;5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _E�    �               #include "sucker.h"5�_�      	                     ����                                                                                                                                                                                                                                                                                                                                                             _E�    �                   Sucker sucker;5�_�      
           	          ����                                                                                                                                                                                                                                                                                                                                                             _E�    �                    Sucker sucker;5�_�   	              
      	    ����                                                                                                                                                                                                                                                                                                                                                     
    _E&    �                   Hiwin arm;5�_�   
                        ����                                                                                                                                                                                                                                                                                                                                                     
    _E-   	 �               #include "Hiwin.h"5�_�                           ����                                                                                                                                                                                                                                                                                                                                                     
    _E7   
 �                   HiwinSDK arm;5�_�                           ����                                                                                                                                                                                                                                                                                                                                                     
    _EB    �                   SUCKER sucker;5�_�                             ����                                                                                                                                                                                                                                                                                                                                                             _E�    �                /    void control_gripper(Gripper::Acting move);5��