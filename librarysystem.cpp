#include <bits/stdc++.h>
using namespace std;
const int size=100000;
int add=0;
int added=0;
void print_menu(){
    cout<<"Librery menu : "<<"\n";
    cout<<"1) add_book"<<"\n";
    cout<<"2) search_books_by_prefix"<<"\n";
    cout<<"3) print_who_borrowed_book_by_name"<<"\n";
    cout<<"4) print_library_by_id"<<"\n";
    cout<<"5) print_library_by_name"<<"\n";
    cout<<"6) add_user "<<"\n";
    cout<<"7) user_borrow_book"<<"\n";
    cout<<"8) user_return_book"<<"\n";
    cout<<"9) print_users"<<"\n";
    cout<<"10) Exit"<<"\n";
}
struct user
{
    string name;
    int national_id;
    std::vector<int>borrowed_books_id;
};
user users[size];
struct book
{
    int id;
    string name ;
    int total_quantity;
    int total_borrowed=0;
};
book books[size];
// add books
void add_book(){
    cout<<"Enter book info: id & name & total_quantity: ";
    cin>>books[add].id>>books[add].name>>books[add].total_quantity;
    add++;
}
//search book by prefix
void book_by_prefix(){
    cout<<"Enter book name prefix : ";
    string prefix;
    cin>>prefix;
    for(int i=0 ; i<add ; i++){
        if(books[i].name.find(prefix)!=string::npos){
            cout<<books[i].name<<"\n";
        }
    }
}
//print who borrowed book by name
void borrowed_book_by_name(){
    cout<<"Enter book name : ";
    string name;
    cin>>name;
    int id=0;
    for(int i=0 ; i<add ; i++){
        if(books[i].name==name){
            id=books[i].id;
        }
    }
    for(int i=0 ; i<added ; i++){
        for(int j=0 ; j<users[i].borrowed_books_id.size() ; j++){
            if(users[i].borrowed_books_id[j]==id){
                cout<<users[i].name<<"\n";
                break;
            }
        }
    }
}
//print library by id
bool compare_id (book &a , book &b){
    return a.id<b.id;
}
void print_books(){
    for(int i=0 ; i<add ; i++){
        cout<<"id = "<<books[i].id<<" book_name = "<<books[i].name;
        cout<<" total_quantity = "<<books[i].total_quantity;
        cout<<" total_borrowed = "<<books[i].total_borrowed<<"\n";
    }
}
//print library by name
bool compare_name (book &a , book &b){
    return a.name<b.name;
}
//add user
void add_user(){
    cout<<"Enter user info: name & national_id : ";
    cin>>users[added].name>>users[added].national_id;
    added++;
}
//user borrow book
void borrow_book(){
    cout<<"Enter user name and book id : ";
    string name;
    int id;
    cin>>name>>id;
    for(int i=0 ; i<add ; i++){
        if(books[i].id == id){
            books[i].total_borrowed++;
            break;
        }
    }
    for(int i=0 ; i<added ; i++){
        if(users[i].name == name){
            users[i].borrowed_books_id.push_back(id);
        }
    }
}
//user return book
void return_book(){
    cout<<"Enter user name and book id : ";
    string name;
    int id;
    cin>>name>>id;
    for(int i=0 ; i<add ; i++){
        if(books[i].id == id){
            books[i].total_borrowed--;
            break;
        }
    }
    for(int i=0 ; i<added ; i++){
        if(users[i].name == name){
            for(int j=0 ; j<users[i].borrowed_books_id.size() ; j++){
                if(id==users[i].borrowed_books_id[j]){
                    users[i].borrowed_books_id[j]=0;
                }
            }
        }
    }
}
//print users
void print_users(){
    for(int i=0 ; i<added ; i++){
        cout<<"user "<<users[i].name<<" id "<<users[i].national_id;
        cout<<" borrowed_books_id: ";
        for(int j=0 ; j<users[i].borrowed_books_id.size() ; j++){
            if(users[i].borrowed_books_id[j]!=0)
            cout<<users[i].borrowed_books_id[j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    print_menu();
    int choice =-1;
    while(choice){
        cout<<"Enter your choice [1:10] \n";
        cin>>choice;
        if(choice==1){
            add_book();
        }
        else if(choice==3){
            borrowed_book_by_name();
        }
        else if(choice==2){
            book_by_prefix();
        }
        else if(choice==4){
            sort(books,books+add,compare_id);
            print_books();
        }
        else if(choice==5){
            sort(books,books+add,compare_name);
            print_books();
        }
        else if(choice==6){
            add_user();
        }
        else if(choice==7){
            borrow_book();
        }
        else if(choice==8){
            return_book();
        }
        else if(choice==9){
            print_users();
        }
        else{
            break;
        }
    }
    return 0;
}