#include <iostream>
#define MAX_STACK_SIZE 10

using namespace std;

struct Element{
	int data;
	int top;
	Element *next;
};

class myStack{
	private:
	Element tumpuk;
	Element *head = NULL;
	
	public:
	void setawal(){
		tumpuk.top = -1;
	}
	
	bool isEmpty(){
        if(tumpuk.top == -1){
			return 1;
		}else{
			return 0;
		}
    }
    
	bool isFull(){
        if(tumpuk.top == MAX_STACK_SIZE-1){
			return 1;
		}else{
			return 0;
		}
    }
    
    void push(int input){
		if(isFull()){
			cout << "Tumpukan Penuh";
		}else{
			Element *tmp = new Element;
			tmp->data = input;
			tmp->next=NULL;
			if(isEmpty())
			{
				head=tmp;
				head->next=NULL;
			}else{
				tmp->next=head;
				head=tmp;
			}
			cout<<"Push berhasil \n";
			tumpuk.top++;
		}
	}
	
	void pop(){
		if (isEmpty()){
			cout<<"\nTumpukan Kosong\n";
		}else{
			Element *tmp = new Element;
			tmp = head;
			head = head->next;
			delete tmp;
			cout<<"\nPop Berhasil\n";
			tumpuk.top--;
		}	
	}
		
	void getTop(){
		if(isEmpty()){
			cout << "Tumpukan Kosong";
		}else{
			cout << head->data;
		}
	}
	
	void print(){
		if(isEmpty()){
			cout << "Tumpukan Kosong" << endl;
		}else{
			cout << "Isi Tumpukan : " << endl;
			Element *tmp = new Element;
			tmp = head;
			while(tmp!=NULL)
			{
				cout<<tmp->data<<"  ";
				tmp=tmp->next;
			}
		}
	}
};

int nama_menu();

int main(){
	myStack obj;
	int menu,val;
	obj.setawal();
	char lagi = 'y';
	do{
		menu = nama_menu();
		switch(menu){
			case 1:
					cout << "Masukan Angka yang mau dipush: ";cin>>val;
					obj.push(val);
					break;
			case 2:
					if(obj.isEmpty()){
						cout << "Tumpukan Kosong" << endl;
					}else{
						cout << "Angka ";obj.getTop(); cout << " akan dihapus";
						cin.ignore();
						cin.get();
						obj.pop();
					}
					break;
			case 3:
					if(obj.isEmpty()){
						cout << "Tumpukan Kosong" << endl;
					}else{
						cout << "Elemen Paling Atas adalah ";obj.getTop();
					}
					break;
			case 4:
					obj.print();
					break;
			case 5:
					exit(0);
			default:
					cout <<"\t\nPilihan tidak ada";
					cin.get();
					break;
		}cout << endl << "Kembali Ke Menu ? (y/n) ";cin>>lagi;
		system("clear");
	}while(lagi=='y');
		cin.get();
		return 0;
}

int nama_menu(){
	cout<<"\t\t  https://github.com/BrondoL/Stack_LIFO"<<endl;
	cout<<"\t||=====================================================||"<<endl;
	cout<<"\t||                                                     ||"<<endl;
	cout<<"\t||      DEVELOPED BY BrondoL aka Aulia Ahmad Nabil     ||"<<endl;
	cout<<"\t||                                                     ||"<<endl;
	cout<<"\t||=====================================================||"<<endl<<endl;
	cout<<"\t\t     STACK WITH LINKED LIST CONCEPT"<<endl<<endl;
	int menu;
	cout << "MENU : "<<endl<<endl;
	cout << "1. Push"<<endl;
	cout << "2. Pop"<<endl;
	cout << "3. Get Top"<<endl;
	cout << "4. Print Stack List"<<endl;
	cout << "5. Exit..."<<endl<<endl;
	cout << "Pilihan : "; cin >> menu;
	system("clear");
	return menu;
}
