Họ và tên:  Võ Hồng Phúc
Mã sinh viên: 21020377
Lớp: INT2215 1
Game FlappyBird

Mô tả trò chơi:
- Trò chơi nổi tiếng do một dev Việt Nam làm ra
- Người chơi sẽ điều khiển chú chim vượt qua những khoảng trống giữa những hàng ống, tuy rất đơn giản nhưng đã làm điên đảo cộng đồng thời bấy giờ.

Các chức năng của trò chơi:
- Các chức năng của game là: bắt đầu trò chơi, chơi (điều khiển chim qua hàng ống), thua sẽ chuyển qua màn hình replay, ấn replay sẽ quay lại màn hình menu để chơi lại, exit để thoát game, tăng 1 điểm khi qua mỗi hàng ống và hiện thị điểm.
- Âm thanh xuất hiện khi chim va chạm vào ống và khi vượt qua được 1 ống.
- Video demo: 

Các kĩ thuật sử dụng trong Game:
- Thư viện SDL2, SDL2_image, SDL2_mixer.
- Sử dụng class, pointer, string, array.
- Thuật toán được sử dụng:
+ oop (tính kế thừa của class object cho 2 class background và player, tính đóng gói - tất cả các file đều được thể hiện dưới 1 class với mỗi chức năng riêng, ...). 
+ sử dụng hàm random() để tạo các đường ống khác nhau
+ xử lý va chạm để tính điểm và phát âm thanh
+ delay() + vòng lặp thay đổi tọa độ của chim(để chim rơi xuống hoặc bay lên), của 3 cái cột để tạo màn hình chạy cột và repawn cột liên tục

Bài học được rút ra mà em tâm đắc nhất:
Dự án bài tập lớn làm game lần này đã giúp em biết được cách tìm kiếm tài liệu, đọc tài liệu, tìm bug, cách sử dụng các thư viện SDL, cách tách file header để làm các dự án yêu cầu code dài và nhiều chức năng - giúp tăng tính logic, dễ dàng kiểm soát hơn, cách sử dụng makefile, ... Có những bug mà em phải tìm cả mấy ngày liền mới có thể fix. Dự án đã giúp em rèn luyện nhiều phẩm chất của 1 dev là kiên trì, cẩn thận, ham học hỏi.
Qua dự án lần này, em cảm ơn các thầy học kì này đã dạy cho em biết và hiểu ra rất nhiều kiến thức, riêng thầy thực hành Đỗ Minh Khá của nhóm em, em cảm thấy thầy rất đi sát học sinh, qua từng bài kiểm tra, từng giai đoạn, thầy quan tâm đến từng bạn, có khó khăn gì thầy đều giúp đỡ. Em cảm ơn các thầy và mong ở các môn học khác có thể gặp lại các thầy ạ.

Hướng phát triển :
+ Thêm high score
+ Sound collision