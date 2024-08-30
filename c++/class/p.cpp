#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Product {
    int pno;
    char name[50];
    float price, dis;

public:
    void create_product() {
        cout << "\nPlease Enter The Product No. of The Product: ";
        cin >> pno;
        cin.ignore();
        cout << "\nPlease Enter The Name of The Product: ";
        cin.getline(name, 50);
        cout << "\nPlease Enter The Price of The Product: ";
        cin >> price;
        cout << "\nPlease Enter The Discount (%): ";
        cin >> dis;
    }

    void show_product() const {
        cout << "\nThe Product No. of The Product: " << pno;
        cout << "\nThe Name of The Product: " << name;
        cout << "\nThe Price of The Product: " << price;
        cout << "\nDiscount: " << dis << "%";
    }

    int retpno() const { return pno; }
    float retprice() const { return price; }
    const char* retname() const { return name; }
    int retdis() const { return dis; }
};

fstream fp;
Product pr;

void write_product() {
    fp.open("Shop.dat", ios::out | ios::app | ios::binary);
    pr.create_product();
    fp.write(reinterpret_cast<char*>(&pr), sizeof(Product));
    fp.close();
    cout << "\n\nThe Product Has Been Created ";
    cin.get();
}

void display_all() {
    cout << "\n\n\n\t\tDISPLAY ALL RECORDS!!!\n\n";
    fp.open("Shop.dat", ios::in | ios::binary);
    while (fp.read(reinterpret_cast<char*>(&pr), sizeof(Product))) {
        pr.show_product();
        cout << "\n\n====================================\n";
    }
    fp.close();
    cin.get();
}

void display_sp(int n) {
    int flag = 0;
    fp.open("Shop.dat", ios::in | ios::binary);
    while (fp.read(reinterpret_cast<char*>(&pr), sizeof(Product))) {
        if (pr.retpno() == n) {
            pr.show_product();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
        cout << "\n\nRecord Not Found";
    cin.get();
}

void modify_product() {
    int no, found = 0;
    cout << "\n\n\tTo Modify ";
    cout << "\n\n\tPlease Enter The Product No. of The Product: ";
    cin >> no;
    fp.open("Shop.dat", ios::in | ios::out | ios::binary);
    while (fp.read(reinterpret_cast<char*>(&pr), sizeof(Product)) && found == 0) {
        if (pr.retpno() == no) {
            pr.show_product();
            cout << "\nPlease Enter The New Details of Product\n";
            pr.create_product();
            int pos = static_cast<int>(fp.tellg()) - sizeof(Product);
            fp.seekp(pos, ios::beg);
            fp.write(reinterpret_cast<char*>(&pr), sizeof(Product));
            cout << "\n\n\t Record Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
    cin.get();
}

void delete_product() {
    int no;
    cout << "\n\n\n\tDelete Record";
    cout << "\n\nPlease Enter The Product No. of The Product You Want To Delete: ";
    cin >> no;
    fp.open("Shop.dat", ios::in | ios::out | ios::binary);
    fstream fp2;
    fp2.open("Temp.dat", ios::out | ios::binary);
    while (fp.read(reinterpret_cast<char*>(&pr), sizeof(Product))) {
        if (pr.retpno() != no) {
            fp2.write(reinterpret_cast<char*>(&pr), sizeof(Product));
        }
    }
    fp2.close();
    fp.close();
    remove("Shop.dat");
    rename("Temp.dat", "Shop.dat");
    cout << "\n\n\tRecord Deleted ..";
    cin.get();
}

void menu() {
    fp.open("Shop.dat", ios::in | ios::binary);
    if (!fp) {
        cout << "ERROR!!! FILE COULD NOT BE OPENED\n\n\n Go To Admin Menu to create File";
        cout << "\n\n\n Program is closing ....";
        cin.get();
        exit(0);
    }

    cout << "\n\n\t\tProduct MENU\n\n";
    cout << "====================================================\n";
    cout << "P.NO.\t\tNAME\t\tPRICE\n";
    cout << "====================================================\n";

    while (fp.read(reinterpret_cast<char*>(&pr), sizeof(Product))) {
        cout << pr.retpno() << "\t\t" << pr.retname() << "\t\t" << pr.retprice() << endl;
    }
    fp.close();
}

void place_order() {
    int order_arr[50], quan[50], c = 0;
    float amt, damt, total = 0;
    char ch = 'Y';
    menu();
    cout << "\n============================";
    cout << "\n PLACE YOUR ORDER";
    cout << "\n============================\n";
    do {
        cout << "\n\nEnter The Product No. Of The Product: ";
        cin >> order_arr[c];
        cout << "\nQuantity in number: ";
        cin >> quan[c];
        c++;
        cout << "\nDo You Want To Order Another Product? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << "\n\nThank You For Placing The Order";
    cin.get();
    cout << "\n\n********************************INVOICE************************\n";
    cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";

    for (int x = 0; x < c; x++) {
        fp.open("Shop.dat", ios::in | ios::binary);
        while (fp.read(reinterpret_cast<char*>(&pr), sizeof(Product))) {
            if (pr.retpno() == order_arr[x]) {
                amt = pr.retprice() * quan[x];
                damt = amt - (amt * pr.retdis() / 100);
                cout << "\n" << order_arr[x] << "\t" << pr.retname() << "\t" << quan[x] << "\t\t" << pr.retprice() << "\t" << amt << "\t\t" << damt;
                total += damt;
            }
        }
        fp.close();
    }
    cout << "\n\n\t\t\t\t\tTOTAL = " << total;
    cin.get();
}

void intro() {
    cout << "\n\n\n\tSUPER MARKET";
    cout << "\n\n\tBILLING";
    cout << "\n\n\tPROJECT";
    cout << "\n\nMADE BY : ANUJ KUMAR";
    cout << "\n\nSCHOOL : RYAN INTERNATIONAL SCHOOL";
    cin.get();
}

void admin_menu() {
    char ch2;
    cout << "\n\n\n\tADMIN MENU";
    cout << "\n\n\t1.CREATE PRODUCT";
    cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
    cout << "\n\n\t3.QUERY";
    cout << "\n\n\t4.MODIFY PRODUCT";
    cout << "\n\n\t5.DELETE PRODUCT";
    cout << "\n\n\t6.VIEW PRODUCT MENU";
    cout << "\n\n\t7.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-7): ";
    cin >> ch2;
    switch (ch2) {
        case '1': write_product(); break;
        case '2': display_all(); break;
        case '3': int num; cout << "\n\n\tPlease Enter The Product No.: "; cin >> num; display_sp(num); break;
        case '4': modify_product(); break;
        case '5': delete_product(); break;
        case '6': menu(); cin.get(); break;
        case '7': break;
        default: cout << "\a"; admin_menu();
    }
}

int main() {
    char ch;
    intro();
    do {
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. CUSTOMER";
        cout << "\n\n\t02. ADMINISTRATOR";
        cout << "\n\n\t03. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-3): ";
        cin >> ch;
        switch (ch) {
            case '1': place_order(); cin.get(); break;
            case '2': admin_menu(); break;
            case '3': exit(0);
            default: cout << "\a";
        }
    } while (ch != '3');
    return 0;
}
