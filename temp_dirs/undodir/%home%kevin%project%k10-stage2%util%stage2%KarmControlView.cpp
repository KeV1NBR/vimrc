Vim�UnDo� �"���x;�YV?DJ��2��~Ed'�|xf��  �                   client->act();  =                          _��    _�                    ?       ����                                                                                                                                                                                                                                                                                                                                                             _�    �  >  @  �                      client->act();5�_�                   >       ����                                                                                                                                                                                                                                                                                                                                                             _�:     �  =  ?  �                      Movement x = 0;5�_�                   >       ����                                                                                                                                                                                                                                                                                                                                                             _�;    �  =  ?  �      !                Movement x = ()0;5�_�                   >       ����                                                                                                                                                                                                                                                                                                                                                             _�t     �  =  >          )                Movement x = (Movement)0;5�_�                   =       ����                                                                                                                                                                                                                                                                                                                                                             _�u     �  <  =                          Arm y("8787");5�_�                   =       ����                                                                                                                                                                                                                                                                                                                                                             _�x    �  <  >  �                      client->act(x);5�_�                   2       ����                                                                                                                                                                                                                                                                                                                                                             _��    �  1  3  �      1        string movement = it->first.as<string>();5�_�      	             2       ����                                                                                                                                                                                                                                                                                                                                                             _��     �  1  3  �      ,        string tmp = it->first.as<string>();5�_�      
           	  2       ����                                                                                                                                                                                                                                                                                                                                                             _��     �  1  3  �      .        string tmp = ()it->first.as<string>();5�_�   	              
  2   ,    ����                                                                                                                                                                                                                                                                                                                                                             _��     �  1  3  �      -        string tmp = (it->first.as<string>();5�_�   
                2       ����                                                                                                                                                                                                                                                                                                                                                             _��    �  1  3  �      .        string tmp = (it->first.as<string>());5�_�                   2       ����                                                                                                                                                                                                                                                                                                                                                             _��     �  1  3  �      2        string tmp = atoi(it->first.as<string>());5�_�                   2       ����                                                                                                                                                                                                                                                                                                                                                             _��    �  1  3  �      /        int tmp = atoi(it->first.as<string>());5�_�                   2       ����                                                                                                                                                                                                                                                                                                                                                             _��   
 �  1  3  �      4        int movement = atoi(it->first.as<string>());5�_�                   2   7    ����                                                                                                                                                                                                                                                                                                                                                             _��    �  1  3  �      9        int movement = std::atoi(it->first.as<string>());5�_�                   =       ����                                                                                                                                                                                                                                                                                                                                                             _��     �  <  >  �                      client->act();5�_�                   =       ����                                                                                                                                                                                                                                                                                                                                                             _��     �  <  >  �                       client->act(());5�_�                   =   &    ����                                                                                                                                                                                                                                                                                                                                                             _��    �  <  >  �      (                client->act((Movement));5�_�                   =   &    ����                                                                                                                                                                                                                                                                                                                                                             _��     �  <  >  �      0                client->act((Movement)movement);5�_�                             ����                                                                                                                                                                                                                                                                                                                                                             _��    �              �   #include "KarmControlView.h"       #include <numeric>   #include <thread>   #include <tuple>       #include <allegro5/allegro.h>       #include <opencv2/imgproc.hpp>       !#include <Poco/StringTokenizer.h>   #include <Poco/Util/Timer.h>    #include <Poco/Util/TimerTask.h>   '#include <Poco/Util/TimerTaskAdapter.h>       #include <yaml-cpp/yaml.h>        #include "TimerTaskAdapterArg.h"       #include "arm.h"       using namespace std;   using namespace cv;   using namespace Poco;   using namespace Poco::Util;   using namespace YAML;       ;KarmControlView::KarmControlView(const std::string& ipport)       : client(),         ipport(ipport),             // 按鈕狀態   6      buttonState(0b10000000000000000000000000000000),         viewUpdate(true),             commTimer(),         updateIndex(0),   .      lastUpdate(chrono::system_clock::now()),             lastColor(),             macros(),       +      log(Logger::get("KarmControlView")) {   3    this->view = cv::Mat::zeros(200, 400, CV_8UC3);       A    // TimerTask::Ptr task(new TimerTaskAdapter<KarmControlView>(   .    //    *this, &KarmControlView::commTask));   '    // commTimer.schedule(task, 0, 30);       -    log.information("KarmControlView start");   }       %KarmControlView::~KarmControlView() {   9    log.information("Stopping Karm communicate worker.");       commTimer.cancel(true);   8    log.information("Karm communicate worker stopped.");   }       $void KarmControlView::updateView() {   ,    // 計算網路通訊延遲 設定燈號   8    std::chrono::duration<double, std::milli> duration =   6        std::chrono::system_clock::now() - lastUpdate;   &    cv::Scalar circleColor(0, 0, 255);   !    if (duration.count() < 100) {   "        circleColor = {0, 255, 0};       (    } else if (duration.count() < 500) {   $        circleColor = {0, 255, 255};       }       )    // 延遲過高在Console跳出警告   !    if (duration.count() > 100) {   C        log.warning("Communication delay %f ms", duration.count());       }       3    if (viewUpdate || (circleColor != lastColor)) {           view = 0;           drawTitle();       =        circle(view, {110, 15}, 5, circleColor, -1, LINE_AA);            lastColor = circleColor;               drawControlKeys();           drawArmSelectKeys();           drawCamRotateKeys();           // drawServoValues();           viewUpdate = false;       }   }       // set sevro in range   7// int constrain(int value, int minimum, int maximum) {   ///    return min(maximum, max(minimum, value));   //}       (// 接受鍵盤事件 更新按鈕狀態   .void KarmControlView::onKeyDown(int keycode) {   .    uint64_t onehot = keycode2Onehot(keycode);       buttonState |= onehot;       // 接受XC 切換左右手   $    // 接受1至9觸發巨集事件   $    // 接受U至;觸發巨集事件       switch (keycode) {           case ALLEGRO_KEY_X:   )            buttonState &= ~(1ULL << 28);               break;           case ALLEGRO_KEY_C:   (            buttonState |= (1ULL << 28);               break;               case ALLEGRO_KEY_1:           case ALLEGRO_KEY_2:           case ALLEGRO_KEY_3:           case ALLEGRO_KEY_4:           case ALLEGRO_KEY_5:           case ALLEGRO_KEY_6:           case ALLEGRO_KEY_7:           case ALLEGRO_KEY_8:           case ALLEGRO_KEY_9:           case ALLEGRO_KEY_0:           case ALLEGRO_KEY_U:           case ALLEGRO_KEY_I:           case ALLEGRO_KEY_O:           case ALLEGRO_KEY_P:           case ALLEGRO_KEY_J:           case ALLEGRO_KEY_K:           case ALLEGRO_KEY_L:   #        case ALLEGRO_KEY_SEMICOLON:   $            onMacroKeyDown(keycode);               break;       }       viewUpdate = true;   }       .// 接受按鍵釋放事件 更新按鈕狀態   ,void KarmControlView::onKeyUp(int keycode) {   .    uint64_t onehot = keycode2Onehot(keycode);       buttonState &= ~onehot;       viewUpdate = true;   }       "// 在視窗畫外框 寫上標題   #void KarmControlView::drawTitle() {   N    rectangle(view, {0, 0, view.cols - 1, view.rows - 1}, {255, 255, 255}, 2);   M    putText(view, "Karm view", {5, 20}, 0, 0.6, {255, 255, 255}, 1, LINE_AA);   }       // 畫手臂控制按鈕   )void KarmControlView::drawControlKeys() {   /    vector<tuple<Point, int, string>> keyTups({   '        {{30, 55}, ALLEGRO_KEY_U, "U"},   '        {{80, 55}, ALLEGRO_KEY_I, "I"},   (        {{130, 55}, ALLEGRO_KEY_O, "O"},   (        {{180, 55}, ALLEGRO_KEY_P, "P"},   2        //{{230, 55}, ALLEGRO_KEY_OPENBRACE, "["},   (        {{30, 120}, ALLEGRO_KEY_J, "J"},   (        {{80, 120}, ALLEGRO_KEY_K, "K"},   )        {{130, 120}, ALLEGRO_KEY_L, "L"},   0        {{180, 120}, ALLEGRO_KEY_SEMICOLON, ";"}   .        //{{230, 120}, ALLEGRO_KEY_QUOTE, "'"}       });           for (auto& tup : keyTups) {           Point p;           int key;           string s;           tie(p, key, s) = tup;   E        drawKey(view, s, p, (buttonState & keycode2Onehot(key)) > 0);       }   }       6// 畫XC 控制切換左右手及上下相機的按鈕   +void KarmControlView::drawArmSelectKeys() {   .    vector<tuple<Point, int, string>> keyTups(   M        {{{60, 170}, ALLEGRO_KEY_X, "X"}, {{110, 170}, ALLEGRO_KEY_C, "C"}});           for (auto& tup : keyTups) {           Point p;           int key;           string s;           tie(p, key, s) = tup;   E        drawKey(view, s, p, (buttonState & keycode2Onehot(key)) > 0);       }   }       (// 畫上下左右 控制相機的按鈕   +void KarmControlView::drawCamRotateKeys() {   .    vector<tuple<Point, int, string>> keyTups(   +        {{{320, 130}, ALLEGRO_KEY_UP, "^"},   -         {{280, 170}, ALLEGRO_KEY_LEFT, "<"},   -         {{320, 170}, ALLEGRO_KEY_DOWN, "v"},   0         {{360, 170}, ALLEGRO_KEY_RIGHT, ">"}});           for (auto& tup : keyTups) {           Point p;           int key;           string s;           tie(p, key, s) = tup;   E        drawKey(view, s, p, (buttonState & keycode2Onehot(key)) > 0);       }   }       +// 當巨集鍵按下後 觸發巨集事件   3void KarmControlView::onMacroKeyDown(int keycode) {       string macroName = "";   :    if (buttonState & keycode2Onehot(ALLEGRO_KEY_LCTRL)) {           macroName += "ctrl";       }   ;    if (buttonState & keycode2Onehot(ALLEGRO_KEY_LSHIFT)) {           macroName += "shift";       }   6    if (buttonState & keycode2Onehot(ALLEGRO_KEY_X)) {           macroName += "L";       }   6    if (buttonState & keycode2Onehot(ALLEGRO_KEY_C)) {           macroName += "R";       }       switch (keycode) {           case ALLEGRO_KEY_1:               macroName += "1";               break;           case ALLEGRO_KEY_2:               macroName += "2";               break;           case ALLEGRO_KEY_3:               macroName += "3";               break;           case ALLEGRO_KEY_4:               macroName += "4";               break;           case ALLEGRO_KEY_5:               macroName += "5";               break;           case ALLEGRO_KEY_6:               macroName += "6";               break;           case ALLEGRO_KEY_7:               macroName += "7";               break;           case ALLEGRO_KEY_8:               macroName += "8";               break;           case ALLEGRO_KEY_9:               macroName += "9";               break;           case ALLEGRO_KEY_0:               macroName += "0";               break;               case ALLEGRO_KEY_U:               macroName += "0";               break;           case ALLEGRO_KEY_I:               macroName += "1";               break;           case ALLEGRO_KEY_O:               macroName += "2";               break;           case ALLEGRO_KEY_P:               macroName += "3";               break;           case ALLEGRO_KEY_J:               macroName += "4";               break;           case ALLEGRO_KEY_K:               macroName += "5";               break;           case ALLEGRO_KEY_L:               macroName += "6";               break;   #        case ALLEGRO_KEY_SEMICOLON:               macroName += "7";               break;       }       5    // 建立一次性的巨集工作 並加入排程   M    TimerTask::Ptr pTask(new TimerTaskAdapterArg(&KarmControlView::macroTask,   P                                                 this, macroName, Timestamp()));   +    commTimer.schedule(pTask, Timestamp());   +    log.debug("Call macro %s ", macroName);   }       '// 設定手臂或相機的起始角度   >// void KarmControlView::setInitial(const YAML::Node& node) {}       !// 巨集事件所觸發的工作   =void KarmControlView::macroTask(Poco::Util::TimerTask& pTask,   =                                const std::string& macroName,   B                                const Poco::Timestamp& sendTime) {   T    // 如果一下子按太多其他巨集鍵 讓巨集事件延遲1秒沒有執行   5    if (sendTime.elapsed() > 1 * Timespan::SECONDS) {   K        log.warning("Oh macroTask delay %z, ignored.", sendTime.elapsed());           return;       }       /    // 如果沒有設定這個巨集 則離開       if (!macros[macroName]) {           return;       }           // 將每個movement取出   +    YAML::Node actions = macros[macroName];   N    for (YAML::Node::const_iterator it = actions.begin(); it != actions.end();            ++it) {   A        int movement = std::atoi(it->first.as<string>().c_str());           // if (!movement) {   ?        //    log.warning("Command %s not found .", macroName);           //    continue;           //}               viewUpdate = true;   -        log.debug("use macros:%d", movement);               if (client) {               try {   1                client->act((Movement) movement);   %                client->setSpeed(20);   9                lastUpdate = chrono::system_clock::now();   A                this_thread::sleep_for(chrono::milliseconds(30));       0            } catch (const std::exception& ex) {   %                log.error(ex.what());               }   	        }       }   }       // 設定巨集   ;void KarmControlView::setMacros(const YAML::Node& macros) {       this->macros = macros;   }       '// 目前選擇左或右手 是第28bit   ,bool KarmControlView::isRightArmSelected() {   ,    return (buttonState & (1ULL << 28)) > 0;   }       Kbool KarmControlView::isLeftArmSelected() { return !isRightArmSelected(); }       *// 手臂控制的按鈕的狀態是0~7bit   1bool KarmControlView::isArmControl(int keycode) {       bool ret = false;   &    int index = keycodeIndex(keycode);   #    if (index >= 0 && index <= 7) {           ret = true;       }       return ret;   }       )// 相機控制按鈕的狀態是10~13bit   *bool KarmControlView::isCam(int keycode) {       bool ret = false;   &    int index = keycodeIndex(keycode);   %    if (index >= 10 && index <= 13) {           ret = true;       }       return ret;   }       0int KarmControlView::keycodeIndex(int keycode) {       int index = -1;       switch (keycode) {   C            // 0~3bit按鈕狀態 代表控制手臂第幾軸正轉           case ALLEGRO_KEY_U:               index = 0;               break;           case ALLEGRO_KEY_I:               index = 1;               break;           case ALLEGRO_KEY_O:               index = 2;               break;           case ALLEGRO_KEY_P:               index = 3;               break;       C            // 4~7bit按鈕狀態 代表控制手臂第幾軸逆轉           case ALLEGRO_KEY_J:               index = 4;               break;           case ALLEGRO_KEY_K:               index = 5;               break;           case ALLEGRO_KEY_L:               index = 6;               break;   #        case ALLEGRO_KEY_SEMICOLON:               index = 7;               break;       F            // 8~9bit按鈕狀態 代表左右手選擇按鈕的狀態           case ALLEGRO_KEY_X:               index = 8;               break;           case ALLEGRO_KEY_C:               index = 9;               break;       B            // 10~13bit按鈕狀態 代表相機控制上下左右           case ALLEGRO_KEY_UP:               index = 10;               break;           case ALLEGRO_KEY_DOWN:               index = 11;               break;           case ALLEGRO_KEY_LEFT:               index = 12;               break;           case ALLEGRO_KEY_RIGHT:               index = 13;               break;       E            // 14~15bit按鈕狀態 代表相機選擇按鈕的狀態           case ALLEGRO_KEY_V:               index = 14;               break;           case ALLEGRO_KEY_B:               index = 15;               break;       9            // 16~27bit按鈕狀態 代表巨集鍵狀態           case ALLEGRO_KEY_LCTRL:               index = 16;               break;            case ALLEGRO_KEY_LSHIFT:               index = 17;               break;           case ALLEGRO_KEY_1:               index = 18;               break;           case ALLEGRO_KEY_2:               index = 19;               break;           case ALLEGRO_KEY_3:               index = 20;               break;           case ALLEGRO_KEY_4:               index = 21;               break;           case ALLEGRO_KEY_5:               index = 22;               break;           case ALLEGRO_KEY_6:               index = 23;               break;           case ALLEGRO_KEY_7:               index = 24;               break;           case ALLEGRO_KEY_8:               index = 25;               break;           case ALLEGRO_KEY_9:               index = 26;               break;           case ALLEGRO_KEY_0:               index = 27;               break;       }       return index;   }       %// 以keycode轉換為onehot encoding   7uint64_t KarmControlView::keycode2Onehot(int keycode) {   &    int index = keycodeIndex(keycode);       if (index >= 0) {           return 1ULL << index;       }       return 0;   }       // 在Mat上繪製按鈕   @void KarmControlView::drawKey(cv::Mat img, const std::string& c,   A                              const cv::Point& p, bool clicked) {        cv::Scalar color(100, 0, 0);       if (clicked) {   *        color = cv::Scalar(240, 240, 240);       }   O    cv::rectangle(img, p - cv::Point(17, 17), p + cv::Point(17, 17), color, 2);   M    cv::putText(img, c, p + cv::Point(-5, 5), 0, 0.7, color, 2, cv::LINE_AA);   }5��