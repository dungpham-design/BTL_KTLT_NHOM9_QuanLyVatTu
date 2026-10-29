/**
 * @file main.cpp
 * @brief Chuong trinh chinh: Quan ly Vat tu va Du an Trien khai Mang (BTL KTLT)
 * @details Tich hop day du 10 Use Cases hien thi theo thu tu UC01 -> UC10
 */

#include <iostream>
#include <limits>
#include <cstdlib>

// ============================================================================
// KHAI BÁO REPOSITORY VA CÁC MENU THUỘC 5 SINH VIÊN
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
#include "include/MaterialMenu.h"            // SV2 - UC02
#include "include/SupplierMenu.h"           // SV3 - UC03
#include "include/WarehouseMenu.h"          // SV4 - UC04
#include "include/ConstructionTeamMenu.h"   // SV5 - UC05
#include "include/ProjectMenu.h"            // SV4 - UC06
#include "include/ImportReceiptMenu.h"      // SV1 - UC07
#include "include/ExportReceiptMenu.h"      // SV2 - UC08
#include "include/AcceptanceReportMenu.h"   // SV5 - UC09
#include "include/PaymentInvoiceMenu.h"      // SV3 - UC10

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
    cout << "         HE THONG QUAN LY VAT TU VA DU AN TRIEN KHAI MANG              \n";
    cout << "========================================================================\n";
    cout << " 1. Quan ly danh muc vat tu\n";
    cout << " 2. Quan ly vat tu\n";
    cout << " 3. Quan ly nha cung cap\n";
    cout << " 4. Quan ly kho hang\n";
    cout << " 5. Quan ly doi thi cong\n";
    cout << " 6. Quan ly du an trien khai\n";
    cout << " 7. Quan ly phieu nhap kho\n";
    cout << " 8. Quan ly phieu xuat kho\n";
    cout << " 9. Quan ly phieu nghiem thu\n";
    cout << "10. Quan ly hoa don thanh toan\n";
    cout << " 0. Thoat chuong trinh\n";
    cout << "------------------------------------------------------------------------\n";
    cout << "Chon: ";
}

int getSafeChoice() {
    int choice;
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Lua chon khong hop le! Nhap lai: ";
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
    // 2. KHOI TAO CÁC OBJECT MENU
    // ------------------------------------------------------------------------
    MaterialCategoryMenu categoryMenu(categoryRepo);
    MaterialMenu         materialMenu(materialRepo);
    SupplierMenu         supplierMenu(supplierRepo);
    WarehouseMenu        warehouseMenu(warehouseRepo);
    ConstructionTeamMenu constructionTeamMenu(teamRepo);
    ProjectMenu          projectMenu(projectRepo);
    ImportReceiptMenu    importReceiptMenu(importRepo);
    ExportReceiptMenu    exportReceiptMenu(exportRepo);
    AcceptanceReportMenu acceptanceReportMenu(acceptanceRepo, teamRepo);
    PaymentInvoiceMenu   invoiceMenu(invoiceRepo);

    // ------------------------------------------------------------------------
    // 3. VONG LAP DIEU KHIEN MENU CHINH (THEO THU TU UC01 -> UC10)
    // ------------------------------------------------------------------------
    int choice = -1;
    do {
        clearScreen();
        showMainMenu();
        choice = getSafeChoice();

        switch (choice) {
            case 1:
                clearScreen();
                categoryMenu.run(); // UC01
                break;
            case 2:
                clearScreen();
                materialMenu.run(); // UC02
                break;
            case 3:
                clearScreen();
                supplierMenu.run(); // UC03
                break;
            case 4:
                clearScreen();
                warehouseMenu.run(); // UC04
                break;
            case 5:
                clearScreen();
                constructionTeamMenu.run(); // UC05
                break;
            case 6:
                clearScreen();
                projectMenu.run(); // UC06
                break;
            case 7:
                clearScreen();
                importReceiptMenu.run(); // UC07
                break;
            case 8:
                clearScreen();
                exportReceiptMenu.run(); // UC08
                break;
            case 9:
                clearScreen();
                acceptanceReportMenu.run(); // UC09
                break;
            case 10:
                clearScreen();
                invoiceMenu.run(); // UC10
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