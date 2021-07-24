# TrungTamNgoaiNhu_CTDL
13/- Trung tâm ngoại ngữ
a. Cần tổ chức các danh sách sau: 
(i).- Cấp lớp: danh sách tuyến tính là 1 mảng con trỏ (Mã cấp lớp, Tên cấp lớp, 
Số tiết học, học phí, con trỏ): con trỏ sẽ trỏ đến các lớp thuộc cấp lớp tương 
ứng.
(ii).- Lớp: danh sách liên kết đơn (Mã lớp, trạng thái, Phòng học, contrỏ). Mỗi lớp
có 1 mã duy nhất; trạng thái của lớp bao gồm: 0: lớp chuẩn bị mở, 1: lớp đang 
học, 2: lớp đã hoàn tất. Thuộc tính contrỏ là con trỏ chỉ đến danh sách học 
viên của lớp (con trỏ chỉ đến cây nhị phân tìm kiếm HọcViên).
(iii).- HọcViên: cây nhị phân tìm kiếm (Mã học viên, là số nguyên ngẫu nhiên, được 
phát sinh tự động và không trùng nhau), Ho, Ten, Phai, con trỏ): con trỏ sẽ 
trỏ đến danh sách các điểm (nghe, nói, đọc, viết) của học viên. 
(iv).- Điểm: danh sách liên kết đơn (kỹ năng, điểm): kỹ năng =0 là nghe, =1 là nói, 
=2 là đọc, =3 là viết.
b. Chương trình có các chức năng sau: Hướng dẫn thực hiện đồ án môn học Cấu Trúc Dữ Liệu và Giải Thuật 11/11
- Về cấp lớp: thêm / xóa / hiệu chỉnh thông tin cấp lớp. 
- Về lớp: thêm / xóa / hiệu chỉnh thông tin lớp. 
- Về học viên: thêm / xóa / hiệu chỉnh thông tin học viên. 
- Về điểm: thêm / xóa / hiệu chỉnh thông tin về điểm của học viên. 
- In danh sách học viên theo lớp. 
- Tìm và In kết quả học tập của học viên dựa trên mã số của học viên. 
- Thống kê số lượng học viên theo từng cấp lớp. 
- In ra 10 lớp có số lượng học viên là đông nhất
