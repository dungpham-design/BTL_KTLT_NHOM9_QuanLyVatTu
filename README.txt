================================================================================
          HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG - KHOA VIỄN THÔNG 1
                  BÁO CÁO HƯỚNG DẪN MÃ NGUỒN BÀI TẬP LỚN KTLT
       ĐỀ TÀI 8: QUẢN LÝ VẬT TƯ VÀ DỰ ÁN TRIỂN KHAI MẠNG (NHÓM 09)
================================================================================

[ 1. THÔNG TIN CHUNG ]
- Học phần: Kỹ thuật lập trình
- Giảng viên hướng dẫn: Nguyễn Hữu Cầm
- Nhóm thực hiện: NHÓM 09
- Tên đề tài: Quản lý Vật tư và Dự án Triển khai Mạng (Đề tài 8)
- Ngôn ngữ & Chuẩn C++: C++11 / C++17 (Console Application)

--------------------------------------------------------------------------------
[ 2. BẢNG PHÂN CÔNG THÀNH VIÊN & USE CASES (NHÓM 09) ]
--------------------------------------------------------------------------------
STT | Họ và tên          | Mã Sinh Viên | Use Case 1 (Danh Mục/Đơn Giản) | Use Case 2 (Nghiệp Vụ/Phức Tạp)
----------------------------------------------------------------------------------------------------
 1  | Trần Minh Quân     | B24DCVT306   | UC01: Quản lý Danh mục vật tư  | UC07: Quản lý Phiếu nhập kho
 2  | Võ Minh Quang      | B24DCVT308   | UC02: Quản lý Vật tư           | UC08: Quản lý Phiếu xuất kho
 3  | Mai Tất Đạt        | B24DCVT064   | UC03: Quản lý Nhà cung cấp     | UC10: Quản lý Hóa đơn thanh toán
 4  | Nguyễn Tiến Đoàn   | B24DCVT074   | UC04: Quản lý Kho              | UC06: Quản lý Dự án triển khai
 5  | Phạm Tiến Dũng     | B24DCVT099   | UC05: Quản lý Đội thi công     | UC09: Quản lý Phiếu nghiệm thu
----------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------
[ 3. CẤU TRÚC THƯ MỤC DỰ ÁN ]
--------------------------------------------------------------------------------
QuanLyVatTu_BTL_KTLT/
├── data/                        # Thư mục chứa 10 file dữ liệu văn bản (.txt)
│   ├── categories.txt           # [UC01] Dữ liệu Danh mục vật tư
│   ├── materials.txt            # [UC02] Dữ liệu Vật tư
│   ├── suppliers.txt            # [UC03] Dữ liệu Nhà cung cấp
│   ├── warehouses.txt           # [UC04] Dữ liệu Kho hàng
│   ├── teams.txt                # [UC05] Dữ liệu Đội thi công
│   ├── projects.txt             # [UC06] Dữ liệu Dự án triển khai
│   ├── import_receipts.txt      # [UC07] Dữ liệu Phiếu nhập kho
│   ├── export_receipts.txt      # [UC08] Dữ liệu Phiếu xuất kho
│   ├── acceptance_reports.txt   # [UC09] Dữ liệu Phiếu nghiệm thu
│   └── payment_invoices.txt     # [UC10] Dữ liệu Hóa đơn thanh toán
├── include/                     # Thư mục chứa toàn bộ các file Header (.h)
│   ├── MaterialCategory.h       # [SV1] Khai báo lớp Danh mục vật tư
│   ├── Material.h               # [SV2] Khai báo lớp Vật tư
│   ├── Supplier.h               # [SV3] Khai báo lớp Nhà cung cấp
│   ├── Warehouse.h              # [SV4] Khai báo lớp Kho hàng
│   ├── ConstructionTeam.h       # [SV5] Khai báo lớp Đội thi công
│   ├── Project.h                # [SV4] Khai báo lớp Dự án triển khai
│   ├── ImportReceipt.h          # [SV1] Khai báo lớp Phiếu nhập kho
│   ├── ExportReceipt.h          # [SV2] Khai báo lớp Phiếu xuất kho
│   ├── AcceptanceReport.h       # [SV5] Khai báo lớp Phiếu nghiệm thu
│   ├── PaymentInvoice.h         # [SV3] Khai báo lớp Hóa đơn thanh toán
│   └── *Menu.h                  # Thư mục khai báo 10 lớp Menu giao diện
│
├── src/                         # Thư mục chứa các file triển khai phương thức (.cpp)
│   ├── MaterialCategory.cpp, Material.cpp, Supplier.cpp, Warehouse.cpp...
│   ├── ConstructionTeam.cpp, Project.cpp, ImportReceipt.cpp, ExportReceipt.cpp...
│   ├── AcceptanceReport.cpp, PaymentInvoice.cpp
│   └── *Menu.cpp                # File triển khai 10 Menu điều khiển
│
│
├──Entity.h                 # Lớp cơ sở trừu tượng (Abstract Base Class)
├──Repository.h             # Lớp khuôn mẫu (Class Template) quản lý CRUD & tệp
├──InputHelper.h            # Tiện ích nhập dữ liệu an toàn & dọn luồng cin
├── main.cpp                # Điểm khởi chạy chính (Menu điều khiển UC01 -> UC10)
├── Test.dev                # File cấu hình Project Embarcadero Dev-C++
└── README.txt              # File tài liệu hướng dẫn sử dụng & nộp bài
 

