Vim�UnDo� �вxNrx9��DHm��+��8�
��KS   q              	                    _g=8    _�       
          	          ����                                                                                                                                                                                                                                                                                                                                                             _g;y     �         o          // initialize output images5�_�   	              
          ����                                                                                                                                                                                                                                                                                                                                                             _g;�     �         p      $    this->classifyCam = new Camera()5�_�   
                    %    ����                                                                                                                                                                                                                                                                                                                                                             _g;�     �         p      %    this->classifyCam = new Ciamera()5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _g;�   
 �         p      $    this->classifyCam = new Ciamera;5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _g<�     �         p       5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _g<�     �         r       5�_�                       
    ����                                                                                                                                                                                                                                                                                                                                                             _g<�     �         r      #include ""5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _g<�    �               r   #include "SenseModel.h"   #include "SenseModelImpl.h"   #include "Camera.h"           #include <chrono>   #include <exception>   #include <iostream>   #include <stdexcept>       using namespace cv;   using namespace std;       GSenseModel::SenseModelImpl::SenseModelImpl(const SenseParm senseParm) {   *    cout << "Sense Model init..." << endl;           // initialize Camera       realsense::Config config;       camera.connect(config);   7    if (camera.depth_supports(RS2_OPTION_MIN_DISTANCE))   >        camera.set_depth_option(RS2_OPTION_MIN_DISTANCE, 200);   .    camera.set_align_stream(RS2_STREAM_COLOR);   <    camera.set_colorizer_option(RS2_OPTION_COLOR_SCHEME, 3);   ,    camera.enable_hole_filling_filter(true);   D    camera.set_hole_filling_filter_option(RS2_OPTION_HOLES_FILL, 1);           // initialize output images   #    this->classifyCam = new Camera;       -    cout << "Sense Model init done." << endl;   }   .SenseModel::SenseModelImpl::SenseModelImpl() {   *    cout << "Sense Model init..." << endl;           // initialize Camera       realsense::Config config;       camera.connect(config);   7    if (camera.depth_supports(RS2_OPTION_MIN_DISTANCE))   >        camera.set_depth_option(RS2_OPTION_MIN_DISTANCE, 200);   .    camera.set_align_stream(RS2_STREAM_COLOR);   <    camera.set_colorizer_option(RS2_OPTION_COLOR_SCHEME, 3);   ,    camera.enable_hole_filling_filter(true);   D    camera.set_hole_filling_filter_option(RS2_OPTION_HOLES_FILL, 1);           // initialize output images       -    cout << "Sense Model init done." << endl;   }   LSenseModel::SenseModelImpl::~SenseModelImpl() { this->camera.disconnect(); }       <void SenseModel::SenseModelImpl::run(SenseData& senseData) {       camera.update();   +    this->camera.retrieve_color_image(rgb);   -    this->camera.retrieve_depth_image(depth);   2    this->camera.retrieve_xyz_measure(pointCloud);       &    senseData.rgb = this->rgb.clone();   *    senseData.depth = this->depth.clone();   4    senseData.pointCloud = this->pointCloud.clone();   }       ?void SenseModel::SenseModelImpl::drawImgs(PlanData& planData) {   A    for (size_t i = 0; i < planData.draw.drawables.size(); i++) {   8        Drawable& drawable = planData.draw.drawables[i];   $        Mat img = this->rgb.clone();       0        // draw object in box and write its name   <        for (size_t j = 0; j < drawable.bboxs.size(); j++) {   *            Rect rect = drawable.bboxs[j];   2            Scalar color = drawable.bboxColors[j];   .            string msg = drawable.bboxMsgs[j];   6            Point position = rect.tl() + Point(0, -2);                   // draw box   !            // rect thickness = 2   +            rectangle(img, rect, color, 2);                   // draw text   +            // text size = 1, thickness = 2   8            putText(img, msg, position, 0, 1, color, 2);   	        }   $        this->rgbShow = img.clone();       }   }       -void SenseModel::SenseModelImpl::showImgs() {       string name = "drawImg";       namedWindow(name);       imshow(name, rgb);           // fix window position       // int x = i*700+200;       // int y = 100;       // moveWindow(name, x, y);   }       Gvector<Mat> SenseModel::SenseModelImpl::getImgs() { return this->rgb; }       1SenseModel::SenseModel(const SenseParm senseParm)   F    : impl(std::make_shared<SenseModel::SenseModelImpl>(senseParm)) {}   SenseModel::SenseModel()   =    : impl(std::make_shared<SenseModel::SenseModelImpl>()) {}       SenseModel::~SenseModel() {}       Jvoid SenseModel::run(SenseData& senseData) { this->impl->run(senseData); }       /void SenseModel::drawImgs(PlanData& planData) {   #    this->impl->drawImgs(planData);   }       7void SenseModel::showImgs() { this->impl->showImgs(); }       Cvector<Mat> SenseModel::getImgs() { return this->impl->getImgs(); }5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             _g<�    �                #    this->classifyCam = new Camera;5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _g<�     �                    // initialize output images5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _g<�     �         o       5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             _g<�     �         p       5�_�                             ����                                                                                                                                                                                                                                                                                                                                                             _g=7    �               p   #include "SenseModel.h"   #include "Camera.h"   #include "SenseModelImpl.h"       #include <chrono>   #include <exception>   #include <iostream>   #include <stdexcept>       using namespace cv;   using namespace std;       GSenseModel::SenseModelImpl::SenseModelImpl(const SenseParm senseParm) {   *    cout << "Sense Model init..." << endl;           // initialize Camera       realsense::Config config;       camera.connect(config);   7    if (camera.depth_supports(RS2_OPTION_MIN_DISTANCE))   >        camera.set_depth_option(RS2_OPTION_MIN_DISTANCE, 200);   .    camera.set_align_stream(RS2_STREAM_COLOR);   <    camera.set_colorizer_option(RS2_OPTION_COLOR_SCHEME, 3);   ,    camera.enable_hole_filling_filter(true);   D    camera.set_hole_filling_filter_option(RS2_OPTION_HOLES_FILL, 1);           this->classifyCam.open       -    cout << "Sense Model init done." << endl;   }   .SenseModel::SenseModelImpl::SenseModelImpl() {   *    cout << "Sense Model init..." << endl;           // initialize Camera       realsense::Config config;       camera.connect(config);   7    if (camera.depth_supports(RS2_OPTION_MIN_DISTANCE))   >        camera.set_depth_option(RS2_OPTION_MIN_DISTANCE, 200);   .    camera.set_align_stream(RS2_STREAM_COLOR);   <    camera.set_colorizer_option(RS2_OPTION_COLOR_SCHEME, 3);   ,    camera.enable_hole_filling_filter(true);   D    camera.set_hole_filling_filter_option(RS2_OPTION_HOLES_FILL, 1);           // initialize output images       -    cout << "Sense Model init done." << endl;   }   LSenseModel::SenseModelImpl::~SenseModelImpl() { this->camera.disconnect(); }       <void SenseModel::SenseModelImpl::run(SenseData& senseData) {       camera.update();   +    this->camera.retrieve_color_image(rgb);   -    this->camera.retrieve_depth_image(depth);   2    this->camera.retrieve_xyz_measure(pointCloud);       &    senseData.rgb = this->rgb.clone();   *    senseData.depth = this->depth.clone();   4    senseData.pointCloud = this->pointCloud.clone();   }       ?void SenseModel::SenseModelImpl::drawImgs(PlanData& planData) {   A    for (size_t i = 0; i < planData.draw.drawables.size(); i++) {   8        Drawable& drawable = planData.draw.drawables[i];   $        Mat img = this->rgb.clone();       0        // draw object in box and write its name   <        for (size_t j = 0; j < drawable.bboxs.size(); j++) {   *            Rect rect = drawable.bboxs[j];   2            Scalar color = drawable.bboxColors[j];   .            string msg = drawable.bboxMsgs[j];   6            Point position = rect.tl() + Point(0, -2);                   // draw box   !            // rect thickness = 2   +            rectangle(img, rect, color, 2);                   // draw text   +            // text size = 1, thickness = 2   8            putText(img, msg, position, 0, 1, color, 2);   	        }   $        this->rgbShow = img.clone();       }   }       -void SenseModel::SenseModelImpl::showImgs() {       string name = "drawImg";       namedWindow(name);       imshow(name, rgb);           // fix window position       // int x = i*700+200;       // int y = 100;       // moveWindow(name, x, y);   }       Gvector<Mat> SenseModel::SenseModelImpl::getImgs() { return this->rgb; }       1SenseModel::SenseModel(const SenseParm senseParm)   F    : impl(std::make_shared<SenseModel::SenseModelImpl>(senseParm)) {}   SenseModel::SenseModel()   =    : impl(std::make_shared<SenseModel::SenseModelImpl>()) {}       SenseModel::~SenseModel() {}       Jvoid SenseModel::run(SenseData& senseData) { this->impl->run(senseData); }       /void SenseModel::drawImgs(PlanData& planData) {   #    this->impl->drawImgs(planData);   }       7void SenseModel::showImgs() { this->impl->showImgs(); }       Cvector<Mat> SenseModel::getImgs() { return this->impl->getImgs(); }5�_�              	      7       ����                                                                                                                                                                                                                                                                                                                                                             _[7V    �   6   8   o      -    senseData.depthImg = this->depth.clone();5�_�                    3   +    ����                                                                                                                                                                                                                                                                                                                                                             _[7d    �   2   4   o      0    this->camera.retrieve_depth_image(depthImg);5�_�                    7   $    ����                                                                                                                                                                                                                                                                                                                                                             _[7k    �   6   8   o      0    senseData.depthImg = this->depthImg.clone();5�_�                    4   &    ����                                                                                                                                                                                                                                                                                                                                                             _[7r     �   4   5   o    �   4   5   o      2    this->camera.retrieve_xyz_measure(pointCloud);5�_�                    5   %    ����                                                                                                                                                                                                                                                                                                                                                             _[7v     �   4   6   p      '    this->camera.retrieve_(pointCloud);5�_�                    5   &    ����                                                                                                                                                                                                                                                                                                                                                             _[7y     �   4   6   p      $    this->camera.retrieve_x_measure;5�_�                    5       ����                                                                                                                                                                                                                                                                                                                                                             _[7�    �   4   6        5�_�                     7       ����                                                                                                                                                                                                                                                                                                                                                             _[7�    �   6   8   o      -    senseData.depth = this->depthImg.clone();5��