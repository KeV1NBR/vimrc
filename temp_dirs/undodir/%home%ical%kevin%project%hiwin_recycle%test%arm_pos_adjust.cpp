VimЯUnDoх a┼ої;sн∙uп2╓и2╦Ee с│o╞w┬GTь▓╫                     >       >   >   >    ]P21    _╨                                                                                                                                                                                                                                                                                                                                                                                              ]P1
    ї       E           ї              5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1B     ї                    SenseData senseData;5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1C     ї                    PlanData planData;5Б_╨      	                                                                                                                                                                                                                                                                                                                                                                                      ]P1C     ї                    ActData actData;5Б_╨      
           	                                                                                                                                                                                                                                                                                                                                                                            ]P1D     ї                %    SenseModel* senseModel = nullptr;5Б_╨   	              
                                                                                                                                                                                                                                                                                                                                                                           ]P1E     ї                #    PlanModel* planModel = nullptr;5Б_╨   
                                                                                                                                                                                                                                                                                                                                                                                         ]P1E     ї                !    ActModel* actModel = nullptr;5Б_╨                                                                                                                                                                                                                                                                                                                                                                                             ]P1F     ї                 5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1F     ї                '    std::vector<std::string> knownMove;5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1G     ї                    knownMove.clear();5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1G     ї                $    knownMove.push_back("pick_pos");5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1H     ї                !    knownMove.push_back("go_up");5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1H     ї                &    knownMove.push_back("goto_metal");5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1H     ї                &    knownMove.push_back("goto_paper");5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1I     ї                (    knownMove.push_back("goto_plastic");5Б_╨                                                                                                                                                                                                                                                                                                                                                                                             ]P1K     ї                H    senseModel = Parse_SenseModel(nodes["Camera"], senseData, planData);5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1K     ї                2    planModel = Parse_PlanModel(nodes, knownMove);5Б_╨                                                                                                                                                                                                                                                                                                                                                                                           ]P1O     ї                %    actModel = Parse_ActModel(nodes);5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1Y     ї                &    std::cout << "start" << std::endl;5Б_╨                                                                                                                                                                                                                                                                                                                                                                                             ]P1Z     ї                 5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1Z     ї                    bool run = true;5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1[     ї                    while(run){5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1[     ї                #        senseModel->run(senseData);5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1[     ї                5        planModel->run(senseData, planData, actData);5Б_╨                                                                                                                                                                                                                                                                                                                                                                                              ]P1\     ї                 5Б_╨      !                                                                                                                                                                                                                                                                                                                                                                                       ]P1\     ї                '        senseModel->drawImgs(planData);5Б_╨       "           !                                                                                                                                                                                                                                                                                                                                                                           ]P1\     ї                        senseModel->showImgs();5Б_╨   !   #           "                                                                                                                                                                                                                                                                                                                                                                            ]P1]     ї                 5Б_╨   "   $           #                                                                                                                                                                                                                                                                                                                                                                           ]P1]     ї                %        char input = cv::waitKey(10);5Б_╨   #   %           $                                                                                                                                                                                                                                                                                                                                                                           ]P1^     ї                        switch(input){5Б_╨   $   &           %      	                                                                                                                                                                                                                                                                                                                                                                     ]P1^     ї                        	case -1:5Б_╨   %   '           &      
                                                                                                                                                                                                                                                                                                                                                                     ]P1_     ї                        		break;5Б_╨   &   (           '                                                                                                                                                                                                                                                                                                                                                                            ]P1_     ї                 5Б_╨   '   )           (      	                                                                                                                                                                                                                                                                                                                                                                     ]P1_     ї                        	case 27:5Б_╨   (   *           )      
                                                                                                                                                                                                                                                                                                                                                                     ]P1`     ї                        		run = false;5Б_╨   )   +           *      
                                                                                                                                                                                                                                                                                                                                                                     ]P1`     ї                        		break;5Б_╨   *   ,           +                                                                                                                                                                                                                                                                                                                                                                           ]P1`     ї                	        }5Б_╨   +   -           ,                                                                                                                                                                                                                                                                                                                                                                            ]P1a     ї                 5Б_╨   ,   .           -                                                                                                                                                                                                                                                                                                                                                                           ]P1a     ї                +        if(!planModel->isFinish() && run) {5Б_╨   -   /           .      	                                                                                                                                                                                                                                                                                                                                                                     ]P1b     ї                0        	run = actModel->run(planData, actData);5Б_╨   .   0           /                                                                                                                                                                                                                                                                                                                                                                           ]P1b     ї                        } else {5Б_╨   /   1           0      	                                                                                                                                                                                                                                                                                                                                                                     ]P1b     ї                        	run = false;5Б_╨   0   2           1                                                                                                                                                                                                                                                                                                                                                                           ]P1c     ї                	        }5Б_╨   1   3           2                                                                                                                                                                                                                                                                                                                                                                            ]P1d     ї                 5Б_╨   2   4           3                                                                                                                                                                                                                                                                                                                                                                            ]P1j     ї               +    YamlSettings::initSettings(argc, argv);    ї                    ї                    ї                5Б_╨   3   5           4                                                                                                                                                                                                                                                                                                                                                                           ]P1o     ї                    ї                   }5Б_╨   4   6           5                                                                                                                                                                                                                                                                                                                                                                           ]P1Й     ї               }5Б_╨   5   7           6      4                                                                                                                                                                                                                                                                                                                                                                     ]P1╠     ї               4    YAML::Node& nodes = YamlSettings::getSettings();5Б_╨   6   8           7                                                                                                                                                                                                                                                                                                                                                                           ]P1Ё     ї               @      arm.setServoState(1);    this_thread::sleep_for(1s);      5Б_╨   7   9           8      '                                                                                                                                                                                                                                                                                                                                                                     ]P1Ї     ї               '      this_thread::sleep_for(1s);      5Б_╨   8   :           9                                                                                                                                                                                                                                                                                                                                                                           ]P2     ї               |       arm.errorReset();    arm.setOperationMode(1);    arm.moveLinAbsJoi               nt(home);    arm.waitForIdle();     5Б_╨   9   ;           :      #                                                                                                                                                                                                                                                                                                                                                                     ]P2     ї               g       arm.setOperationMode(1);    arm.moveLinAbsJoi               nt(home);    arm.waitForIdle();     5Б_╨   :   <           ;      '                                                                                                                                                                                                                                                                                                                                                                     ]P2     ї               K       arm.moveLinAbsJoi               nt(home);    arm.waitForIdle();     5Б_╨   ;   =           <      %                                                                                                                                                                                                                                                                                                                                                                     ]P2     ї               <       arm.moveLinAbsJoint(home);    arm.waitForIdle();     5Б_╨   <   >           =                                                                                                                                                                                                                                                                                                                                                                 v        ]P2#     ї                       arm.waitForIdle();     ї                %       arm.moveLinAbsJoint(home);    ї                #       arm.setOperationMode(1);    ї                       arm.errorReset();    ї                '      this_thread::sleep_for(1s);      ї                      arm.setServoState(1);    ї                #     Hiwin arm("192.168.0.3", 502);5Б_╨   =               >   
                                                                                                                                                                                                                                                                                                                                                              v        ]P20    ї   	             5Б_╨                                                                                                                                                                                                                                                                                                                                                                                             ]P1U     ї              5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P1L     ї              5Б_╨                                                                                                                                                                                                                                                                                                                                                                                            ]P16     ї              5Б_╨                                                                                                                                                                                                                                                                                                                                                                                             ]P17     ї              5Б_╨                                                                                                                                                                                                                                                                                                                                                                                             ]P18     ї              5Б_╨                                                                                                                                                                                                                                                                                                                                                                                              ]P19     ї              5Бчк