--------------------------------------------------------------------------------
[ 4. HƯỚNG DẪN BIÊN DỊCH VÀ CHẠY CHƯƠNG TRÌNH ]
--------------------------------------------------------------------------------

CÁCH 1: BIÊN DỊCH BẰNG EMBARCADERO DEV-C++ (Khuyên dùng cho buổi bảo vệ)
  Bước 1: Mở phần mềm Dev-C++ -> File -> Open Project or File... -> Chọn file `Test.dev`.
  Bước 2: Cấu hình đường dẫn include (nếu tạo project mới):
          - Bấm `Alt + P` (Project Options) -> Tab `Directories` -> Tab `Include Directories`.
          - Nhấn nút `...` chọn đến thư mục `include/` của dự án -> Nhấn `Add` -> Nhấn `OK`.
  Bước 3: Nhấp chuột phải vào tên Project ở cây bên trái -> Chọn `Add to Project...` (Ctrl + F7)
          để đảm bảo đã thêm đầy đủ tất cả các file .cpp trong `src/` và các file .h trong `include/`.
  Bước 4: Nhấp chọn tab `main.cpp`.
  Bước 5: Nhấn phím `Ctrl + F11` (Rebuild All) để làm sạch file tạm và biên dịch lại toàn bộ.
  Bước 6: Nhấn phím `F11` (Compile & Run) để khởi chạy chương trình.

CÁCH 2: BIÊN DỊCH BẰNG TERMINAL / COMMAND LINE (GCC / VS CODE)
  Bước 1: Mở Git Bash / Command Prompt / Terminal tại thư mục gốc của dự án.
  Bước 2: Chạy câu lệnh g++ biên dịch tất cả file nguồn:
          g++ -std=c++11 main.cpp src/*.cpp -Iinclude -o main.exe
  Bước 3: Thực thi chương trình:
          ./main.exe

--------------------------------------------------------------------------------
[ 5. ĐỊNH DẠNG DỮ LIỆU TỆP VĂN BẢN (data/*.txt) ]
--------------------------------------------------------------------------------
Mỗi dòng đại diện cho 1 bản ghi thực thể, các trường phân cách bởi ký tự `|`:

1. categories.txt           : maDanhMuc|tenDanhMuc|moTa
2. materials.txt            : maVatTu|tenVatTu|donViTinh|donGia|soLuongTon|maDanhMuc
3. suppliers.txt            : maNCC|tenNCC|diaChi|sdt|email
4. warehouses.txt           : maKho|tenKho|diaChiKho|nguoiQuanLy|sucChua
5. teams.txt                : maDoi|tenDoi|doiTruong|sdtDoiTruong|soLuongThanhVien
6. projects.txt             : maDuAn|tenDuAn|diaDiem|ngayBatDau|ngayKetThuc|tongKinhPhi
7. import_receipts.txt     : maPhieuNhap|ngayNhap|maNhaCungCap|maNhanVien|tongTien
8. export_receipts.txt     : maPhieuXuat|ngayXuat|maDuAn|maKho|maNhanVien|tongTien
9. acceptance_reports.txt  : maPhieuNT|maDuAn|maDoi|ngayNghiemThu|danhGia
10. payment_invoices.txt    : maHoaDon|maNhaCungCap|soTienThanhToan|ngayThanhToan|trangThai

================================================================================