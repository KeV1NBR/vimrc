Vim�UnDo� �i����\q�X�`e�Xk��¬A�f�� �<      =void editCfgFile(std::string cfg, string index, double value)      6                       ]��`   
 _�                        >    ����                                                                                                                                                                                                                                                                                                                                                             ]��    �      	   !      >void editCfgFile(std::string cfg, string index, double value);5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]��    �         !          while(getline(cfg, line))5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]��     �         !          cfg.close();5�_�                       $    ����                                                                                                                                                                                                                                                                                                                                                             ]��    �         !      &    ofstream out("./yolov3-tiny.cfg");5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]��     �         !              if(tmp == "width")5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]��    �         !                   line = "width=1024";5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]���     �         #    �         !              if(tmp == index)5�_�      	                     ����                                                                                                                                                                                                                                                                                                                                                             ]���     �                            line.clear();5�_�      
           	           ����                                                                                                                                                                                                                                                                                                                                                             ]���     �         #    �         #    5�_�   	              
           ����                                                                                                                                                                                                                                                                                                                                                             ]���     �         $      	        {    �         $       5�_�   
                         ����                                                                                                                                                                                                                                                                                                                                                             ]���     �         #      	        }    �         #       5�_�                       	    ����                                                                                                                                                                                                                                                                                                                                                             ]���     �         "      	        }5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]���     �         #                  line.clear();5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]���     �         $                  line<< index<<""5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]���    �         $                  line<< index<<"="5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]��     �         $      +            line<< index<<"="<<value<<endl;5�_�                       +    ����                                                                                                                                                                                                                                                                                                                                                             ]��     �         $      ,            line<< index <<"="<<value<<endl;5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]��     �                            line.clear();5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]��%     �         #                  line = ;5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]��*     �         #                  line = index + "";5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]��+     �         #                  line = index + "=";5�_�                       !    ����                                                                                                                                                                                                                                                                                                                                                             ]��=     �         #      '            line = index + "=" + value;5�_�                       ,    ����                                                                                                                                                                                                                                                                                                                                                             ]��B     �         #      2            line = index + "=" + to_string()value;5�_�                       0    ����                                                                                                                                                                                                                                                                                                                                                             ]��D    �         #      1            line = index + "=" + to_string(value;5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]��U     �                	        {5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]��V    �                	        }5�_�                             ����                                                                                                                                                                                                                                                                                                                                                             ]��\   	 �                    out.close();    �          !           �      !   !       5�_�                        6    ����                                                                                                                                                                                                                                                                                                                                                             ]��_   
 �      	         =void editCfgFile(std::string cfg, string index, double value)5��