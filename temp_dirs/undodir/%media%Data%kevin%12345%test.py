Vim�UnDo� -?��i+�!��	k��6�M�|��p8��   &                                   a���    _�                        '    ����                                                                                                                                                                                                                                                                                                                                                             a�"    �         %      )G = torch.load('Generator_epoch_200.pth')5�_�                             ����                                                                                                                                                                                                                                                                                                                                                             a���     �      $   %       �       !   %    5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             a���     �                'noise = (torch.rand(16, 128)-0.5) / 0.55�_�                            ����                                                                                                                                                                                                                                                                                                                                                             a���    �                noise = noise.to(device)5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             a���     �          &               noise = noise.to(device)5�_�                    !       ����                                                                                                                                                                                                                                                                                                                                                             a���     �       "   &      5        noise = torch.reshape(noise, (64, 1, 28, 28))5�_�                             ����                                                                                                                                                                                                                                                                                                                                                             a���     �          &      noise = noise.to(device)    �      !   &       5�_�                     !        ����                                                                                                                                                                                                                                                                                                                                                             a���    �       #   %      fake_image = G(noise)5��