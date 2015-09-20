Xin chào các bạn! Chào mừng bạn đến với UnoJoyKT!

UnoJoyKT là một dự án nhỏ được sửa một số chỗ dựa trên mã nguồn UnoJoy do bạn AlanChatham công bố. 
UnoJoyKT cho phép bạn dùng Arduino Uno tạo cần điều khiển Joystick giao diện USB. 

Nó là một hệ thống ba phần:

Drivers - Dùng để cài đặt driver cho mạch Arduino khi kết nối với USB
Phần mềm -Thư viện UnoJoyKT cho Arduino
Firmware - Mã để nạp vào chip giao tiếp USB của Arduino 

Để làm việc với UnoJoyKT, bạn cần phải tiến hành làm việc với 3 phần của dự án. 

=== DRIVERS ===
Trong thư mục UnoJoyKT, có những tập tin cài đặt các trình điều khiển
bạn sẽ cần cho bộ nạp khởi động DFU. 

Trên Windows, bạn cũng cần phải tải về và cài đặt công cụ FLIP của Atmel:
http://www.atmel.com/tools/FLIP.aspx


=== SOFTWARE ===

Để bắt đầu, trước tiên, hãy vào thư mục UnoJoyKTdemo. Mở UnoJoyKTdemo.ino và upload mã cho Arduino của bạn.


=== FIRMWARE ===

Bây giờ chúng ta có mã trên Arduino, việc tiếp theo là chúng ta cần
lập trình lại chip giao tiếp trên Arduino. Để làm điều này, đầu tiên bạn cần đặt các Arduino vào chế độ 'Arduino UNO DFU'. 
Các hướng dẫn về chế độ 'Arduino UNO DFU' được mô tả ở link bên dưới:
http://arduino.cc/en/Hacking/DFUProgramming8U2

---- Cách đưa Arduino vào chế độ DFU ----

Đầu tiên cắm kết nối Arduino với máy tính.
Sau đó sử dụng một đoạn dây điện hoặc một vật nhỏ bằng kim loại, kết nối 2 chân ở khối chân cắm gồm 6 chân ở gần cổng USB của mạch Arduino.
Sau đó rút kết nối mạch Arduino ra khỏi máy tính và kết nối lại và bây giờ xuất hiện để hệ thống của bạn là 'Arduino UNO DFU'.

                      ---->
        o o o           |        | o o 
----|   o o o           |----|   | o o
    |                   |    |     
USB |                   |USB |      
    |                   |    |   
----|                   |----|
                        |

---- Khi bạn đang trong chế độ 'Arduino UNO DFU' ----

Khi Arduino đang ở trong chế độ DFU, để cập nhật firmware, chỉ cần nhấp vào:
Windows: TurnIntoAJoystick.bat

Lưu ý: Sau khi bạn cập nhật xong firmware, bạn sẽ cần phải tháo và cắm Arduino lại cho nó để hiển thị với phần mềm mới. 
Khi bạn cắm lại Arduino, nó sẽ hiển thị trên máy tính như là một 'UnoJoyKT Joystick'. Bạn có thể kiểm tra điều này theo bước dưới đây



---- Cách kiểm tra các chế độ làm việc của Arduino ----

Trên Windows 7, 8, 8.1, 10 bạn có thể kiểm tra xem nó ra bằng cách vào
    Start-> Devices and Printers và bạn sẽ thấy nó có tên 'Unspecified'
    Trong chế độ Arduino, nó sẽ xuất hiện như là 'Arduino UNO (COM 23)
    Trong chế độ DFU, nó sẽ xuất hiện như là 'Arduino UNO DFU'
    Trong chế độ UnoJoyKT, nó sẽ xuất hiện ở đầu như 'UnoJoyKT Joystick'
