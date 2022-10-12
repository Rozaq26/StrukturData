#include<iostream>
using namespace std;
#define MAX 8

struct Antrian {
    int data[MAX];
    int head;
    int tail;
};

Antrian antre;
void create();
bool isEmpty();
bool isFull();
void enqueue(int);
int dequeue();
void tampil();
void menu();

int main(){

    create();
    menu();

    return 0;
}

void create(){
    antre.head = antre.tail =-1;
}

bool isEmpty(){
    if(antre.tail == -1){
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(){
    if(antre.tail == MAX - 1){
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int data){
    if(isEmpty()){
        antre.head = antre.tail = 0;
        antre.data[antre.tail] = data;
    }
    else
    {
        antre.tail++;
        antre.data[antre.tail] = data;
    }
    cout<<data<<" dimasukkan ke antrian";
}

int dequeue(){
    int i;
    int e = antre.data[antre.head];
    for(i = antre.head;i < antre.tail;i++){
        antre.data[i] = antre.data[i+1];
    }
    antre.tail--;
    return e;
}

void tampil(){
    if(isEmpty()){
        cout<<"data kosong";
    }
    else{

        for(int i = antre.head;i <= antre.tail;i++){
            cout << antre.data[i] << " ";
        }
    }
}

void menu()
{

    int opsi, angka;


    do{

        cout << "MENU" << endl;
        cout << "1. Masukan data" << endl;
        cout << "2. Menyelesaikan data" << endl;
        cout << "3. Menampilkan data" << endl;
        cout << "4. Mengecheck data" << endl;
        cout << "5. Keluar" << endl;
        cout << endl;
        cout << "Pilih menu : ";cin>>opsi;


        switch (opsi)
        {
        case 1:
            cout << "Isi data ";cin>>angka;
            enqueue(angka);
            cout << endl;
            break;
        case 2:
            cout << "data " << dequeue() << " selesai" << endl;
            cout << endl;
            break;
        case 3:
            if (isEmpty()!=true)
            {
                cout << "data yang masih tersedia ";tampil();
                cout << endl;
            }
            else{
                cout << "Masih kosong" << endl;
                cout << endl;
            }

            break;
        case 4:
            if (isFull())
            {
                cout << "data telah penuh! " << endl;
                cout << endl;
            }
            else if(isEmpty())
            {
                cout << "data masih kosong! " << endl;
                cout << endl;
            }
            else{
                cout << "Ada isinya tapi tidak penuh" << endl;
                cout << endl;
            }
            break;
        case 5:
            cout << endl;
            break;
        default:
            cout << "Input tidak valid" << endl;
            cout << endl;


        }



    }while(opsi!=5);


}
