/**
 * @file main.cpp
 * @brief Chuong trinh chinh: Quan ly Vat tu va Du an Trien khai Mang (BTL KTLT)
 * @details Tich hop day du 10 Use Cases chia deu cho 5 Sinh vien
 */

#include <iostream>
#include <limits>
#include <cstdlib>

// ============================================================================
// KHAI BÁO REPOSITORY VA CÁC MENU THU?C 5 SINH VIÊN
// ============================================================================
#include "Repository.h"

// Entities
#include "include/MaterialCategory.h"
#include "include/Material.h"
#include "include/Supplier.h"
#include "include/Warehouse.h"
#include "include/ConstructionTeam.h"
#include "include/Project.h"
#include "include/ImportReceipt.h"
#include "include/ExportReceipt.h"
#include "include/AcceptanceReport.h"
#include "include/PaymentInvoice.h"

// Menus
#include "include/MaterialCategoryMenu.h"  // SV1 - UC01
#include "include/ImportReceiptMenu.h"      // SV1 - UC07
#include "include/MaterialMenu.h"            // SV2 - UC02
#include "include/ExportReceiptMenu.h"      // SV2 - UC08
#include "include/SupplierMenu.h"           // SV3 - UC03
#include "include/PaymentInvoiceMenu.h"      // SV3 - UC10
#include "include/WarehouseMenu.h"          // SV4 - UC04
#include "include/ProjectMenu.h"            // SV4 - UC06
#include "include/ConstructionTeamMenu.h"   // SV5 - UC05
#include "include/AcceptanceReportMenu.h"   // SV5 - UC09

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void showMainMenu() {
    cout << "========================================================================\n";
    cout << "   HE THONG QUAN LY VAT TU VA DU AN TRIEN KHAI MANG (BTL KTLT)          \n";
    cout << "========================================================================\n";
    cout << " [ SINH VIEN 1 ]\n";
    cout << "   1. UC01: Quan ly Danh muc vat tu (MaterialCategory)\n";
    cout << "   2. UC07: Quan ly Phieu nhap kho (ImportReceipt)\n\n";

    cout << " [ SINH VIEN 2 ]\n";
    cout << "   3. UC02: Quan ly Vat tu (Material)\n";
    cout << "   4. UC08: Quan ly Phieu xuat kho (ExportReceipt)\n\n";

    cout << " [ SINH VIEN 3 ]\n";
    cout << "   5. UC03: Quan ly Nha cung cap (Supplier)\n";
    cout << "   6. UC10: Quan ly Hoa don thanh toan (PaymentInvoice)\n\n";

    cout << " [ SINH VIEN 4 ]\n";
    cout << "   7. UC04: Quan ly Kho hang (Warehouse)\n";
    cout << "   8. UC06: Quan ly Du an trien khai (Project)\n\n";

    cout << " [ SINH VIEN 5 ]\n";
    cout << "   9. UC05: Quan ly Doi thi cong (ConstructionTeam)\n";
    cout << "  10. UC09: Quan ly Phieu nghiem thu (AcceptanceReport)\n";
    cout << "========================================================================\n";
    cout << "   0. Thoat chuong trinh\n";
    cout << "========================================================================\n";
    cout << "Nhap lua chon cua ban (0-10): ";
}

int getSafeChoice() {
    int choice;
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Lua chon khong hop le! Nhap lai (0-10): ";
    }
    return choice;
}

int main() {
    // ------------------------------------------------------------------------
    // 1. KHOI TAO DULIEU REPOSITORY CHO CÁC USE CASE
    // ------------------------------------------------------------------------
    Repository<MaterialCategory> categoryRepo("data/categories.txt");
    Repository<ImportReceipt>    importRepo("data/import_receipts.txt");
    Repository<Material>         materialRepo("data/materials.txt");
    Repository<ExportReceipt>    exportRepo("data/export_receipts.txt");
    Repository<Supplier>         supplierRepo("data/suppliers.txt");
    Repository<PaymentInvoice>   invoiceRepo("data/payment_invoices.txt");
    Repository<Warehouse>        warehouseRepo("data/warehouses.txt");
    Repository<Project>          projectRepo("data/projects.txt");
    Repository<ConstructionTeam> teamRepo("data/teams.txt");
    Repository<AcceptanceReport> acceptanceRepo("data/acceptance_reports.txt");

    // ------------------------------------------------------------------------
    // 2. KHOI TAO CÁC OBJECT MENU (Truyen Repository neu Menu yeu cau)
    // ------------------------------------------------------------------------
    // SV1
    MaterialCategoryMenu categoryMenu(categoryRepo);
    ImportReceiptMenu    importReceiptMenu(importRepo);

    // SV2
    MaterialMenu      materialMenu(materialRepo);
    ExportReceiptMenu exportReceiptMenu(exportRepo);

    // SV3
    SupplierMenu       supplierMenu(supplierRepo);
    PaymentInvoiceMenu invoiceMenu(invoiceRepo);

    // SV4
    WarehouseMenu warehouseMenu(warehouseRepo);
    ProjectMenu   projectMenu(projectRepo);

    // SV5
    ConstructionTeamMenu constructionTeamMenu(teamRepo);
  AcceptanceReportMenu acceptanceReportMenu(acceptanceRepo, teamRepo);

    // ------------------------------------------------------------------------
    // 3. VONG LAP DIEU KHIEN MENU CHINH
    // ------------------------------------------------------------------------
    int choice = -1;
    do {
        clearScreen();
        showMainMenu();
        choice = getSafeChoice();

        switch (choice) {
            case 1:
                clearScreen();
                categoryMenu.run();
                break;
            case 2:
                clearScreen();
                importReceiptMenu.run();
                break;
            case 3:
                clearScreen();
                materialMenu.run();
                break;
            case 4:
                clearScreen();
                exportReceiptMenu.run();
                break;
            case 5:
                clearScreen();
                supplierMenu.run();
                break;
            case 6:
                clearScreen();
                invoiceMenu.run();
                break;
            case 7:
                clearScreen();
                warehouseMenu.run();
                break;
            case 8:
                clearScreen();
                projectMenu.run();
                break;
            case 9:
                clearScreen();
                constructionTeamMenu.run();
                break;
            case 10:
                clearScreen();
                acceptanceReportMenu.run();
                break;
            case 0:
                cout << "\nCam on ban da su dung chuong trinh! Tam biet.\n";
                break;
            default:
                cout << "\nLua chon khong hop le! Nhan Enter de thu lai...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                break;
        }
    } while (choice != 0);

    return 0;
}