Vim�UnDo� N:�e+�U��vz^#NZ��.Q�%Zr$|�a                                    ]�K'    _�                             ����                                                                                                                                                                                                                                                                                                                                                             ]�I[     �                   5�_�                    	        ����                                                                                                                                                                                                                                                                                                                                                  v        ]�Ic     �                )                                        )�                ^                                    REQUIRED_VARS SERIALPORT_INCLUDE_DIRS SERIALPORT_LIBRARIES�                :                                FOUND_VAR Serialport_FOUND�                D                        find_package_handle_standard_args(Serialport�                >                        include(FindPackageHandleStandardArgs)�                                            )�                (                        "/usr/local/lib"�                                    "/usr/lib"�                =            find_library(SERIALPORT_LIBRARIES libserialport.a�   
                             )�   	                          "/usr/local/include"�      
                  "/usr/include"5�_�                           ����                                                                                                                                                                                                                                                                                                                                                 v       ]�I�     �   
                )5�_�                           ����                                                                                                                                                                                                                                                                                                                                                 v       ]�I�     �   
                5�_�                           ����                                                                                                                                                                                                                                                                                                                                                 v       ]�I�     �   
                ""5�_�                       /    ����                                                                                                                                                                                                                                                                                                                                                 v       ]�I�     �      	         1find_path(SERIALPORT_INCLUDE_DIRS libserialport.h5�_�      
                 3    ����                                                                                                                                                                                                                                                                                                                                                 v       ]�I�     �      	         3find_path(SERIALPORT_INCLUDE_DIRS dynamixel_sdk.h.h5�_�                
      1    ����                                                                                                                                                                                                                                                                                                                                                 v       ]�J�     �               1find_library(SERIALPORT_LIBRARIES libserialport.a5�_�   
                    "    ����                                                                                                                                                                                                                                                                                                                               "          "       v   #    ]�J�     �               "find_library(SERIALPORT_LIBRARIES 5�_�                           ����                                                                                                                                                                                                                                                                                                                               "          "       v   #    ]�J�     �               J#   Serialport_FOUND    - True if the system has the libserialport library5�_�                           ����                                                                                                                                                                                                                                                                                                                               "          "       v   #    ]�J�     �               :#   SERIALPORT_INCLUDE_DIRS     - location of header files5�_�                           ����                                                                                                                                                                                                                                                                                                                               "          "       v   #    ]�J�     �               ;#   SERIALPORT_LIBRARIES        - location of library files5�_�                           ����                                                                                                                                                                                                                                                                                                                               "          "       v   #    ]�J�     �      	         1find_path(SERIALPORT_INCLUDE_DIRS dynamixel_sdk.h5�_�                           ����                                                                                                                                                                                                                                                                                                                               "          "       v   #    ]�J�     �      	         0find_path(DYXAMIXEL_INCLUDE_DIRS dynamixel_sdk.h5�_�                           ����                                                                                                                                                                                                                                                                                                                               "          "       v   #    ]�J�     �               3find_library(SERIALPORT_LIBRARIES libdxl_x64_cpp.so5�_�                       ,    ����                                                                                                                                                                                                                                                                                                                               "          "       v   #    ]�J�     �               ,find_package_handle_standard_args(Serialport5�_�                           ����                                                                                                                                                                                                                                                                                                                               "          "       v   #    ]�J�     �                   FOUND_VAR Serialport_FOUND5�_�                           ����                                                                                                                                                                                                                                                                                                                               "          "       v   #    ]�K     �               >    REQUIRED_VARS SERIALPORT_INCLUDE_DIRS SERIALPORT_LIBRARIES5�_�                       3    ����                                                                                                                                                                                                                                                                                                                               "          "       v   #    ]�K
    �               =    REQUIRED_VARS DYNAMIXEL_INCLUDE_DIRS SERIALPORT_LIBRARIES5�_�                            ����                                                                                                                                                                                                                                                                                                                               "          "       v   #    ]�K'     �   
                "/usr/local/inc       ude/dynamixel_sdk"5�_�      	       
         1    ����                                                                                                                                                                                                                                                                                                                               "          "       v   &    ]�I�     �               "find_library(SERIALPORT_LIBRARIES 5�_�                  	      "    ����                                                                                                                                                                                                                                                                                                                               "          "       v   &    ]�J�     �               "find_library(SERIALPORT_LIBRARIES 5��