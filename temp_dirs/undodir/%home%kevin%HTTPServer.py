Vim�UnDo� �_���z"�(#��)�H�a�}k��ɞ�$aդ      ;            self.path ='http://localhost:25144/mytest.html'      .      #       #   #   #    ]�?�    _�                             ����                                                                                                                                                                                                                                                                                                                                                             ]�7j     �                   5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�7x     �                 9from http.server import BaseHTTPRequestHandler as handler�                  from http.server impport 5�_�                       )    ����                                                                                                                                                                                                                                                                                                                                                             ]�7�     �                )from http.server import HTTPServer as ser5�_�                       9    ����                                                                                                                                                                                                                                                                                                                                                             ]�7�     �                 9from http.server import BaseHTTPRequestHandler as handler5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�7�     �                 class Service()5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�7�     �                 class Service(handler)5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�9K     �                     def 5�_�      	                     ����                                                                                                                                                                                                                                                                                                                                                             ]�9T     �                     def do_GET()5�_�      
           	          ����                                                                                                                                                                                                                                                                                                                                                             ]�9k     �                     def do_GET(self)5�_�   	              
          ����                                                                                                                                                                                                                                                                                                                                                             ]�9m     �               class Service(handler)5�_�   
                        ����                                                                                                                                                                                                                                                                                                                                                             ]�9u     �                     def do_GET(self):5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�9�     �                         if self.path == ''5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�9�     �                             self�                         if self.path == '/'5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�9�     �                       if self.path == '/'5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�9�     �                             self5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�9�     �                             self.path = 5�_�                       ;    ����                                                                                                                                                                                                                                                                                                                                                             ]�9�     �                 <            self.path ='http://localhost:25144/mytest.html' 5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�:     �                         src=5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�:     �                         src =5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�:%     �                         src = open()5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�:-     �                         src = open(self.path[])5�_�                       !    ����                                                                                                                                                                                                                                                                                                                                                             ]�:6     �                 !        src = open(self.path[1:])5�_�                       (    ����                                                                                                                                                                                                                                                                                                                                                             ]�:<     �                 (        src = open(self.path[1:]).read()5�_�                    	       ����                                                                                                                                                                                                                                                                                                                                                             ]�:J     �                         self.send_response()5�_�                    	       ����                                                                                                                                                                                                                                                                                                                                                             ]�:O     �                         self.send_response(200)5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ]�:p     �                         self.wfile.write()5�_�                       #    ����                                                                                                                                                                                                                                                                                                                                                             ]�:z     �                 $        self.wfile.write(bytes(src))5�_�                       -    ����                                                                                                                                                                                                                                                                                                                                                             ]�:�     �                 -        self.wfile.write(bytes(src), 'utf-8')5�_�                       #    ����                                                                                                                                                                                                                                                                                                                                                             ]�:�     �                 .        self.wfile.write(bytes(src), 'utf-8'))5�_�                       -    ����                                                                                                                                                                                                                                                                                                                                                             ]�:�     �                 -        self.wfile.write(bytes(src, 'utf-8'))5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             ]�:�     �                 ser = HTTPServer(('localhost'))5�_�      !                  %    ����                                                                                                                                                                                                                                                                                                                                                             ]�:�     �                 &ser = HTTPServer(('localhost', 25144))5�_�       "           !      /    ����                                                                                                                                                                                                                                                                                                                                                             ]�:�    �                 /ser = HTTPServer(('localhost', 25144), Service)5�_�   !   #           "          ����                                                                                                                                                                                                                                                                                                                                                             ]�<6    �               /ser = HTTPServer(('localhost', 25144), Service)5�_�   "               #      .    ����                                                                                                                                                                                                                                                                                                                                                             ]�?�    �               ;            self.path ='http://localhost:25144/mytest.html'5��